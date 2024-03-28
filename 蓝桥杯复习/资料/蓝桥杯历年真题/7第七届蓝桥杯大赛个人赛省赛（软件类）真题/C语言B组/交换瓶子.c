#include "stdio.h"
int count = 0;
int N;
int main()
{
	int i;
	scanf("%d",&N);
	int a[N];
	for(i = 0;i < N;i++)
		scanf("%d",&a[i]);
	f(a,0);
	return 0;
}
int f(int a[],int p)
{
	if(p == N-1){
		printf("%d",count);
	}
	if(a[p] == p+1)
		f(a,p+1);
	else
	{
		int i;
		for(i = p+1;i < N;i++){
			if(a[i] == p+1){
				swap(a,i,p);
				f(a,p+1);
			}		
		}
		p++;		
	}
}
int swap(int a[],int i,int p)
{
	int t;
	t = a[i];
	a[i] = a[p];
	a[p] = t;
	count++;
}
