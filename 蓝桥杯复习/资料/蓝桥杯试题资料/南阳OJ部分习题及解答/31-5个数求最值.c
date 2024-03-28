/*
描述
设计一个从5个整数中取最小数和最大数的程序
输入
输入只有一组测试数据，为五个不大于1万的正整数
输出
输出两个数，第一个为这五个数中的最小值，第二个为这五个数中的最大值，两个数字以空格格开。
样例输入
1 2 3 4 5
样例输出
1 5
*/

#include <stdio.h>

main()
{
	int min,max;
	int i,temp;
	
	scanf("%d",&min);
	max=min;
	
	for(i=0;i<4;i++)
	{
		scanf("%d",&temp);
		if(temp<min)
		min=temp;
		if(temp>max)
		max=temp;
	}
	
	printf("%d %d",min,max);
	
	return 0;
}
