#include "stdio.h"
int main()
{
	long long n;
	scanf("%ld",&n);
	int l = 0;
	long long i,j;
	for(i = 1;i < n;i++){
		for(j = 1;j < n;j++){if( j == i) continue;
			if((double)i*i/1000000+(double)j*j/1000000 == (double)n*n/1000000)
				l++;			
		}
	}
	printf("%d",l/2);
	return 0;
}
