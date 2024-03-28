/*
描述
求A+B是否与C相等。
输入
T组测试数据。
每组数据中有三个实数A,B,C(-10000.0<=A,B<=10000.0,-20000.0<=C<=20000.0)
数据保证小数点后不超过4位。

输出
如果相等则输出Yes
不相等则输出No
样例输入
3
-11.1 +11.1 0
11 -11.25 -0.25
1 2 +4
样例输出
Yes
Yes
No
*/
#include <stdio.h>

main()
{
	int T;
	
	scanf("%d",&T);
	while(T--)
	{
		double A,B,C;
		
		scanf("%lf%lf%lf",&A,&B,&C);
		A+B-C>-0.0001&&A+B-C<0.0001? printf("Yes\n"):printf("No\n");	
	}
	
	return 0;
}
