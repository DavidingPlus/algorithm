#include "stdio.h"
int main(void)
{
	int i,N;
	scanf("%d",&N);
	long long s[N];
	for(i = 0;i < N;i++)
		scanf("%ld",&s[i]);
	f(s,N);
	
}
int f(long long s[],int N)
{
	int i,j;
	long long t;
	for(i = 1;i < N;i++){
		for(j = 1;j < N-i+1;j++){
			if(s[j-1] > s[j]){
				t = s[j-1];
				s[j-1] = s[j];
				s[j] = t;
			}
		}
	}
}
