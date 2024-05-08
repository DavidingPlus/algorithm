#include "stdio.h"
#include "stdlib.h"
int main()
{
	char s[9];
	scanf("%s",s);
	int a1,a2,a3;
	a1 = (s[0]-'0')*10+(s[1]-'0');
	a2 = (s[3]-'0')*10+(s[4]-'0');
	a3 = (s[6]-'0')*10+(s[7]-'0');
	if(a1 <= 59)
	printf("200%d-0%d-0%d\n",a1,a2,a3);
	printf("200%d-0%d-0%d\n",a3,a2,a1);
	printf("200%d-0%d-0%d\n",a3,a1,a2);
	return 0;
}
