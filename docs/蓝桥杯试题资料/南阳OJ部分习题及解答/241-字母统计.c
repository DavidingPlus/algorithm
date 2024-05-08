/*
描述
现在给你一个由小写字母组成字符串，要你找出字符串中出现次数最多的字母，如果出现次数最多字母有多个那么输出最小的那个。
输入
第一行输入一个正整数T（0<T<25）
随后T行输入一个字符串s,s长度小于1010。
输出
每组数据输出占一行，输出出现次数最多的字符；
样例输入
3
abcd
bbaa
jsdhfjkshdfjksahdfjkhsajkf
样例输出
a
a
j
*/
#include <stdio.h>
#include <string.h>

main()
{
	int T;
	
	scanf("%d",&T);
	while(T--)
	{
		char str[1015];
		int Letter_num[26]={0};
		int i,max=0,temp;
		
		scanf("%s",str);
		for(i=0;i<strlen(str);i++)
		{
			Letter_num[str[i]-97]++;
		}
		for(i=0;i<26;i++)
		{
			if(Letter_num[i]>max)
			{
				max=Letter_num[i];
				temp=i;
			}
		}
		printf("%c\n",97+temp);
	}
	
	return 0;
}
