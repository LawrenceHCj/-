#include <iostream>
#include "Fraction.h"
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int gcd(int a , int b){ //获得分子分母的最大公约数
    if(a > b){
        while (b != 0) 
        {
		int temp = b;
		b = a % b;
		a = temp;
        }
        }
    else {
        int temp = a;
        a = b;
        b = temp;
        while (b != 0) 
        {
		temp = b;
		b = a % b;
		a = temp;
        }
    }
    return a;
}
 Fraction operator+(const Fraction& frac1, const Fraction& frac2){//重载+运算符
   Fraction tempF;
   tempF.numer = frac1.numer*frac2.deno + frac2.numer*frac1.deno;
	tempF.deno = frac1.deno*frac2.deno;
	tempF.RdcFrc();
	return tempF;
 }

 Fraction operator-(const Fraction& frac1, const Fraction& frac2){//重载-运算符
     Fraction tempF;
   tempF.numer = frac1.numer*frac2.deno - frac2.numer*frac1.deno;
	tempF.deno = frac1.deno*frac2.deno;
	tempF.RdcFrc();
	return tempF;
 }
 Fraction operator*(const Fraction& frac1, const Fraction& frac2){//重载*运算符
 	Fraction tempF;
 	tempF.numer = frac1.numer * frac2.numer;
 	tempF.deno = frac1.deno * frac2.deno;
 	tempF.RdcFrc();
 	return tempF;
 }
 Fraction operator/(const Fraction& frac1, const Fraction& frac2){//重载/运算符
 	Fraction tempF;
 	tempF.numer = frac1.numer * frac2.deno;
 	tempF.deno = frac2.deno * frac1.numer;
 	tempF.RdcFrc();
 	return tempF;
 }
 bool operator==(Fraction frac1, Fraction frac2){
 	if((double)frac1.numer/frac1.deno == frac2.numer /(double) frac2.deno){//重载==运算符
 		return true;
	 }
	else {
		return false;
	}
 }
  bool operator>(const Fraction &frac1,const Fraction& frac2){
 	if((double)frac1.numer/frac1.deno > frac2.numer / (double)frac2.deno){//重载>运算符
 		return true;
	 }
	else {
		return false;
	}
 }
 bool operator<(const Fraction &frac1, const Fraction &frac2){//重载<运算符
 	if(frac1.numer/(double)frac1.deno < frac2.numer /(double) frac2.deno){
 		return true;
	 }
	else {
		return false;
	}
 }
 ostream& operator<<(ostream& out, const Fraction& frac){//重载<<运算符
 	cout<<frac.numer<<"/"<<frac.deno;
 	return out;
 }
 istream& operator>>(istream& in, Fraction& frac){//重载>>运算符
 	char sign;//获取分数线 "/"
 	int numer,deno;
 	cin >> frac.numer>>sign>>frac.deno;
 	return in;
 }
  bool checkDeno(Fraction &frac){//验证分数的分母是否为0
 		if(frac.deno == 0){
 			cout<<"分母不能为0，请重新输入！"<<endl;
 			return false;
		 }
		 else{
		 	return true;
		 }
 }
bool checkNumer(Fraction &frac){
	if(frac.numer ==0) {
	return false;}
	else {
	return true;}
}
 
 void get1(){//用户选择1执行此函数
 	while(1){
 		cout <<"请输入分数计算式（如1/2+1/3回车），输入#号键返回上一层目录："<<endl;
 		char signal;
 		Fraction F1,F2;
 		cin>>F1>>signal>>F2;
 		while(cin.fail()){
 			cin.clear();
 			if(cin.peek()=='#'){
 				getchar();
 				system("cls");
 				return;
			 }
 			else{
			 cout << "分数算式输入错误!"<<endl;
 			break;
			 }
		 }
		 if(checkDeno(F1)&&checkDeno(F2)){
		 }
		 else {
		 	continue;
		 }
		if(signal!='+'&&signal!='-'&&signal!='*'&&signal!='/'){
			cout<<"分数算式输入错误!"<<endl;
			continue;
		}
		else if(signal == '+'){
			Fraction tempF = F1+F2;
			if(!checkNumer(tempF)){
				cout<<"=0"<<endl;
			}
			else {
			cout <<"="<< tempF<<endl;}
		}
		else if(signal == '-'){
			Fraction tempF = F1-F2;
			if(!checkNumer(tempF)){
				cout<<"=0"<<endl;
			}
			else {
			cout <<"="<< tempF<<endl;}
		}	
		else if(signal == '*'){
			Fraction tempF = F1*F2;
				if(!checkNumer(tempF)){
				cout<<"=0"<<endl;
			}
			else {
			cout <<"="<< tempF<<endl;}
		}	
		else if(signal == '/'){
			Fraction tempF = F1/F2;
				if(!checkNumer(tempF)){
				cout<<"=0"<<endl;
			}
			else {
			cout <<"="<< tempF<<endl;}
		}
	 }
 }
 void sortFraction(vector<Fraction> &frac , char signal){//对获得的分数按需求排序
 	if(signal == '>'){
 		sort(frac.begin() , frac.end() , greater<>());
	 }
	else if (signal == '<'){
		sort(frac.begin() , frac.end() , less<>());
	}
 }
 void get2(){//用户选择2执行此函数
 	while(1){cout << "请输入一组分数，用逗号隔开，如需由小到大排序用符号<结尾,"
	 <<"由大到小排序用符号>结尾（如1/2,1/4,3/5<回车），输入#号键返回上一层目录："
	<< endl;
	vector<Fraction> frac;
	Fraction temp;
	char signal;
	while(1){
cinPlace:	cin>>temp>>signal;
	while(cin.fail() || (signal !=','&&signal !='<'&&signal !='>')){
		cin.clear();
		if(cin.peek()=='#'){
			getchar();
			system("cls");
			return;
		}
		cout<<"输入错误!"<<endl;
		cin.ignore(INT_MAX,'\n');
       goto cinPlace;
	}
	if(checkDeno(temp)){
	frac.push_back(temp);
	if(signal=='<'||signal=='>'){
		break;
	}
	}	else { cin.ignore(INT_MAX,'\n');
	goto cinPlace;
	}}

	sortFraction(frac, signal);
	vector<Fraction>::iterator start = frac.begin();
	vector<Fraction>::iterator end = frac.end();
		while (start != end) {
			cout << *start << " ";
			start++;
		}
		cout<<endl;
	
 }
 }
 void Get(){//用户打开界面使用此函数
 	while(true){
 	cout << "1. 分数运算" << endl;
	cout << "2. 分数排序" << endl;
	int A;
	cin >> A;
	if(cin.fail()){
		cout<<"输入无效请重新输入"<<endl;
		continue;
	}
	else{
		switch(A){
			case 1 :{
				system("cls");
				get1();
				break;
			}
			case 2:{
				system("cls");
				get2();
				break;
			}
			default:{
				cout<<"输入无效请重新输入"<<endl;
				continue;
			}
		}
	}
	}
 }
