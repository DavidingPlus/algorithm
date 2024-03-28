/*
描述
国王有一个魔镜，可以把任何接触镜面的东西变成原来的两倍——只是，因为是镜子嘛，增加的那部分是反的。
比如一条项链，我们用AB来表示，不同的字母表示不同颜色的珍珠。如果把B端接触镜面的话，魔镜会把这条项链变为ABBA。如果再用一端接触的话，则会变成ABBAABBA（假定国王只用项链的某一端接触魔镜）。

给定最终的项链，请编写程序输出国王没使用魔镜之前，最初的项链可能的最小长度。

输入
第一行是一个整数N(N<=10)表示测试数据的组数）
每组测试数据占一行 只有一个字符串（长度小于100），由大写英文字母组成，表示最终的项链。
输出
每组测试数据的输出只有一个整数，表示国王没使用魔镜前，最初的项链可能的最小长度。
样例输入
2
ABBAABBA
A
样例输出
2
1
*/
#include <stdio.h>
#include <string.h>

void f(char str[],int lenth)
{
	char str1[100];
	int i;
	
	//出口一 
	if(lenth%2!=0)
	{
		printf("%d\n",lenth);
		return ;
	}
	
	//递归部分 
	for(i=0;i<lenth/2;i++)
	{
		str1[i]=str[i];
		//出口二 
		if(str[i]!=str[lenth-i-1])
		{
			printf("%d\n",lenth);
			return ;
		}
	}
	str1[i]='\0';
	f(str1,strlen(str1));
}

main()
{
	int N;
	
	scanf("%d",&N);
	while(N--)
	{
		char str[100];
		int i,j;
		
		scanf("%s",str);
		f(str,strlen(str));
	}
	
	return 0;
}
