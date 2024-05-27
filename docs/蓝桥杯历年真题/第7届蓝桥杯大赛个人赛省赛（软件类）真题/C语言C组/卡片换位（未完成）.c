#include <stdio.h>
#include <string.h>
int step = 0;
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};
typedef struct Point{
	int x;
	int now[6];
	int step;
}Point;
int bfs(int s[],int p,int q)
{
	if(s[p] == 2 && s[q] == 1){
		printf("%d",step);
		return; 
	}
	Point w;
	int i;
	for(i = 0;i < 6;i++){
		if(s[i] == 6){
			w.x = i/3;
			w.y = i%3;			
		}
	}
	int x0,y0,j;
	for(j = 0; j < 4;j++){
		x0 = w.x+x[j];
		y0 = w.y+y[j];
		if(x0 < 0 || x0 > 1 || y0 < 0 || y0 > 2) continue;
}

int main()
{
	char s[7];
	char s1[4];
	gets(s);
	gets(s1);
	strcat(s,s1);
	int i,a[6],l = 3,p,q;
	for(i = 0;i < 6;i++){
		if(s[i] == 'A'){
			a[i] = 1;
			p = i;
		}
		if(s[i] == 'B'){
			a[i] = 2;
			q =i;
		}
		if(s[i] == ' ')
			a[i] = 6;
		if(s[i] == '*')
			a[i] = l++;
	}
	bfs(a,p,q);
	return 0;	
} 
