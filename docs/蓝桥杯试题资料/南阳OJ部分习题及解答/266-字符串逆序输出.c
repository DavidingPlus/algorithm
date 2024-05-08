/*
描述
给定一行字符，逆序输出此行（空格.数字不输出）
输入
第一行是一个整数N(N<10)表示测试数据的组数）
每组测试数据占一行，每行数据中间有且只有一个空格（这样你可以把此行当成两个字符串读取）。
每行字符长度不超过40
并且保证输入的字符只有空格（1个），数字，小写字母三种
输出
对应每行测试数据，逆序输出（空格和数字不输出）
样例输入
3
abc 123de
abc 123
abc d
样例输出
edcba
cba
dcba
*/
#include <stdio.h>
#include <string.h>

main()
{
	int N;
	
	scanf("%d ",&N);
	while(N--)
	{
		char str[40],ch;
		int i=0;
		
		while((ch=getchar())!='\n')
		{
			if(ch>='a'&&ch<='z')
			{
				str[i++]=ch;
			}
		}
		for(i=i-1;i>=0;i--)
		{
			printf("%c",str[i]);
		}
		printf("\n");
	}
	
	return 0;
} 
