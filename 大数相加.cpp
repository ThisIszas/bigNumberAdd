#include<iostream>
#include<stdlib.h> 
#include <string.h>
#include<stdio.h>
using namespace std;

string calculate(string a,string b);

int main(){
	string fn,sn;
	cout<<"�����һ�����ֺ͵ڶ�������.\n"; 
	cin>>fn>>sn;
	string result;
	result=calculate(fn,sn);
	cout<<result<<endl;
}

string calculate(string a,string b){
	int temp=0,i=0,sumOfZero=0,carryBit=0,fn,sn;
	string flag,zeros,reverse_Order_Result="",result;
	
	if(a.length() > b.length()) flag = "b";//�ҳ�a,b�ַ����н϶̵��Ǹ�. 
	else flag = "a";
	
	if(flag=="a"){         //��a�϶�,����aǰ�油0,��a="123"->a="000123"; 
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
	
	for(i=(a.length()-1);i>=0;i--){//�������Сѧ��ѧ����ʽ��ӷ���. carryBit��ʾ��λ. 
		fn = a[i]-'0';
		sn = b[i]-'0';                             //     457
		temp = fn+sn+carryBit;                     //   + 123
		carryBit = 0;//ʹ�����λ��,����λ����.    // -----------
		if(temp>9){                                //   = 580 
			carryBit = 1;
			temp = temp - 10; 
		}
		char temp2[256];
		itoa(temp,temp2,10);
		reverse_Order_Result+=temp2;
	}
	
	if(carryBit==1) reverse_Order_Result=reverse_Order_Result+'1';
	for(i=reverse_Order_Result.length()-1;i>=0;i--) result+=reverse_Order_Result[i];
	return result;
}

