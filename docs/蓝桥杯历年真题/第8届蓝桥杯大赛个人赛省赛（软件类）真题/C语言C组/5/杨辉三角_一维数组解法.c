#include "stdio.h"
// 杨辉三角的第row行，第col列 
long long f(int row, int col){
	if(row<2) return 1;
	if(col==0) return 1;
	if(col==row) return 1;
	
	long long a[1024];
	a[0]=1;
	a[1]=1;	
	int p = 2;
	int q;
	
	while(p<=row){
		a[p] = 1;
		for(q=p-1; q>0; q--) 
			a[q] = a[q] + a[q-1]; //填空
		p++;
	}
	
	return a[col];
}

int main()
{
	printf("%d\n", f(6,2));
	printf("%d\n", f(6,3));
	printf("%lld\n", f(40,20));	
	return 0;
}
