#include<iostream>
#include<stdlib.h> 
#include <string.h>
#include<stdio.h>
using namespace std;

string calculate(string a,string b);
int resultList[256];

int main(){
	string fn,sn;
	cout<<"输入第一个数字和第二个数字.\n"; 
	cin>>fn>>sn;
	string result;
	result=calculate(fn,sn);
	cout<<result<<endl;
}

string calculate(string a,string b){
	int temp=0,i=0,j=0,sumOfZero=0,carryBit=0,fn,sn,min,k=0,moveStep=0,jj;
	string flag,zeros,reverse_Order_Result="",result,changeValue;
	
	if(a.length() > b.length()) flag = "b";//找出a,b字符串中较短的那个. 
	else flag = "a";
	
	if(flag=="a"){         //若a较短,则在a前面补0,如a="123"->a="000123"; 
		min = a.length();
		sumOfZero = b.length() - a.length();
		for(i=0;i<sumOfZero;i++){
			zeros+="0";
		}
		a= zeros + a;
	}
	else{
		min = b.length();
		sumOfZero = a.length() - b.length();
		for(i=0;i<sumOfZero;i++){
			zeros+="0";
		}
		b= zeros + b;
	} 
//	if(a.length() == b.length()){
//		for(i=0;i<a.length();i++){
//			fn = a[i]-'0';
//			sn = b[i]-'0';
//			if(fn!=sn){
//				if(fn < sn){
//					changeValue = a;
//					a = b ;
//					b = changeValue ;
//					flag = "true";
//				}
//			}
//		}
//	} 
//	for(i=(a.length()-1);i>=(a.length()-min);i--){
	for(i=(a.length()-1);i>=0;i--){
		//fn = a[i]-'0';
		sn = b[i]-'0';                            
//		temp = fn-sn-carryBit;                    
//		carryBit = 0;
//		if(temp<0){                               
//			carryBit = 1;
//			temp = temp + 10; 
//		}
		for(j=(a.length()-1);j>=0;j--){
			fn = a[j]-'0';
			temp = fn*sn+carryBit;
//			cout<<"开始  "<<"carryBit:"<<carryBit<<" temp:"<<temp<<" fn:"<<fn<<" sn:"<<sn<<endl;
			carryBit = 0;
			if(temp>9){
				carryBit = temp/10;
				temp=temp%10;
			}
//			cout<<"之后  "<<"carryBit:"<<carryBit<<" temp:"<<temp<<" fn:"<<fn<<" sn:"<<sn<<endl;
//			cout<<"j:"<<j<<" k:"<<k<<" min:"<<min<<" j-k+min:"<<j-k+min<<endl;
			resultList[j-k+min] = resultList[j-k+min] + temp;
//			for(jj=0;jj<6;jj++) cout<<resultList[jj]<<" ";
//			cout<<endl; 
		}
		if(carryBit!=0) {
//			cout<<"j:"<<j<<" k:"<<k<<endl;
			moveStep++;
			resultList[j-k+min] = resultList[j-1-k+min] + carryBit;
////			cout<<"外部:"; 
//			for(jj=0;jj<4;jj++) cout<<resultList[jj]<<" ";
//			cout<<endl; 
		}
		carryBit=0;
		k++;
		
//		char temp2[256];
//		itoa(temp,temp2,10);
//		reverse_Order_Result+=temp2;
	} 
//	cout<<endl<<"moveStep:"<<moveStep<<" min:"<<min<<" a.length:"<<a.length()<<endl;
	
	for(i=(a.length()+min)-1;i>=(min-moveStep);i--){
		if(resultList[i]>9){
			carryBit = resultList[i]/10;
			resultList[i] = resultList[i]%10;
			resultList[i-1] = resultList[i-1]+carryBit;
			carryBit = 0;
		}
	}
//	for(jj=0;jj<9;jj++) cout<<resultList[jj]<<" ";
//	cout<<endl;
//	cout<<"a:"<<a<<" b:"<<b<<endl;
	int count=-1;
	for(j=0;j<a.length()+min;j++){
		if(resultList[i]!=0){
			count++;
			break;
		}
	}
	for(i=0;i<a.length()+min;i++) //cout<<resultList[i]<<" ";
	{	
		
		if(resultList[i]!=0 && i!=count){
			char temps[256];
			temp = resultList[i];
			itoa(temp,temps,10);
			result+=temps;
		}
	}
	//for(i=0;i<4;i++)
//	if(flag == "true") reverse_Order_Result=reverse_Order_Result+'-';
//	for(i=reverse_Order_Result.length()-1;i>=0;i--) result+=reverse_Order_Result[i];
	return result;
}

