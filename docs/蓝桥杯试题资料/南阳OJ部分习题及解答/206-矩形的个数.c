/*
描述
在一个3*2的矩形中，可以找到6个1*1的矩形，4个2*1的矩形3个1*2的矩形，2个2*2的矩形，2个3*1的矩形和1个3*2的矩形，总共18个矩形。

给出A，B,计算可以从中找到多少个矩形。
输入
本题有多组输入数据（<10000），你必须处理到EOF为止

输入2个整数A,B(1<=A,B<=1000)

输出
输出找到的矩形数。 
样例输入
1 2
3 2
样例输出
3
18
*/
//解法一
#include <stdio.h>

main()
{
	int m,n;
	
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		//公式，个数和为(m+1)*(n+1)*m*n/4个 
		printf("%lld\n",(long long)(m+1)*(n+1)*m*n/4);
	}
	
	return 0;
}
/*
//解法二（非公式）：思路正确，但数据过大时会超时 
#include <stdio.h>

main()
{
	int a,b,i,j;
	long long s;

	while(scanf("%d%d",&a,&b)!=EOF) 
	{
		s=0;
		// 1*1 有a*b个
		//1*2 有a*(b-1)个
		//...... 
		//2*1 有(a-1)*b个
		for(i=a;i>0;i--)
		for(j=b;j>0;j--)
		s+=i*j;
		printf("%lld\n",s);
	}
	
	return 0;
}
*/
