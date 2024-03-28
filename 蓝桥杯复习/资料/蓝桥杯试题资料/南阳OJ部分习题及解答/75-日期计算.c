/*
描述
如题，输入一个日期，格式如：2010 10 24 ，判断这一天是这一年中的第几天。
输入
第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每行的输入数据都是一个按题目要求格式输入的日期。
输出
每组输入数据的输出占一行，输出判断出的天数n
样例输入
3
2000 4 5
2001 5 4
2010 10 24
样例输出
96
124
297
*/
#include <stdio.h>

int getDayOfYear(int year, int month, int day)
{
		int days[2][12]={{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
		int flag=(year%4==0&&year%100!=0)||year%400==0?0:1;
		int sum=day;
		int i;
		
		for(i=0;i<month;i++)	
		{
			sum+=days[flag][i];
		}
				
		return sum;		
}

main()
{
	int N;
	
	scanf("%d",&N);
	while(N--)
	{
		int year,month,day;
		
		scanf("%d%d%d",&year,&month,&day);
		printf("%d\n",getDayOfYear(year,month-1,day));
	}
	
	return 0; 
}
