#include <iostream>
#include "function.h"
using namespace std;
Fraction::Fraction (){}
Fraction::Fraction (int n , int b){//�вι��캯��������Ҫ���ĸ��Ϊ0
    if(b != 0){
	this->deno = b;
    this->numer = n;
	}
	else{cout << "��ĸ����Ϊ0"<<endl;
	}
}
Fraction::Fraction (const Fraction&p){
    this->deno = p.deno;
    this->numer = p.numer;
}
void Fraction::setFraction (int n, int b){
    if(b != 0){
	this->deno = b;
    this->numer = n;
	}
	else{cout << "��ĸ����Ϊ0"<<endl;
	}
}
int Fraction::getNumer(){
    return numer;
}
int Fraction::getDeno(){
    return deno;
}
void Fraction::RdcFrc(){
    	if(numer == 0){
	}
	else{
	int common = gcd(numer , deno);
    deno = deno/common;
    numer = numer / common;
	}
}
