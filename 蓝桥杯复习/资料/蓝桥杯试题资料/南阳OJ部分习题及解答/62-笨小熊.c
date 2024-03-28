/*
描述
笨小熊的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！ 
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小熊就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

输入
第一行数据N(0<N<100)表示测试数据组数。
每组测试数据输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
输出
每组测试数据输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”； 
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0
样例输入
2
error
olympic
样例输出
Lucky Word
2
No Answer
0
*/
#include <stdio.h>
#include <string.h>

int permit(int num)
{
	int i;
	if(num<=1)
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
	int N;
	
	scanf("%d",&N);
	
	while(N--)
	{
		char str[100];
		int num[100]={0},maxn,minn;
		int i=1,j=0,k=1;
		num[0]=1;
		
		scanf("%s",str);
		//查找最多字母与最少字母的个数分别存入maxn和minn 
		while(i<strlen(str))
		{
			int st=0;
			int sl;//9999
			for(j=0;j<k;j++)
			{
				if(str[i]==str[j])
				{
					num[j]++;
					st=1;
					break;
				}
			}
			if(st==0)
				{
					str[k]=str[i];
					num[k]=1;
					k++;
				}
			i++;
		}
		minn=maxn=num[0];
		for(i=0;i<k;i++)
		{
			if(num[i]>maxn)
			maxn=num[i];
			if(num[i]<minn)
			minn=num[i];
		}
		
		if(permit(maxn-minn))
		{
			printf("Lucky Word\n%d\n",maxn-minn);
		}
		else
		{
			printf("No Answer\n0\n");
		}
	}
	
	return 0;
}
/*
		for(i=0;i<k;i++)
		{
			printf("%c\n",str[i]);
			printf("%d\n",num[i]);
		}
*/
