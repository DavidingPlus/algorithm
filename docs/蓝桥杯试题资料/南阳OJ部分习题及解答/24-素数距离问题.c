/*
描述 现在给出你一些数，要求你写出一个程序，输出这些整数相邻最近的素数，并输出其相距长度。如果左右有等距离长度素数，则输出左侧的值及相应距离。
 如果输入的整数本身就是素数，则输出该素数本身，距离输出0
输入第一行给出测试数据组数N(0<N<=10000)
接下来的N行每行有一个整数M(0<M<1000000)，输出每行输出两个整数 A B.
其中A表示离相应测试数据最近的素数，B表示其间的距离。样例输入3
6
8
10
样例输出5 1
7 1
11 1
*/

#include <stdio.h>

int is_permit(int num)
{
	int i;
	if(num>1)
	{
		for(i=2;i*i<num+1;i++)
		{
			if(num%i==0)
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

main()
{
	int n,m;
	int i;
	
	scanf("%d",&n);
	//n组测试数据 
	while(n--)
	{
		scanf("%d",&m);
		
		if(is_permit(m))
		{
			printf("%d 0\n",m);
		}
		else
		{
			for(i=1;;i++)
			{
				if(is_permit(m-i))
				{
					printf("%d %d\n",m-i,i);
					break;
				}
				if(is_permit(m+i))
				{
					printf("%d %d\n",m+i,i);
					break;
				}
			}
		}
	}
	
	return 0;
}
