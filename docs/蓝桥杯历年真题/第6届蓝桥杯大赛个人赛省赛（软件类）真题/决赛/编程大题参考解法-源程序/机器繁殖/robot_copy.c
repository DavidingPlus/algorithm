
#include <stdio.h>
#include <math.h>
#include <string.h>

int test(int begin, int n, double sum0)
{
	double a = begin;
	double sum = a;
	int i;
	
	for(i=1; i<=n; i++){
		a = a * 2 - 1;
		sum = sum + a;
	}		
	
	return fabs(sum-sum0)/sum < 0.01;
}

int main()
{
	int a; //  after a years 
	double b;  // 	all number
	int i;  // begin number
	char buf[1000];
	int len; //number length in buf
	
	scanf("%d", &a);
	scanf("%s", buf);
	
	len = strlen(buf);
	
	if(len<10) 
		b = atoi(buf);
	else{
		buf[9] = 0;
		b =  atoi(buf) * pow(10,len-9);
	}
			
	for(i=1; i<100; i++) { 
		if(test(i,a,b)) {
			printf("%d\n",i); 
			break;
		}
	}	
	return 0;
}
