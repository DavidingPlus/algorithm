#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

struct tree
{
    tree *lchild,*rchild;
    int left,right,max;
} *root[250005],ncc[10000005];

int x[maxn*10],y[maxn*10],z[maxn*10];
int depth[maxn],mulfa[maxn][18],mulmax[maxn][18],bfa[maxn],h[maxn],gg[maxn];
vector<PII> f[maxn];
PIII ls[maxn*10];
int N,M,Q,xc,yc,uu,uc;
int L,R,K,C,o,ans,cs1,cs2,cs3,qqq=0;
int ga,ct,cn;

void dfs(int s,int fa,int fas)
{
    depth[s]=depth[fa]+1;
    mulfa[s][0]=fa;
    for (int i=1;i<=17;i++)
        mulfa[s][i]=mulfa[mulfa[s][i-1]][i-1];
    mulmax[s][0]=fas;
    for (int i=1;i<=17;i++)
        mulmax[s][i]=max(mulmax[s][i-1],mulmax[mulfa[s][i-1]][i-1]);
    for (int i=0;i<f[s].size();i++)
        if (f[s][i].w1!=fa) dfs(f[s][i].w1,s,f[s][i].w2);
}

int LCA(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=17;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y]) x=mulfa[x][i];
    if (x==y) return x;
    for (int i=17;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

int getmax(int x,int s)
{
    int ans=0;
    for (int i=17;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[s])
            ans=max(ans,mulmax[x][i]),
            x=mulfa[x][i];
    return ans;
}

int getans(int x,int y)
{
    int c=LCA(x,y);
    return max(getmax(x,c),getmax(y,c));
}

void maketree(tree *&node,int left,int right)
{
    ++qqq;
    tree *p=&ncc[qqq];
    p->lchild=p->rchild=0;
    p->left=left,p->right=right;
    p->max=0;
    node=p;
    if (left==right) p->max=getans(gg[left],gg[left+1]); else
    {
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
        p->max=max(p->lchild->max,p->rchild->max);
    }
}

int getmax(tree *p,int l,int r)
{
    if (l>r) return -1;
    int ll=p->left,rr=p->right;
    if ((ll==l)&&(rr==r)) return p->max;
    return max(getmax(p->lchild,l,min(r,p->lchild->right)),
               getmax(p->rchild,max(p->rchild->left,l),r));
}

int main()
{
//    freopen("construct.in","r",stdin);
//    freopen("construct.out","w",stdout);

    scanf("%d %d %d",&N,&M,&Q);
    for (int i=1;i<=M;i++)
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
    for (int i=1;i<=M;i++)
        ls[i]=m_p(z[i],m_p(x[i],y[i]));
    sort(ls+1,ls+M+1);
    for (int i=1;i<=M;i++)
        x[i]=ls[i].w2.w1,
        y[i]=ls[i].w2.w2,
        z[i]=ls[i].w1;

    //Construct MST
    for (int i=1;i<=N;i++) bfa[i]=i;
    int cnt=0;
    for (int i=1;i<=M;i++)
    {
        xc=x[i],yc=y[i];
        while (bfa[xc]!=xc) xc=bfa[xc];
        while (bfa[yc]!=yc) yc=bfa[yc];
        if (xc!=yc)
        {
            ++cnt;
            f[x[i]].p_b(m_p(y[i],z[i]));
            f[y[i]].p_b(m_p(x[i],z[i]));
            bfa[xc]=yc;
            uu=x[i];
            while (uu!=yc)
            {
                uc=bfa[uu];
                bfa[uu]=yc;
                uu=uc;
            }
            uu=y[i];
            while (uu!=yc)
            {
                uc=bfa[uu];
                bfa[uu]=yc;
                uu=uc;
            }
        }
    }

    //LCA;multi
    memset(mulfa,0,sizeof(mulfa));
    memset(mulmax,0,sizeof(mulmax));
    memset(depth,0,sizeof(depth));
    dfs(1,0,0);

    if (cnt!=N-1) return 0;

    ga=min(70,N/3);
    ct=0;
    for (int i=1;i<=ga;i++)
        for (int j=0;j<i;j++)
        {
            ++ct;
            cn=0;
            for (int k=0;k<=(N-j)/i;k++)
                ++cn,gg[cn]=k*i+j;
            maketree(root[ct],1,cn-1);
        }

    for (int i=1;i<=Q;i++)
    {
        scanf("%d %d %d %d",&L,&R,&K,&C);
        if (K>ga)
        {
            int fff=L-L%K+C;
            if (fff<L) fff+=K;
            o=0;
            for (int j=fff;j<=R;j+=K)
                ++o,h[o]=j;
            ans=0;
            for (int j=1;j<o;j++)
                ans=max(ans,getans(h[j],h[j+1]));
            printf("%d\n",ans);
        }
        else
        {
            cs1=(K*(K-1)/2)+C+1;
            if (L-1-C<0) cs2=1; else cs2=(L-1-C)/K+2;
            cs3=(R-C)/K+1;
            printf("%d\n",getmax(root[cs1],cs2,cs3-1));
        }
    }

    return 0;
}
