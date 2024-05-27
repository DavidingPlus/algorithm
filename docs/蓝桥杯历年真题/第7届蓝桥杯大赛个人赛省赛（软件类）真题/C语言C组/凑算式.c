#include <stdio.h>
int a[362880][9];
int T = -1,count = 0;
void f(int  s[],int l)
{
	int i,j,t;
	if(l == 8){
		T = T+1;
		for(j = 0;j < 9;j++)
			a[T][j] = s[j];
		return;
	}
	for(i = l;i < 9;i++){
		{t = s[l];s[l] = s[i];s[i] = t;}
		f(s,l+1);
		{t = s[l];s[l] = s[i];s[i] = t;}		
	}
}
int main()
{
	int s[] = {1,2,3,4,5,6,7,8,9};
	f(s,0);
	int i,j,A,B,C,P,Q;
	for(i = 0;i < 362880;i++){
		A = a[i][0];
		B = a[i][1];
		C = a[i][2];
		P = a[i][3]*100+a[i][4]*10+a[i][5];
		Q = a[i][6]*100+a[i][7]*10+a[i][8];
		if(A*C*Q+B*Q+C*P == 10*C*Q){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
