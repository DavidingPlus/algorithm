/*
描述
现在给你N个数（0<N<1000），现在要求你写出一个程序，找出这N个数中的所有素数，并求和。
输入
第一行给出整数M(0<M<10)代表多少组测试数据
每组测试数据第一行给你N，代表该组测试数据的数量。
接下来的N个数为要测试的数据，每个数小于1000
输出
每组测试数据结果占一行，输出给出的测试数据的所有素数和
样例输入
3
5
1 2 3 4 5
8
11 12 13 14 15 16 17 18
10
21 22 23 24 25 26 27 28 29 30
样例输出
10
41
52
*/

#include <stdio.h>
#include <math.h>

int is_permit(int num)
{
	int i;
	
	if(num==1)
	return 0;
	
	for(i=2;i*i<num+1;i++)
	{
		if(num%i==0)
		return 0;
	}
	
	return 1;
}

main()
{
	int n,m;
	int i,temp;
	int num[1005]={0},sum[15]={0};
	
//	for(i=1;i<50;i++)
//	printf("%d=%d\n",i,is_permit(i)); 
	
	scanf("%d",&m);
	temp=m;
	
	//遍历temp组数据
	while(m--)
	{
		//n个数据 
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			
			//n个数据中的素数和存入对应的组数 
			if(is_permit(num[i]))
			{
				sum[temp-m-1]+=num[i];
			}
			
//			printf("当前数组质数和%d\n",sum[temp-m-1]);
		}
	}
	
	//输出这temp组数据
	for(i=0;i<temp;i++)
	{
		printf("%d\n",sum[i]);
	} 
	
	return 0;
}







