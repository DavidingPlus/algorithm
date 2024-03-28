/*
描述
任意给出两个英文字母，比较它们的大小，规定26个英文字母A,B,C.....Z依次从大到小。

输入
第一行输入T，表示有T组数据；
接下来有T行，每行有两个字母，以空格隔开；
输出
输出各组数据的比较结果，输出格式见样例输出；
（注意输出严格按照输入的顺序即输入是A B，输出时必须是A?B）
样例输入
3
A B
D D
Z C
样例输出
A>B
D=D
Z<C
*/
#include <stdio.h>

main()
{
	int T;
	
	scanf("%d ",&T);
	while(T--)
	{
		char a,b;
		scanf("%c %c",&a,&b);
		if((int)(a-b)==0)
		printf("%c=%c\n",a,b);
		else if((int)(a-b)>0)
		printf("%c<%c\n",a,b);
		else
		printf("%c>%c\n",a,b);
		//去掉回车，防止存入a
		getchar();
	}
	
	return 0;
}
