#include "stdio.h"
#define N 10000 
int main()
{
	int i,j,l,k = 0;
	int s[N];
	for(i = 2;i<=N;i++){
		l = 0;
		for(j = 2;j*j<= i;j++){
			if(i%j == 0) l++;
		}
		if(l==0){s[k++] = i;}
	}
	int M = 0;
	for(i = 2;i<=N;i++){
		l = 0;
		for(j = 2;j*j<= i;j++){
			if(i%j == 0) l++;
		}
		if(l==0){
			M++;
		}
	} 
	int m = 1,a1,n = 0,p,d,q;
	for(p = 0;p < M;p++){
		a1 = s[p];
		for(d = 2;d < M;d++)
		{
			for(q = 0;q < M;q++){
				if(s[q]!= a1 && (s[q]-a1) == m*d)
					m++;
			}
			if(m >= 10) break;
			else m = 1;
		}
		if(m >= 10) break;
	}
	printf("%d %d",a1,d);
	return 0;
}
