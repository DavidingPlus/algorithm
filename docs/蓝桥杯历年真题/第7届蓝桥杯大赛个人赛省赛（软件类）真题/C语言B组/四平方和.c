#include "stdio.h"
int main()
{
	long N;
	scanf("%d",&N);
	int i,j,k,l;
	int m = 1;
	for(i = 0;i*i<=N;i++){
		for(j = 0;j*j<=N;j++){
			for(k = 0;k*k<=N;k++){
				for(l = 0;l*l <=N;l++){
					if(i*i+j*j+k*k+l*l == N && i<=j && j<=k && k<=l){
						if(m == 1)
						printf("%d %d %d %d\n",i,j,k,l);
						m++;
					}
				}
						
			}
		}
	}
	return 0;
}
