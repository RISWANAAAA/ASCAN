#ifndef CALFORMULA_H
#define CALFORMULA_H
#include<QLineEdit>


class CalFormula
{
public:
    CalFormula();
    struct iol_formula {
        double PEMM;
        double PORx[5];
        double IOLPower[5];
    }SRKIIValues;
    struct iol_formula1 {
        double PEMM;
        double PORx[5];
        double IOLPower[5];
    }HolladayValues;
    struct iol_formula2 {
        double PEMM;
        double PORx[5];
        double IOLPower[5];
    }SRKTValues;
    struct iol_formula3 {
        double PEMM;
        double PORx[5];
        double IOLPower[5];
    }HOFFERValues;

    int diff(double emm);
   int calculateacd(double AL, double AConst, double KD);
   void SRKIICalc(double AL, double AConst, double K, double Rx,QLineEdit *lineEditsPower[], QLineEdit *lineEditsError[],QLineEdit *emmetropiaEdit);
   void HolladayCalc(double AL, double SF, double K,double Rx,QLineEdit *lineEditIOLPower[], QLineEdit *lineEditRefError[], QLineEdit *emmetropiaEdit);
   void SRKTCalc(double AL, double AConst,double K,double Rx,QLineEdit *lineEditsSRKTPower[], QLineEdit *lineEditsSRKTError[], QLineEdit *emmetropiaSRKTEdit);
   int HofferCalc(double A, double ACD, double K,double Rx,QLineEdit *lineEditsHofferPower[], QLineEdit *lineEditsHofferError[], QLineEdit *emmetropiaHofferEdit);
   void Haigis(double A, double AConst, double K,double Rx,QLineEdit *lineEditsPower[], QLineEdit *lineEditsError[], QLineEdit *emmetropiaEdit);
};

#endif // CALFORMULA_H
