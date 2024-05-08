/*
描述
      现在给出了一个只包含大小写字母的字符串，不含空格和换行，要求把其中的大写换成小写，小写换成大写，然后输出互换后的字符串。
输入
第一行只有一个整数m（m<=10),表示测试数据组数。
接下来的m行，每行有一个字符串（长度不超过100）。
输出
输出互换后的字符串，每组输出占一行。
样例输入
2
Acm
ACCEPTED
样例输出
aCM
accepted
*/
#include <stdio.h>
#include <string.h>

main()
{
	int m;
	
	scanf("%d",&m);
	while(m--)
	{
		char str[100];
		int i;
		
		scanf("%s",str);
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			printf("%c",str[i]-32);
			else
			printf("%c",str[i]+32);
		}
		printf("\n");
	} 
		
	return 0;
}
