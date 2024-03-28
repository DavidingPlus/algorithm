/*
描述
有n盏灯，编号为1~n，第1个人把所有灯打开，第2个人按下所有编号为2 的倍数的开关（这些灯将被关掉），第3 个人按下所有编号为3的倍数的开关（其中关掉的灯将被打开，开着的灯将被关闭），依此类推。一共有k个人，问最后有哪些灯开着？输入：n和k，输出开着的灯编号。k≤n≤1000
输入
输入一组数据：n和k
输出
输出开着的灯编号
样例输入
7 3
样例输出
1 5 6 7
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

main()
{
	int *lamp,n,k;
	int i,j;
	
	scanf("%d%d",&n,&k);
	//动态申请n+1个int型的内存空间 
	lamp=(int *)malloc((n+1)*sizeof(int));
	//对该内存空间清零
	memset(lamp,0,n+1);
	for(i=1;i<k+1;i++)
	for(j=1;j<n+1;j++)
	{
		if(j%i==0)
		{
			lamp[j]=!lamp[j];
		}
	}
	for(i=1;i<n+1;i++)
	{
		if(lamp[i]==1)
		{
			printf("%d ",i);
		}
	}
	free(lamp);
	printf("\n");
	
	return 0;
}
