 #include "Fraction.h"
 int gcd(int a, int b);
 Fraction operator+(const Fraction& frac1, const Fraction& frac2); //重载+运算
 Fraction operator-(const Fraction& frac1, const Fraction& frac2); //重载-运算
 Fraction operator*(const Fraction& frac1, const Fraction& frac2); //重载*运算
 Fraction operator/(const Fraction& frac1, const Fraction& frac2); //重载/运算
 bool operator==(Fraction frac1, Fraction frac2);                  //重载==运算
 bool operator>(const Fraction& frac1, const Fraction& frac2);     //重载>运算
 bool operator<(const Fraction& frac1, const Fraction& frac2);     //重载<运算
ostream& operator<<(ostream& out, const Fraction& frac);          //重载<<运算
 istream& operator>>(istream& in, Fraction& frac);                 //重载>>运算
 void sortFraction();//对分数数组排
 void Get();
 void get1();
 void get2();
 bool check(Fraction &frac);