#include <stdio.h>
char ch(int m)
{
	if(m == 0)
		return 'Z';
	if( m == 1)
	    return 'A';
	if( m == 2)
	    return 'B';
	if( m == 3)
	    return 'C';
	if( m == 4)
	    return 'D';
	if( m == 5)
	    return 'E';
	if( m == 6)
	    return 'F';
	if( m == 7)
	    return 'G';
	if( m == 8)
	    return 'H';
	if( m == 9)
	    return 'I';
	if( m == 10)
	    return 'J';
	if( m == 11)
	    return 'K';
	if( m == 12)
	    return 'L';
	if( m == 13)
	    return 'M';
	if( m == 14)
	    return 'N';
	if( m == 15)
	    return 'O';
	if( m == 16)
	    return 'P';
	if( m == 17)
	    return 'Q';
	if( m == 18)
	    return 'R';
	if( m == 19)
	    return 'S';
	if( m == 20)
	    return 'T';
	if( m == 21)
	    return 'U';
	if( m == 22)
	    return 'V';
	if( m == 23)
	    return 'W';
	if( m == 24)
	    return 'X';
	if( m == 25)
	    return 'Y';
}
int main()
{
	int n;
	scanf("%d",&n);
	int a = 1,l = 0,j;
	while (n > a)
	{
		a*=26;
		l++; 
	}
	int b[10] = {0};
	int p,q = 1,w;
	for(j = 0;j < l;j++)
	{
		p = n % 26;
		b[j] = p;
		if(p == 0)
			w = 26;
		if(p != 0)
			w = p;
		n = (n-w)/26;//¹Ø¼ü 
	}
	int k,t;
	for(k = l-1;k >= 0 ;k--)
	{
		t = b[k];
		printf("%c",ch(t));
	}
	return 0; 	
 } 
