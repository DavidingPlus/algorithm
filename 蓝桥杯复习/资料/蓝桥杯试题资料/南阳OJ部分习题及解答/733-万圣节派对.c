#include <stdio.h>
#include <stdlib.h>

main()
{
	int n;

	scanf("%d",&n);
	while(n--)
	{
		int x,y;
		int i,a,b,c,d,e,f;
		
		scanf("%d%d",&x,&y);
		for(i=x;i<=y;i++)
		{
			a=i%10;
			b=i/10%10;
			c=i/100%10;
			d=i/1000%10;
			e=i/10000%10;
			f=i/100000;
			if(a>6||b>6||c>6||d>6||e>6||f>6)
			continue;
			if((a==b&&b==c)||(b==c&&c==d)||(c==d&&d==e)||(d==e&&e==f))
			continue;
			if(abs(a-b)>4||abs(b-c)>4||abs(c-d)>4||abs(d-e)>4||abs(e-f)>4)
			continue;
			printf("%06d\n",i);
		}
		printf("\n");
	}
	
	return 0;
}