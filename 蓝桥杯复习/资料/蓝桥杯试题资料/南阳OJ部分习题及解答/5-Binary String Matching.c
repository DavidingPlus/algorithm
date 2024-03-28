/*
描述
Given two strings A and B, whose alphabet consist only ‘0’ and ‘1’. Your task is only to tell how many times does A appear as a substring of B? For example, the text string B is ‘1001110110’ while the pattern string A is ‘11’, you should output 3, because the pattern A appeared at the posit
输入
The first line consist only one integer N, indicates N cases follows. In each case, there are two lines, the first line gives the string A, length (A) <= 10, and the second line gives the string B, length (B) <= 1000. And it is guaranteed that B is always longer than A.
输出
For each case, output a single line consist a single integer, tells how many times do B appears as a substring of A.
样例输入
3
11
1001110110
101
110010010010001
1010
110100010101011 
样例输出
3
0
3 
*/
#include <stdio.h>
#include <string.h>

main()
{
	int n;
	char str1[1001],str2[11];
	int i,j;
	
	scanf("%d",&n);
	
	while(n--)
	{
		int sum=0;
		//输入字符串 
		scanf("%s",str2);
		scanf("%s",str1);
		//字符串比较
		for(j=0;j<=strlen(str1)-strlen(str2);j++)
		{
			for(i=0;i<strlen(str2);i++)
			{
				if(str2[i]!=str1[i+j])
				{
					break;
				}
				if(i==strlen(str2)-1) 
				sum++;
			}
		}
		//输出字串个数
		printf("%d\n",sum);
	}
	
	return 0;
}
