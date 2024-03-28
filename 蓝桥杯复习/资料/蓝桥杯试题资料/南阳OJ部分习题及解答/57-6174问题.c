/*
描述
假设你有一个各位数字互不相同的四位数，把所有的数字从大到小排序后得到a,从小到大后得到b,然后用a-b替换原来这个数，并且继续操作。例如，从1234出发，依次可以得到4321-1234=3087、8730-378=8352、8532-2358=6174，又回到了它自己！现在要你写一个程序来判断一个四位数经过多少次这样的操作能出现循环，并且求出操作的次数

比如输入1234执行顺序是1234->3087->8352->6174->6174,输出是4

输入
第一行输入n,代表有n组测试数据。
接下来n行每行都写一个各位数字互不相同的四位数
输出
经过多少次上面描述的操作才能出现循环
样例输入
1
1234
样例输出
4
*/
#include <stdio.h>

//产生新的黑洞数 
int BlackHole(int num)
{
	int a[4]={0},temp,i,j;
	a[0]=num%10;
	a[1]=num/10%10;
	a[2]=num/100%10;
	a[3]=num/1000;
	for(i=0;i<3;i++)
	for(j=i+1;j<4;j++)
	{
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	
	return (a[3]*1000+a[2]*100+a[1]*10+a[0])-(a[0]*1000+a[1]*100+a[2]*10+a[3]);
}

//判断是否进入循环 
int is_equal(int num[],int temp,int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		if(temp==num[j])
		return 1;
	}
	
	return 0;
}
main()
{
	int n;
	scanf("%d",&n);
	 
	while(n--)
	{
		int num[10]={0};
		int temp,i=0;
		scanf("%d",&num[0]);
		temp=num[0];
		do
		{
			num[i]=temp;
			temp=BlackHole(temp);
			i++;
		}
		while(!is_equal(num,temp,i));
		
		printf("%d\n",i);
	}
	
	return 0;
}
