#include <iostream>
using namespace std;
class Fraction
{
friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //重载+运算符
friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //重载-运算符
friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //重载*运算符
friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //重载/运算符
friend bool operator==(Fraction frac1, Fraction frac2);                  //重载==运算符
friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //重载>运算符
friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //重载<运算符
friend ostream& operator<<(ostream& out, const Fraction& frac);          //重载<<运算符
friend istream& operator>>(istream& in, Fraction& frac);   				 //重载>>运算符
friend bool checkDeno(Fraction &frac); 
friend bool checkNumer(Fraction &frac);            
	friend void sortFraction();//对分数数组排序
public:
Fraction();                      //无参造函数
Fraction(int n, int d);          //带参造函数
Fraction(const Fraction& f);     //复制造函数
void setFraction(int n, int d);  //设置分数的分子和分母
int getNumer();                  //获取分数的分子
int getDeno();                   //获取分数的分母
void RdcFrc();                   //当前分数约分
private:
int numer;
int deno;
};
