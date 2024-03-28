/*
描述
已知w是一个大于10但不大于1000000的无符号整数，若w是n(n≥2)位的整数，则求出w的后n-1位的数。

输入
第一行为M，表示测试数据组数。
接下来M行，每行包含一个测试数据。
输出
输出M行，每行为对应行的n-1位数（忽略前缀0）。如果除了最高位外，其余位都为0，则输出0。
样例输入
4
1023
5923
923
1000
样例输出
23
923
23
0
*/
#include <stdio.h>

void num(unsigned int w,int *t,int *s)
{
	int i;
	//出口 
	if(w<10)
	return ;
	//递归
	i=w%10;
	w/=10;
	num(w,t,s);
	if(i!=0&&*t==0)
	*t=1;
	//输出
	if(*t==1)
	{
		printf("%d",i);
		*s=1;
	}
	else if(*t==0&&i!=0)
	{
		printf("%d",i);
		*s=1;
	}
	else
	;
}
main()
{
	int M;
	
	scanf("%d",&M);
	while(M--)
	{
		unsigned int w;
		int t=0,s=0;
		
		scanf("%d",&w);
		num(w,&t,&s);
		if(s==0)
		printf("0");
		printf("\n");
	}
	
	return 0;
} 
