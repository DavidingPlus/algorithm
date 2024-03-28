#include <stdio.h>
#include <string.h>
#define MaxTime 200

main()
{
	int T;
	
	scanf("%d",&T);
	while(T--)
	{
		int date[MaxTime],day=0;
		int N,a,b,c;
		int i;
		
		memset(date,0,sizeof(date));
		scanf("%d",&N);
		while(N--)
		{
			scanf("%d%d%d",&a,&b,&c);
			//住宿期间每天需要的房间数 
			for(i=b-1;i<b+c-1;i++)
			{
				date[i]+=a;
			}
		}
		
		//找出所有天数中最大房间数 
		for(i=0;i<MaxTime;i++)
		if(date[i]>day)
		day=date[i];
		
		printf("%d\n",day);
	}
	
	return 0;
}
