/*
描述
做了A+B Problem之后，Yougth感觉太简单了，于是他想让你求出两个数反转后相加的值。帮帮他吧
输入
有多组测试数据。每组包括两个数m和n，数据保证int范围，当m和n同时为0是表示输入结束。
输出
输出反转后相加的结果。
样例输入
1234 1234
125 117
0 0
样例输出
8642
1232
*/
//解法一：
#include <stdio.h>

int NumberFormat(int n)
{
	int sum=0;
	while(n)
	{
		sum=sum*10+n%10;
		n/=10;
	}
	return sum;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&(a||b))
	{
		printf("%d\n",NumberFormat(a)+NumberFormat(b));
	}
	return 0;
}
//解法二：递归