#include "stdio.h"
int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
	int s[] = {2,1,3,4};
	printf("%d",cantor(s,4));;
	return 0;	
}
int cantor(int s[],int n)
{
	int i,j,temp,num;
	num=0;
	for(i=0;i<n;i++)
	{
		temp=0;
		for(j=i+1;j<n;j++)
		{
			if(s[j]<s[i]) temp++;//判断几个数小于它
		}
		num+=fac[n-i-1]*temp;//(或num=num+fac[n-i-1]*temp;)
	}
	return (num+1);
} 
