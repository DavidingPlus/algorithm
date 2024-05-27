#include <stdio.h>
#define BUF 1024

void f(int a[], int k, int m, char b[])
{
	int i,j;
	if(k==6){ 
		b[5] = 0;
		if(m==0) printf("%s\n",b);
		return;
	}
	
	for(i=0; i<=a[k]; i++){
		for(j=0; j<i; j++) b[5-m+j] = k+'A';
	f(a,k+1,m-i,b);//Ìî¿ÕÎ»ÖÃ
	}
}
int main()
{	
	int  a[6] = {4,2,2,1,1,3};
	char b[BUF];
	f(a,0,5,b);
	return 0;
}
