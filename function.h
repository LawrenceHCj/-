 #include "Fraction.h"
 int gcd(int a, int b);
 Fraction operator+(const Fraction& frac1, const Fraction& frac2); //����+����
 Fraction operator-(const Fraction& frac1, const Fraction& frac2); //����-����
 Fraction operator*(const Fraction& frac1, const Fraction& frac2); //����*����
 Fraction operator/(const Fraction& frac1, const Fraction& frac2); //����/����
 bool operator==(Fraction frac1, Fraction frac2);                  //����==����
 bool operator>(const Fraction& frac1, const Fraction& frac2);     //����>����
 bool operator<(const Fraction& frac1, const Fraction& frac2);     //����<����
ostream& operator<<(ostream& out, const Fraction& frac);          //����<<����
 istream& operator>>(istream& in, Fraction& frac);                 //����>>����
 void sortFraction();//�Է���������
 void Get();
 void get1();
 void get2();
 bool check(Fraction &frac);