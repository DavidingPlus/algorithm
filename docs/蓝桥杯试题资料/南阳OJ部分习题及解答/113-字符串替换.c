/*
描述
编写一个程序实现将字符串中的所有"you"替换成"we"
输入
输入包含多行数据 

每行数据是一个字符串，长度不超过1000 
数据以EOF结束
输出
对于输入的每一行，输出替换后的字符串
样例输入
you are what you do
样例输出
we are what we do
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

main()
{
	char *p,c;
		
	while((c=getchar())!=EOF)
	{
		int i=0,j;
		
		p=(char *)malloc(1000*sizeof(char));
		p[0]=c;
		while(p[i]!='\n')
		{
			i++;
			p[i]=getchar();
		}

		for(j=0;p[j]!='\n';j++)
		{
			if(p[j]=='y'&&p[j+1]=='o'&&p[j+2]=='u')
			{
				printf("we");
				j=j+2;
			}
			else
			{
				printf("%c",p[j]);
			}
		}
		printf("\n");
		
		free(p);
	}
	
	return 0;
}
