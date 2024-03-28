/*
描述
茵茵很喜欢研究车牌号码，从车牌号码上可以看出号码注册的早晚，据研究发现，车牌号码是按字典序发放的，现在她收集了很多车牌号码，请你设计程序帮她判断注册较早的号码。车牌号码由5个字母或数字组成
输入
第一行是n，代表有n组数据，第二行是m，以下m行是m个车牌号码
其中n<100,m<1000
输出
输出注册较早的车牌号
样例输入
1
4
AA100
aa100
0o2r4
ye2er
样例输出
0o2r4
*/
#include <stdio.h>
#include <string.h>

main()
{
	int n;

	scanf("%d",&n);
	while(n--)
	{
		int m,i=1;
		char temp[6],str[6];
		
		scanf("%d",&m);
		while(m--)
		{
			if(i)
			{
				scanf("%s",temp);
				strcpy(str,temp);
				i--;
			}
			else
			{
				scanf("%s",str);
				if(strcmp(temp,str)>0)
				strcpy(temp,str);
			}		
		}
		printf("%s\n",temp);
	}
	
	return 0;
} 
