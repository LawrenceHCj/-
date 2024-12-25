#include <iostream>
#include "Fraction.h"
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int gcd(int a , int b){ //��÷��ӷ�ĸ�����Լ��
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
 Fraction operator+(const Fraction& frac1, const Fraction& frac2){//����+�����
   Fraction tempF;
   tempF.numer = frac1.numer*frac2.deno + frac2.numer*frac1.deno;
	tempF.deno = frac1.deno*frac2.deno;
	tempF.RdcFrc();
	return tempF;
 }

 Fraction operator-(const Fraction& frac1, const Fraction& frac2){//����-�����
     Fraction tempF;
   tempF.numer = frac1.numer*frac2.deno - frac2.numer*frac1.deno;
	tempF.deno = frac1.deno*frac2.deno;
	tempF.RdcFrc();
	return tempF;
 }
 Fraction operator*(const Fraction& frac1, const Fraction& frac2){//����*�����
 	Fraction tempF;
 	tempF.numer = frac1.numer * frac2.numer;
 	tempF.deno = frac1.deno * frac2.deno;
 	tempF.RdcFrc();
 	return tempF;
 }
 Fraction operator/(const Fraction& frac1, const Fraction& frac2){//����/�����
 	Fraction tempF;
 	tempF.numer = frac1.numer * frac2.deno;
 	tempF.deno = frac2.deno * frac1.numer;
 	tempF.RdcFrc();
 	return tempF;
 }
 bool operator==(Fraction frac1, Fraction frac2){
 	if((double)frac1.numer/frac1.deno == frac2.numer /(double) frac2.deno){//����==�����
 		return true;
	 }
	else {
		return false;
	}
 }
  bool operator>(const Fraction &frac1,const Fraction& frac2){
 	if((double)frac1.numer/frac1.deno > frac2.numer / (double)frac2.deno){//����>�����
 		return true;
	 }
	else {
		return false;
	}
 }
 bool operator<(const Fraction &frac1, const Fraction &frac2){//����<�����
 	if(frac1.numer/(double)frac1.deno < frac2.numer /(double) frac2.deno){
 		return true;
	 }
	else {
		return false;
	}
 }
 ostream& operator<<(ostream& out, const Fraction& frac){//����<<�����
 	cout<<frac.numer<<"/"<<frac.deno;
 	return out;
 }
 istream& operator>>(istream& in, Fraction& frac){//����>>�����
 	char sign;//��ȡ������ "/"
 	int numer,deno;
 	cin >> frac.numer>>sign>>frac.deno;
 	return in;
 }
  bool checkDeno(Fraction &frac){//��֤�����ķ�ĸ�Ƿ�Ϊ0
 		if(frac.deno == 0){
 			cout<<"��ĸ����Ϊ0�����������룡"<<endl;
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
 
 void get1(){//�û�ѡ��1ִ�д˺���
 	while(1){
 		cout <<"�������������ʽ����1/2+1/3�س���������#�ż�������һ��Ŀ¼��"<<endl;
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
			 cout << "������ʽ�������!"<<endl;
 			break;
			 }
		 }
		 if(checkDeno(F1)&&checkDeno(F2)){
		 }
		 else {
		 	continue;
		 }
		if(signal!='+'&&signal!='-'&&signal!='*'&&signal!='/'){
			cout<<"������ʽ�������!"<<endl;
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
 void sortFraction(vector<Fraction> &frac , char signal){//�Ի�õķ�������������
 	if(signal == '>'){
 		sort(frac.begin() , frac.end() , greater<>());
	 }
	else if (signal == '<'){
		sort(frac.begin() , frac.end() , less<>());
	}
 }
 void get2(){//�û�ѡ��2ִ�д˺���
 	while(1){cout << "������һ��������ö��Ÿ�����������С���������÷���<��β,"
	 <<"�ɴ�С�����÷���>��β����1/2,1/4,3/5<�س���������#�ż�������һ��Ŀ¼��"
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
		cout<<"�������!"<<endl;
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
 void Get(){//�û��򿪽���ʹ�ô˺���
 	while(true){
 	cout << "1. ��������" << endl;
	cout << "2. ��������" << endl;
	int A;
	cin >> A;
	if(cin.fail()){
		cout<<"������Ч����������"<<endl;
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
				cout<<"������Ч����������"<<endl;
				continue;
			}
		}
	}
	}
 }
