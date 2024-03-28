/*
描述
we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
Give you a letter x and a number y , you should output the result of y+f(x).
输入
On the first line, contains a number T(0<T<=10000).then T lines follow, each line is a case.each case contains a letter x and a number y(0<=y<1000).
输出
for each case, you should the result of y+f(x) on a line
样例输入
6
R 1
P 2
G 3
r 1
p 2
g 3
样例输出
19
18
10
-17
-14
-4
*/
#include <stdio.h>

main()
{
	int T;
	
	scanf("%d ",&T);
	while(T--)
	{
		char x;
		int y;
		
		scanf("%c %d",&x,&y);
		if(x<='Z'&&x>='A')
		printf("%d\n",x-'A'+1+y);
		if(x<='z'&&x>='a')
		printf("%d\n",y-1-x+'a');
		
		getchar();
	}
	
	return 0;
}
