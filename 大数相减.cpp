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
	int temp=0,i=0,sumOfZero=0,carryBit=0,fn,sn;
	string flag,zeros,reverse_Order_Result="",result,changeValue;
	
	if(a.length() > b.length()) flag = "b";//找出a,b字符串中较短的那个. 
	else flag = "a";
	
	if(flag=="a"){         //若a较短,则在a前面补0,如a="123"->a="000123"; 
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
	if(a.length() == b.length()){
		for(i=0;i<a.length();i++){
			fn = a[i]-'0';
			sn = b[i]-'0';
			if(fn!=sn){
				if(fn < sn){
					changeValue = a;
					a = b ;
					b = changeValue ;
					flag = "true";
				}
			}
		}
	} 
	for(i=(a.length()-1);i>=0;i--){
		fn = a[i]-'0';
		sn = b[i]-'0';                            
		temp = fn-sn-carryBit;                    
		carryBit = 0;
		if(temp<0){                               
			carryBit = 1;
			temp = temp + 10; 
		}
		char temp2[256];
		itoa(temp,temp2,10);
		reverse_Order_Result+=temp2;
	}
	
	if(flag == "true") reverse_Order_Result=reverse_Order_Result+'-';
	for(i=reverse_Order_Result.length()-1;i>=0;i--) result+=reverse_Order_Result[i];
	return result;
}

