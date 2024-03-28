#include "stdio.h"
#include "math.h"
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i = 0; i < n;i++)
	{
		if(is_prime(i))
			printf("%d\n",i);
	}
	return 0;
}
int is_prime(int n){
	if(n <= 1)
		return 0;
	int j = floor(sqrt(n)+0.5);
	int i;
	for(i = 2;i <= j;i++){
		if(n % i == 0)
			return 0;	
	}
	return 1;
}
