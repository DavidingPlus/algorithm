#include "stdio.h"
int BinarySearch(int a[],int N,int key)
{
	int low = 0, high = N;
	int mid;
	while(low <= high){
		mid = (low+high)/2;
		if( key == a[mid]) return mid+1;
		if(key < a[mid]) high = mid-1;
		else low = mid+1; 
	}
	return -1;
		
}
int main()
{
	int a[] = {2,4,6,10,28,34,46,49,53,67,90};
	int N = sizeof(a)/sizeof(a[0]);//切记在函数内部调用sizeof将会错误 
	int t = BinarySearch(a,N,9);
	printf("%d",t);
	return 0;
}

