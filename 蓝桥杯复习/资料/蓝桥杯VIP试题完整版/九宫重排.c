#include<stdio.h>
typedef struct Point
{
	int now[9];
    int x;
    int step;
}point;
	point init,goal;
	point T[400000];//点集合 
	int vis[400000];//记录访问过的点 
	int E[9]={1,1,2,6,24,120,720,5040,40320};
	int move[4][2] ={-1,0,1,0,0,-1,0,1};
	int start=0,end=0;
int main()
{
	int i;
	char a[10],b[10];
	scanf("%s%s",a,b);
   for(i=0;i<9;i++)
    {
        if(a[i]!='.')
           init.now[i]=a[i]-'0';//init.now 为当前的序列 
      else
       {
           init.now[i]=0;
         init.x=i;//记录"." 起点位置 
        }
       if(b[i]!='.')
            goal.now[i]=b[i]-'0';//goal.now 为当前的序列 
        else
           goal.now[i]=0;
    }
   init.step=0;
    bfs();
   return 0;
}

int cantor(int A[])//康拓展开
{
    int i,j,s=0,n;
    for(i=0;i<9;i++)
    {
        n=0;
        for(j=i+1;j<9;j++)
             if(A[i]>A[j])    
                 n++;
        s+=n*E[8-i];
     }
     return s+1;
}


int bfs()
{
    int t,g=cantor(goal.now);
    point p;
    p=init;//原序列赋值给P 
    T[end++]=p;//将p存在T[end]的位置 
    vis[cantor(init.now)]=1;//标记已访问 
   while(end-start>0)
   {
        p=T[start];
        if(cantor(p.now)==g)
        {
        	printf("%d",p.step);
            return;
        }
        int i,x,y,x0,y0;
        x=p.x/3,y=p.x%3;
        for(i=0;i<4;i++)//从该位置出发有四个节点 
        {
            x0=x+move[i][0];
           y0=y+move[i][1];
            if (x0<0||x0>2||y0<0||y0>2)
               continue;//结束该单次循环 
           point q=p;//q以p为起点 
           q.x=x0*3+y0;//到达"."新的位置 
           q.step++;
           q.now[p.x]=q.now[q.x];//将到达新位置的值放在原来"."的位置 
           q.now[q.x]=0;//并将"."到达新位置赋值为0 
            t=cantor(q.now); 
            if(!vis[t])
            {
               vis[t]=1;
    		   T[end++]=q;
            }
       }
       start++;
   }
    printf("-1");
}

