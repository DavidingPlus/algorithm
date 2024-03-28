/*
描述
输入三个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这三个字符。
输入
第一行输入一个数N,表示有N组测试数据。后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
输出
对于每组输入数据，输出一行，字符中间用一个空格分开。
样例输入
3
qwe
asd
zxc
样例输出
e q w
a d s
c x z
*/
 
#include "stdio.h"

main()

{
	
char a,b,c,d;
	
int i;
	
scanf("%d",&i);
	
getchar();
	
while(i--)
	
{
		
scanf("%c%c%c",&a,&b,&c);
		
getchar();
		
if (a>b) {d=a;a=b;b=d;}
		
if (a>c) {d=a;a=c;c=d;}
		
if (b>c) {d=b;b=c;c=d;}
		
printf("%c %c %c\n",a,b,c);	
		
	
	
}


}
        