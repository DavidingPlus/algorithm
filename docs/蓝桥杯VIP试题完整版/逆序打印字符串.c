#include "stdio.h"
#include "string.h"
int main(void){
	char str[100];
	scanf("%[^\n]",str);
	f(str);
	printf("%s",str);
	return 0;	
}
int f(char s[])
{
	int i,n;
	char temp;
	n = strlen(s);
	if(n % 2 == 0)
	{
		for(i = 0;i < n/2;i++){
			temp = s[i];
			s[i] = s[n-1-i];
			s[n-1-i] = temp;
		}
	}
	else{
		for(i = 0;i < (n-1)/2;i++){
			temp = s[i];
			s[i] = s[n-1-i];
			s[n-1-i] = temp;
		}
	}	
}
