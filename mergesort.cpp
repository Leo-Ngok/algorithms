//merge sort
#include <cstdio>
#include <math.h>
int swap(int &a, int &b){
	int t=a;
	a=b;
	b=t;
}
//sorting range is: [start,end]
void merge(int *arr,int start,int mean,int end){
	//質佢係新陣列
	int ls=mean-start+1;
	//事實上是end-(mean+1)+1; 
	int rs=end-mean;
	
	int left[ls], right[rs];
	//質d數落去臨時數列 
	for(int i=0;i<ls;i++)left[i]=arr[start+i];
	for(int j=0;j<rs;j++)right[j]=arr[mean+1+j];
	int i=0,j=0,k=start;
	//開始質數 
	for(;i<ls&&j<rs;k++){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
		}else{
			arr[k]=right[j];
			j++;
		}
	}
	//質埋剩低哥d 
	for(;i<ls;i++){
		arr[k]=left[i];
		k++;
	}
	for(;j<rs;j++){
		arr[k]=right[j];
		k++;
	}
}
void msort(int *arr,int start,int end){
	int mean=start+(end-start)/2;
	if(start<end) {
		msort(arr,start,mean);
		msort(arr,mean+1,end);
		merge(arr,start,mean,end);		
	}
}
int main(){
	const int count=13;
	int thelist[count]={9,1,7,3,6,4,12,8,5,10,6,2,0};
	msort(thelist,0,count-1);
	for(int k=0;k<count;k++) printf("%d ",thelist[k]);
	return 0;
}
