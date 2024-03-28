/*
描述
小南刚学了二进制，他想知道一个数的二进制表示中有多少个1，你能帮他写一个程序来完成这个任务吗？
输入
第一行输入一个整数N，表示测试数据的组数(1<N<1000)
每组测试数据只有一行，是一个整数M(0=<M<=10000)
输出
每组测试输出占一行，输出M的二进制表示中1的个数
样例输入
3
4
6
7
样例输出
1
2
3
*/
#include <stdio.h>

main()
{
	int N;
	
	scanf("%d",&N);
	while(N--)
	{
		int M;
		int sum=0;
		
		scanf("%d",&M);
		//循环M的2进制，遇见1，计量器sum加1
		while(!(M==0||M==1))
		{
			int c;
			c=M%2;
			if(c==1)
			sum++;
			M=M/2;
		}
		//输出sum
		if(M==1)
		printf("%d\n",sum+1);
		else
		printf("%d\n",sum);
		 
	}
	
	return 0;
}
