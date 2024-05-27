#include<stdio.h>  
   
int main()  
{  
	double s = 0;
	int i;
	for(i = 1;s <= 15;i++){
		s+=(double)1/i;
		if(s >= 15)
			printf("%d %7f\n",i,s);
	}
	//printf("%d %7f\n",i-1,s);如果是这样打印则i需要减 1 
    return 0;  
} 
