#include<iostream>
#include<stdlib.h> 
#include <string.h>
#include<stdio.h>
using namespace std;

string calculate(string a,string b);

int main(){
	string fn,sn;
	cout<<"输入第一个数字和第二个数字.\n"; 
	cin>>fn>>sn;
	string result;
	result=calculate(fn,sn);
	cout<<result<<endl;
}

string calculate(string a,string b){
	int temp=0,i=0,sumOfZero=0,minNumberLength,carryBit=0,fn,sn,j=0;
	string flag,zeros,kk="",re;
	int result[256];
	if(a.length() > b.length())
	{
		minNumberLength = b.length();
		flag = "b";
	} 
	else{
		minNumberLength = a.length();
		flag = "a";
	}
	
	if(flag=="a"){
		sumOfZero = b.length() - a.length();
		for(i=0;i<sumOfZero;i++){
			zeros+="0";
		}
		a= zeros + a;
	}
	else{
		sumOfZero = a.length() - b.length();
		for(i=0;i<sumOfZero;i++){
			zeros+="0";
		}
		b= zeros + b;
	} 
	
	for(i=(a.length()-1);i>=0;i--){
		fn = a[i]-'0';
		sn = b[i]-'0';
		temp = fn+sn+carryBit;
		carryBit = 0;
		if(temp>9){
			carryBit = 1;
			temp = temp - 10; 
		}
		char temp2[256];
		itoa(temp,temp2,10);
		kk+=temp2;
		result[j] = temp;
		j++;
	}
	if(carryBit==1) kk=kk+'1';
	for(i=kk.length()-1;i>=0;i--) re+=kk[i];
	return re;
}

