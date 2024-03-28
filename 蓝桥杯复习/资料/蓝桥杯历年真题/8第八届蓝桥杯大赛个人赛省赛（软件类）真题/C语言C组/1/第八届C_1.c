#include <stdio.h>
#include <string.h>
int main(void)
{
	char A[1000];
	int i,n;
	fgets(A,sizeof(A),stdin);
	n = strlen(A);
	int l = 0;
	for (i = 0;i < n;i++)
	{
		if(A[i] == '#') 
			l+=1;	
		if(A[i] == '@') 
			l+=2;
	}
	printf("%d",l+2);
	return 0;
 } 
