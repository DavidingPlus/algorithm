/*
描述
现在，有一行括号序列，请你检查这行括号是否配对。
输入
第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），
测试数据组数少于5组。数据保证S中只含有"[","]","(",")"四种字符
输出
每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No
样例输入
3
[(])
(])
([[]()])
样例输出
No
No
Yes
Yes
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
	
main()
{

	int i,n;
	int st=0,sp=0;
	int num[100]={0};

	scanf("%d",&n);
	
	loop:
	while(n--)
	{
		char* str = (char *)malloc(10005);
		//初始化所有数据
		st=0;
		sp=0; 
		
		scanf("%s",str);		
		//字符串长度为奇数肯定不能对称 
		if(strlen(str)%2!=0)
		{
			printf("No\n");
			continue;
		}
		
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='(')
			st+=1;
			if(str[i]==')')
			st-=1;
			if(str[i]=='[')
			sp+=1;
			if(str[i]==']')
			sp-=1;
		
//			printf("%d %d\n",st,sp);
			
			if(sp<0||st<0||(str[i]=='('&&str[i+1]==']')||(str[i]=='['&&str[i+1]==')'))
			{
				printf("No\n");
				goto loop;
			}
		}
		printf("Yes\n");
		
		free(str);
	}
	
	return 0;
}

