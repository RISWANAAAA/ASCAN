#include "calformula.h"
#include<cmath>
#include<QDebug>
CalFormula::CalFormula()
{

}

int CalFormula::diff(double emm)
{
    if ((emm >= -0.25) & (emm < 0))
        return 0.0;
     else if ((emm >= -0.5) & (emm < -0.25))
        return -0.5;
     else if ((emm >= -0.75) & (emm < -0.5))
        return -0.5;
     else if ((emm >= -1.0) & (emm < -0.75))
        return -1.0;
     else if ((emm <= 0.25) & (emm > 0.0))
       return 0.0;
     else if ((emm > 0.25) & (emm <= 0.5))
       return 0.5;
     else if ((emm > 0.5) & (emm <= 0.75))
       return 0.5;
     else if ((emm > 0.75) & (emm <= 1.0))
       return 1.0;
     else
        return 0.0;
}

int CalFormula::calculateacd(double AL, double AConst, double KD)
{
    double m, g, kk,ACD;
     double ACD1,ACD2,ACD3;
      if (AL <= 23.0){
         m = 1.0;
         g = 28.0;
      }
      else{
         m = -1.0;
         g = 23.5;
      }


      ACD =(AConst*0.5663-65.6+3.595)/0.9704;



      if (ACD > 6.5)
          ACD = 6.5;
      else if (ACD < 3.0)
         ACD = 3.0;

      kk = KD / 57.2957;
      ACD1 =     0.3 * (AL - 23.5);
      ACD2 = tan(kk) * tan(kk);
      ACD3 = 0.1 * m * (23.5- AL) * (23.5 - AL) * tan((0.1 * (g - AL) * (g - AL)) / 57.2957);

      //printf("\r\nACD1=%5.2f ACD2=%5.2f ACD3=%5.2f",ACD1,ACD2,ACD3);

      return (ACD + ACD1 + ACD2 + ACD3 - 0.9917);






}

void CalFormula::SRKIICalc(double AL, double AConst, double K, double Rx,QLineEdit *lineEditsPower[], QLineEdit *lineEditsError[], QLineEdit *emmetropiaEdit) {
    double i;
    double Emmetropia, Emmetropia_Rounded, Emmetropia_New, CR, REFR1;
    double Diff_In_Emmetropia, Diff_Add;
    double REFR;
    int Loop = 0;

    // Adjust AConst based on AL
    if (AL < 20.0)
        AConst = AConst + 3;
    else if ((AL >= 20.0) && (AL < 21.0))
        AConst = AConst + 2;
    else if ((AL >= 21.0) && (AL < 22.0))
        AConst = AConst + 1;
    else if ((AL >= 22.0) && (AL < 24.5))
        AConst = AConst;
    else if (AL >= 24.5)
        AConst = AConst - 0.5;

    // Calculate Emmetropia
    Emmetropia = AConst - (0.9 * K) - (2.5 * AL);
    SRKIIValues.PEMM = Emmetropia;

    // Update the emmetropia QLineEdit

        emmetropiaEdit->setText(QString::number(Emmetropia, 'f', 2));  // Set calculated Emmetropia value


    Emmetropia_Rounded = floor(Emmetropia);
    Diff_In_Emmetropia = Emmetropia - Emmetropia_Rounded;

    // Calculate CR
    if (Emmetropia < 14.0)
        CR = 1.0;
    else
        CR = 1.25;

    // Calculate Diff_Add using a helper function `diff`
    Diff_Add = diff(Diff_In_Emmetropia);

    Emmetropia_New = Emmetropia_Rounded + Diff_Add;
    Diff_In_Emmetropia = Emmetropia - Emmetropia_New;
    REFR1 = Diff_In_Emmetropia / CR;

    // Loop to populate power and error values in line edits
    for (i = Emmetropia_New - 1.0; i <= Emmetropia_New + 1.0; i += 0.5) {
        REFR = (REFR1 + (Emmetropia_New - i) / CR);
        SRKIIValues.PORx[Loop] = REFR;
        SRKIIValues.IOLPower[Loop] = i;

        // Debugging the loop values
        qDebug() << "Inside loop, i (Power):" << i << "REFR (Error):" << REFR;

        // Ensure no out-of-bound access and set values in the line edits for Power and Error
        if (Loop < 5) {
            lineEditsPower[Loop]->setText(QString::number(i, 'f', 2));  // Update Power value
            lineEditsError[Loop]->setText(QString::number(REFR, 'f', 2));  // Update Error value

            // Debugging to check values in line edits
            qDebug() << "lineEditsPower[" << Loop << "]:" << lineEditsPower[Loop]->text();
            qDebug() << "lineEditsError[" << Loop << "]:" << lineEditsError[Loop]->text();
        }
        Loop++;  // Increment the loop counter
    }
}

void CalFormula::HolladayCalc(double AL, double SF, double K, double Rx,QLineEdit *lineEditIOLPower[], QLineEdit *lineEditRefError[], QLineEdit *emmetropiaEdit)
{
    int Loop;
    double N1;
    double N2;
    double RT;
    double R;
    double Rag;
    double VD;
    double Alm;
    double AQ;
    double BQ;
    double CQ;
    double ER;
    double LP;
  //  double SF;
    double AD;
    double AG;
    double IOL_1;
    double IOL_2;
    double DR=0.0;
    double P_Emmetropia;
    double ERROR_1;
    double ERROR_2;
    double Rx_ERROR;
    double Emmetropia_Rounded;
    double Diff_In_Emmetropia;
    double Diff_Add;
    double Emmetropia_New;


    //printf("\r\nHolladay\n");
    N1 = 1.333;
    N2 = 1.336;
    RT = 0.200;
    R = 337.5/K;
    VD = 12.0;
    ER = 0.0;
  //  SF = AConst * 0.5663 - 65.60;

    //printf("\r\nSF = %5.2f",SF);
    LP=0.0;
    Alm = AL + RT;
    if (R >= 7)
      Rag = R;
    else if (R < 7)
      Rag = 7;

    AG = 12.5 * AL/23.45;
    if (AG > 13.5)
       AG = 13.5;
    AD = 0.56+Rag - sqrt(Rag*Rag-(AG*AG/4));

    IOL_1 =1000*N2*(N2*R-(N1-1)*Alm-0.001*DR*(VD*(N2*R-(N1-1)*Alm)+Alm*R));
    IOL_2 = (Alm-AD-SF)*(N2*R-(N1-1)*(AD+SF)-0.001*DR*(VD*(N2*R-(N1-1)*(AD+SF))+(AD+SF)*R));

    P_Emmetropia = IOL_1/IOL_2;
    //printf("\r\n%5.2f %5.2f",AL,P_Emmetropia);
    HolladayValues.PEMM = P_Emmetropia;
    emmetropiaEdit->setText(QString::number(P_Emmetropia, 'f', 2));  // Set calculated Emmetropia value

      DR=Rx;
    IOL_1 =1000*N2*(N2*R-(N1-1)*Alm-0.001*DR*(VD*(N2*R-(N1-1)*Alm)+Alm*R));
    IOL_2 = (Alm-AD-SF)*(N2*R-(N1-1)*(AD+SF)-0.001*DR*(VD*(N2*R-(N1-1)*(AD+SF))+(AD+SF)*R));

    P_Emmetropia = IOL_1/IOL_2;

    LP = P_Emmetropia;

      Emmetropia_Rounded = floor(P_Emmetropia);
      Diff_In_Emmetropia = P_Emmetropia - Emmetropia_Rounded;
      Diff_Add = diff(Diff_In_Emmetropia);
      Emmetropia_New = Emmetropia_Rounded + Diff_Add;
      Loop=0;
      for (LP = Emmetropia_New - 1.0; LP <= Emmetropia_New + 1.0; LP = LP + 0.5)
       {
        HolladayValues.IOLPower[Loop] = LP;
        ERROR_1 = 1000*N2*(N2*R-(N1-1)*Alm)-LP*(Alm-AD-SF)*(N2*R-(N1-1)*(AD+SF));
        ERROR_2 = N2*(VD*(N2*R-(N1-1)*Alm)+Alm*R)-0.001*LP*(Alm-AD-SF)*(VD*(N2*R-(N1-1)*(AD+SF))+(AD+SF)*R);
        Rx_ERROR = ERROR_1/ERROR_2;
        HolladayValues.PORx[Loop] = Rx_ERROR;
    //  printf("\r\n%5.2f,%5.2f",HolladayValues->IOLPower[Loop],HolladayValues->PORx[Loop]);
        lineEditIOLPower[Loop]->setText(QString::number(LP, 'f', 2));
          lineEditRefError[Loop]->setText(QString::number(Rx_ERROR, 'f', 2));

        Loop++;
       }

}

void CalFormula::SRKTCalc(double AL, double AConst, double K, double Rx, QLineEdit *lineEditsSRKTPower[], QLineEdit *lineEditsSRKTError[], QLineEdit *emmetropiaSRKTEdit)
{
    double ALCORR,ACCORR,C0,C1,C3,C4,C5,C6,C8,C9,CRWDES,SQRTR1;
    double Emmetropia,Emmetropia_Rounded,Emmetropia_New,Diff_In_Emmetropia,Diff_Add;
    double REFR1,i;
    double IOLPower;
    double REFR;
    double ACD;

    int Loop=0;

    //printf("\r\nSRKT\n");
    ACD = 0.62467 * AConst - 68.747;
    //ACD = 0.58352 * AConst - 63.896;

    if (AL > 24.2)
      ALCORR = (1.716 - 0.0237 * AL) * AL - 3.446;
    else
      ALCORR = AL;

    C0 = K;
    C1 = 337.5 / C0;
    CRWDES = 0.58412 * ALCORR + 0.098 * C0 - 5.40948;
    SQRTR1 = C1 * C1 - ((CRWDES * CRWDES) / 4.0);
    if (SQRTR1 < 0)
      SQRTR1 = 0.0;

    ACCORR = C1 - sqrt(SQRTR1) + ACD - 3.3357;


    C3 = AL * 0.97971 + 0.65696;
    C4 = C3 - ACCORR;
    C5 = 1.336 * C1 - 0.333 * ACCORR;
    C6 = 1.336 * C1 - 0.333 * C3;
    C8 = 12.0 * C6 + C3 * C1;
    C9 = 12.0 * C5 + ACCORR * C1;

    REFR1 = Rx;

    Emmetropia = (1336.0 * (C6 - 0.001 * REFR1 * C8)) / (C4 * (C5 - 0.001 * REFR1 * C9));
    emmetropiaSRKTEdit->setText(QString::number(Emmetropia, 'f', 2));  // Set calculated Emmetropia value

    Emmetropia_Rounded = floor(Emmetropia);
    SRKTValues.PEMM = (1336.0 * (C6 - 0.001 * 0 * C8)) / (C4 * (C5 - 0.001 * REFR1 * C9));

    Diff_In_Emmetropia = Emmetropia - Emmetropia_Rounded;
    Diff_Add = diff(Diff_In_Emmetropia);

     Emmetropia_New = Emmetropia_Rounded + Diff_Add;
     for (i = Emmetropia_New - 1.0; i <= Emmetropia_New + 1.0; i = i + 0.5)
      {
       SRKTValues.IOLPower[Loop] = i;
       REFR = (1336.0 * C6 - i * C4 * C5) / (1.336 * C8 - 0.001 * i * C4 * C9);
       SRKTValues.PORx[Loop] = REFR;
       SRKTValues.IOLPower[Loop] = i;
       lineEditsSRKTPower[Loop]->setText(QString::number(i, 'f', 2));
       lineEditsSRKTError[Loop]->setText(QString::number(REFR, 'f', 2));
       Loop++;
     }
}

int CalFormula::HofferCalc(double A, double ACD, double K, double Rx, QLineEdit *lineEditsHofferPower[], QLineEdit *lineEditsHofferError[], QLineEdit *emmetropiaHofferEdit)
{
    double C,R1,P;
     double P_Emmetropia,P_Emmetropia_New,DIE,REFR;
     int Loop;

    // printf("\r\nHoffer-Q\n");
     if (K <= 0)
        return -1;
     if (A <= 0)
        return -1;

     C = calculateacd(A,ACD, K);

   //  printf("\r\nACD=%7.4f",C);
     P_Emmetropia = (1336.0 / (A          - C- 0.05))-(1.336/ ((1.336 / (K + Rx)) - ((C  + 0.05) / 1000.0)));
             //p0 = (1336.0/  (alf[defeye]-acd-0.05))-(1.336/ ((1.336 / (k + 0)) - ((acd+ 0.05) / 1000.0)));

     HOFFERValues.PEMM = (1336.0 / (A          - C- 0.05))-(1.336/ ((1.336 / (K + 0)) - ((C  + 0.05) / 1000.0)));
     //printf("\r\nP_Emmetropia = %5.2f AConst=%5.2f AL=%5.2f K=%5.2f",P_Emmetropia, AConst,A,K);
     P_Emmetropia_New = floor(P_Emmetropia);
     DIE = P_Emmetropia - P_Emmetropia_New;
     P_Emmetropia_New = P_Emmetropia_New + diff(DIE);

     Loop = 0;
     for (P = P_Emmetropia_New - 1.0; P<=P_Emmetropia_New + 1.0; P= P + 0.5){
       R1 = (1.336 / (1.336 / (1336 / (A - C - 0.05) - P) + (C + 0.05) / 1000.0)) - K;
       REFR = R1 / (1 + (0.012 * R1));
       HOFFERValues.PORx[Loop] = REFR;
      HOFFERValues.IOLPower[Loop] = P;
      lineEditsHofferPower[Loop]->setText(QString::number(P, 'f', 2));
      lineEditsHofferError[Loop]->setText(QString::number(REFR, 'f', 2));
       Loop++;
     }
   //  printf("\r\n");

}

