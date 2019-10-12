#include <cstdio>
void swap(int &a,int &b){
	if(a>b){
		int t=a;
		a=b;
		b=t;
	}
}
void bubblesort(int *blist,int count){
	for(int i=0;i<count-1;i++){
		int s=0;
		for(int k=0;k<count-1-i;k++){
			if(blist[k]>blist[k+1]){
			swap(blist[k],blist[k+1]);s=1;}
		}
		if(s==0)break;
	}
}
	
int main(){
	int thelist[13]={9,1,7,3,6,4,12,8,5,10,6,2,0};
	bubblesort(thelist,13);
	for(int k=0;k<13;k++) printf("%d ",thelist[k]);
	return 0;
}
