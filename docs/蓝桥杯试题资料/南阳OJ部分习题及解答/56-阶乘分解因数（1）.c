/*
描述
给定两个数m,n,其中m是一个素数。

将n（0<=n<=10000）的阶乘分解质因数，求其中有多少个m。

输入
第一行是一个整数s（0<s<=100)，表示测试数据的组数
随后的s行, 每行有两个整数n，m。
输出
输出m的个数。
样例输入
2
100 5
16 2
样例输出
24
15
*/
#include <stdio.h>

main()
{
	int s,m,n,sum=0,f;
	int i,j;
	
	scanf("%d",&s);
	
	while(s--)
	{
		scanf("%d%d",&n,&m);
		for(i=m,j=1;i<=n;j++,i=j*m)
		{
			f=i;
			while(f%m==0)
			{
				f=f/m;
				sum++;
			}
		}
		printf("%d\n",sum);
		sum=0;
		
	}
	 
	return 0;
} 











