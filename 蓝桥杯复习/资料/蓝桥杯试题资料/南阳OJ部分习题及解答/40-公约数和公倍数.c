/*
描述
小明被一个问题给难住了，现在需要你帮帮忙。问题是：给出两个正整数，求出它们的最大公约数和最小公倍数。
输入
第一行输入一个整数n（0<n<=10000)，表示有n组测试数据;
随后的n行输入两个整数i,j（0<i,j<=32767)。
输出
输出每组测试数据的最大公约数和最小公倍数
样例输入
3
6 6
12 11
33 22
样例输出
6 6
1 132
11 66
*/
#include <stdio.h>

int get_GCD(int a,int b)
{
	int t,c;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	
	c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	
	return b;
} 

main()
{
	int n,a,b;
	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		printf("%d %d\n",get_GCD(a,b),a*b/get_GCD(a,b));
	}
	
	return 0;
}




