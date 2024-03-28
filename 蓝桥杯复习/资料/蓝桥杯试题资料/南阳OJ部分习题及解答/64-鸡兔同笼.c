/*
描述
已知鸡和兔的总数量为n,总腿数为m。输入n和m,依次输出鸡和兔的数目，如果无解，则输出“No answer”(不要引号)。
输入
第一行输入一个数据a,代表接下来共有几组数据，在接下来的(a<10)
a行里，每行都有一个n和m.(0<m,n<100)
输出
输出鸡兔的个数，或者No answer
样例输入
2
14 32
10 16
样例输出
12 2
No answer
*/
#include <stdio.h>

main()
{
	int a;
	
	scanf("%d",&a);
	while(a--)
	{
		int m,n;
		int i,temp=0;
		
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			if(i*4+(n-i)*2==m)
			{
				printf("%d %d\n",n-i,i);
				temp=1;
			}
		}
		if(temp==0)
		printf("No answer\n");
	}
	
	return 0;
}
