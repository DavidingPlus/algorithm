#include "stdio.h"
#include "string.h"
int f(char s[],int l) // 当前的层数，以及当前考虑待排序的起点 
{
	int i;
	char t;
	if(l == strlen(s)-1){
		printf("%s\n",s);
		return; 
	}
	for(i = l;i < strlen(s);i++)
	{
		{t = s[l];s[l] = s[i];s[i] = t;}
		f(s,l+1);
		{t = s[l];s[l] = s[i];s[i] = t;}	
	}
}
int main(void)
{
	char s[]="123456789"; 
	f(s,0);
	return 0;
}
