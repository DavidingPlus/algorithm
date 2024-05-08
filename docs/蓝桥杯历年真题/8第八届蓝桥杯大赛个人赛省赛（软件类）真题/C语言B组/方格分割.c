#include<stdio.h>  
typedef struct Point  
{  
    int x;  
    int y;  
}Point;  
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};  
int used[7][7];  
int count=0;  
void dfs(Point p1,Point p2)  
{  
    if(p1.x==0 || p1.y==6 || p1.y==0 || p1.x==6)  
    {  
        count++;  
        return ;  
    }  
    int i;  
    Point pp1,pp2;  
    for(i=0;i<4;i++)  
    {  
        pp1.x=p1.x+x[i];  
        pp1.y=p1.y+y[i];  
        pp2.x=p2.x-x[i];  
        pp2.y=p2.y-y[i];  
        if(used[pp1.x][pp1.y]!=1)  
        {  
            used[pp1.x][pp1.y]=1;  
            used[pp2.x][pp2.y]=1;  
            dfs(pp1,pp2);  
            used[pp1.x][pp1.y]=0;  
            used[pp2.x][pp2.y]=0;  
        }  
    }  
}  
int main()  
{  
    Point p;  
    p.x=3;  
    p.y=3;  
    used[3][3]=1;  
    dfs(p,p);  
    printf("%d\n",count/4);  
    return 0;  
}  
