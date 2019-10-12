#include <cstdio>
void swap(int &a, int &b){
	int t=a;
	a=b;
	b=t;
}	
void selectionsort(int *slist,int count){
	for(int k=0;k<count-1;k++){
		int min;
		int pos=k;
		for(int i=k;i<count;i++){
			if(i==k)min=slist[k];
			else{
				if(min>slist[i]){
					min=slist[i];
					pos=i;
				}
			}
		}
		swap(slist[k],slist[pos]);
	} 	
}
int main(void){
	int thelist[13]={9,1,7,3,6,4,12,8,5,10,6,2,0};
	selectionsort(thelist,13);
	for(int k=0;k<13;k++) printf("%d ",thelist[k]);
	return 0;
}
