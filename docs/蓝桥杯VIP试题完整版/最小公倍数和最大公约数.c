#include "stdio.h"
#include "math.h" 
int main(void)
{
	long long a,b;
	scanf("%d%d",&a,&b);
	printf("最大公约数:%d \n",gcd(a,b));
	printf("最小公倍数:%d ",a*b/gcd(a,b));
	return 0;
}
int gcd(long long a,long long b)
{
	if(b == 0) return a;
	else{ return gcd(b,a%b);}
 } 
