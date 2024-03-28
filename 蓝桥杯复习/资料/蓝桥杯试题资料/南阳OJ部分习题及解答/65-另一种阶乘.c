#include <stdio.h>

main()
{
	int a,n;
	int i,j;
	int	product=1,sum=0;
	
	scanf("%d",&a);
	
	while(a--)
	{
		scanf("%d",&n);
		
		//计算1到n的和 
		for(i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				//偶数时，计算乘积 
				for(j=1;j<i;j+=2)
				{
					product*=j;
				}
			}
			else
			{
				//奇数时，计算乘积
				for(j=1;j<=i;j+=2)
				{
					product*=j;
				}
			}
			sum+=product;
			
			product=1; 
		}
		
		//输出和，并重新初始化数据 
		printf("%d\n",sum);
		sum=0;
	}
	
	return 0;
}
