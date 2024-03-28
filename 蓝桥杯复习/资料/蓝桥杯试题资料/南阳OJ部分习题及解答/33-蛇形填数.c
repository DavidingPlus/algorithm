#include <stdio.h>
#include <string.h>
#define MaxSize 100

main()
{
	int a[MaxSize][MaxSize];
	int n,x,y,tot=0;
	
	scanf("%d",&n);
	
	memset(a,0,sizeof(a));
	tot=a[x=0][y=n-1]=1;
	while(tot<n*n)
	{
		while(x+1<n&&!a[x+1][y]) a[++x][y]=++tot;
		while(y-1>=0&&!a[x][y-1]) a[x][--y]=++tot;
		while(x-1>=0&&!a[x-1][y]) a[--x][y]=++tot;
		while(y+1<n&&!a[x][y+1]) a[x][++y]=++tot;
	}
	
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
		printf("%5d",a[x][y]);
		printf("\n");
	}
	
	return 0;
}
