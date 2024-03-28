/*
描述
1、2、3… …n这n(0<n<=1000000000)个数中有多少个数可以被正整数b整除。
输入
输入包含多组数据
每组数据占一行，每行给出两个正整数n、b。
输出
输出每组数据相应的结果。
样例输入
2 1
5 3
10 4
样例输出
2
1
2
*/
//解法一 
#include <stdio.h>

main()
{
	long long n,b;
	
	while(scanf("%lld%lld",&n,&b)!=EOF)
	{
		printf("%lld\n",n/b);
	}
	
	return 0;
}
//解法二：超时 
/*
#include <stdio.h>

main()
{
	long long n,b;
	
	while(scanf("%lld%lld",&n,&b)!=EOF)
	{
		long long sum=0,i;
		
		for(i=b;i<=n;i+=b)
		{
			sum++;
		}
		
		printf("%lld\n",sum);
	}
	
	return 0;
}
*/
