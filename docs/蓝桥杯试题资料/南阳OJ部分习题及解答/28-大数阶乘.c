/*
描述
我们都知道如何计算一个数的阶乘，可是，如果这个数很大呢，我们该如何去计算它并输出它？
输入
输入一个整数m(0<m<=5000)
输出
输出m的阶乘，并在输出结束之后输入一个换行符
样例输入
50
样例输出
30414093201713378043612608166064768844377641568960512000000000000

解法：
*注意 由于5000！有16325位，所以数组必须开的大些

数组测试函数
void printA(int P[])
{
	int i;
	for(i=0;i<MaxSize;i++)
	{
		printf("%d",P[i]);
	}
	printf("\n");
	
	return ;
} 
*/
#include <stdio.h>
#include <string.h>
#define MaxSize 17000

void resultProduct(int P[],int num)
{
	int i,tp=0,st=0;
	
	for(i=0;i<MaxSize;i++)
	{
		st=tp;
		tp=(P[i]*num+st)/10;
		P[i]=(P[i]*num+st)%10;
	}

	return ;
}

void printArray(int P[])
{
	int i=MaxSize-1;
	
	while(!P[i])
	{
		i--;
	}
	
	while(i>=0)
	{
		printf("%d",P[i]);
		i--;
	}
	
	printf("\n");
	
	return ;
}

main()
{
	int A[MaxSize],n;
	int i;
	
	//数组清零且个位初始化为1 
	memset(A,0,MaxSize*sizeof(int)); 
	A[0]=1;

	scanf("%d",&n);
	//用i依次乘以数组A 
	for(i=2;i<=n;i++)
	{
		resultProduct(A,i);
	}
	
	printArray(A);
	printf("\n");
	return 0;
}

