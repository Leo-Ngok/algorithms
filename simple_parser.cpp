#include <cstring>
#include <iostream>
#include <complex>
#include <cstdio>
using namespace std;
int main(){
	char s[50];
	scanf("%s",s);
	int n=strlen(s);
	char x;
	for(int u=0;u<n;u++){
		if(s[u]>='a'&&s[u]<='z') x=s[u];
	}
	complex<int> sum (0,0);
	complex<int> temp (0,0);
	bool islhs=false;
	bool isunknown=false;
	int mi=1;
	for(int l=n-1;l>=0;l--){
		if(s[l]>='0'&&s[l]<='9'){
			
				
						
			if(!isunknown){
				real(temp)+=(s[l]-'0')*mi;
				mi*=10; 
			}
			else{
				 imag(temp)+=(s[l]-'0')*mi;
				 mi*=10;
			}
			if(l==0){
				sum+=temp;
			}
		}
		if(s[l]==x){
			isunknown=true;
			if(l==0) sum.imag()++;
		}
		if(s[l]=='+'){
			isunknown=false;
			if(s[l+1]==x){
				if(!islhs){
					imag(sum)--;
				}else{
					imag(sum)++; 
			}
			}else{
				if(!islhs){
					sum-=temp;
				}else{
					sum+=temp; 
				}
			}
			
			
			mi=1;
			real(temp)=0;
			imag(temp)=0;
		}
		if(s[l]=='-'){
			isunknown=false;
			if(s[l+1]==x){
				if(!islhs){
					imag(sum)++;
				}else{
					imag(sum)--;
				} 
			}
			else{
				if(!islhs){
					sum+=temp;
				}else{
					sum-=temp; 
				}
			}
			mi=1;
			real(temp)=0;
			imag(temp)=0;
		}
		if(s[l]=='=') {
			islhs=true;
			if(s[l+1]==x){
				isunknown=false;
				imag(sum)--;
				mi=1;
				real(temp)=0;
				imag(temp)=0;
			}
			if(s[l+1]!='+'&&s[l+1]!='-'){
				isunknown=false;
				sum-=temp;
				mi=1;
				real(temp)=0;
				imag(temp)=0;
			}
		}
		
	}
	double result=-real(sum)*1.0/imag(sum);
	printf("%c=%.3f\n",x,result);
	return 0;
}
