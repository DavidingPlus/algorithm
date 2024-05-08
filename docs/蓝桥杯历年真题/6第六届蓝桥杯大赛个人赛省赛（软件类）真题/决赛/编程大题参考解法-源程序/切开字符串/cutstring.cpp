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
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;
const int base=987654323;

int N,o;
char st[maxn];
int a[maxn],b[maxn];
int mark[maxn],temp[maxn],c[maxn],d[maxn],bb[maxn],c1[maxn],d1[maxn],over[maxn],biao[maxn],t[maxn];
int which[maxn],height[maxn],kuo[maxn],lou2[maxn],rank[maxn],sp[maxn],fp[maxn];
int r1[maxn][18],r2[maxn][18],r3[maxn][18];
PII ls[maxn],tq[maxn*10];
int e,p,u,v,tc,x1,x2,xc,yc,mj,ll,rr,xx,yy;
ULL hash1[maxn],hash2[maxn],powc[maxn],cc;
set<ULL> hwc;
set<ULL>::iterator ltk;
set<int> f;
set<int>::iterator jcb;

bool equal(int a,int b,int c)
{
    ULL k1=hash1[a+c-1]-hash1[a-1]*powc[c];
    ULL k2=hash2[b+c-1]-hash2[b-1]*powc[c];
    if (k1==k2) return true; else return false;
}

bool equal_2(int a,int b,int c)
{
    if ((a+c-1>N)||(b+c-1>N)) return false;
    ULL k1=hash1[a+c-1]-hash1[a-1]*powc[c];
    ULL k2=hash1[b+c-1]-hash1[b-1]*powc[c];
    if (k1==k2) return true; else return false;
}

int getmin_r1(int l,int r)
{
    int cc=lou2[r-l+1];
    return min(r1[l][cc],r1[r-(1<<cc)+1][cc]);
}

int getmin_r2(int l,int r)
{
    int cc=lou2[r-l+1];
    return min(r2[l][cc],r2[r-(1<<cc)+1][cc]);
}

int getmax_r3(int l,int r)
{
    int cc=lou2[r-l+1];
    return max(r3[l][cc],r3[r-(1<<cc)+1][cc]);
}

int main()
{

    scanf("%d",&N);
    scanf("%s",st);
    for (int i=1;i<=N;i++)
    {
        a[i]=st[i-1]-96;
        b[i]=st[N-i]-96;
    }
    // suffix array construction
    for (int i=1;i<=N;i++)
        temp[a[i]]=1;
    for (int i=1;i<=255;i++)
        if (temp[i]==1)
            temp[i]=temp[i-1]+1;
        else
            temp[i]=temp[i-1];
    for (int i=1;i<=N;i++) mark[i]=temp[a[i]];

    for (int i=1;i<=N;i++) c[i]=i;
    for (int i=1;i<=N;i++) ls[i]=m_p(mark[i],c[i]);
    sort(ls+1,ls+N+1);
    for (int i=1;i<=N;i++)
        mark[i]=ls[i].w1,c[i]=ls[i].w2;
    for (int i=1;i<=N;i++) d[c[i]]=i;

    e=1;
    while (e<=N)
    {
        memset(biao,0,sizeof(biao));
        over[N]=N;
        for (int i=N-1;i>=1;i--)
            if (mark[i]!=mark[i+1]) over[i]=i; else over[i]=over[i+1];
        for (int i=N;i>=1;i--)
        {
            p=c[i];
            if (p<=e) continue;
            p=d[p-e];
            u=over[p];
            v=u-biao[u];
            c1[v]=c[i]-e;
            d1[c[i]-e]=v;
            bb[v]=mark[i];
            biao[u]++;
        }
        for (int i=N+1;i<=N+e;i++)
        {
            p=d[i-e];
            u=over[p];
            v=u-biao[u];
            c1[v]=c[p];
            d1[c[p]]=v;
            bb[v]=0;
            biao[u]++;
        }
        for (int i=1;i<=N;i++) c[i]=c1[i],d[i]=d1[i];
        t[0]=0;
        for (int i=1;i<=N;i++)
            if ((mark[i]==mark[i-1])&&(bb[i]==bb[i-1]))
                t[i]=t[i-1];
            else
                t[i]=t[i-1]+1;
        for (int i=1;i<=N;i++) mark[i]=t[i];
        if (mark[N]==N) break;
        e*=2;
    }
    for (int i=1;i<=N;i++) which[mark[d[i]]]=i;
    for (int i=1;i<=N;i++) rank[which[i]]=i;
    /*for (int i=1;i<=N;i++)
    {
        for (int j=which[i];j<=N;j++) cout<<st[j-1];
        cout<<endl;
    }*/
    height[0]=1;
    for (int i=1;i<=N;i++)
    {
        tc=d[i];
        height[tc]=height[d[i-1]]-1;
        if (height[tc]<0) height[tc]=0;
        x1=i,x2=which[d[i]-1];
        while (a[x1+height[tc]]==a[x2+height[tc]]) ++height[tc];
    }
    //for (int i=1;i<=N;i++) cout<<height[i]<<endl;

    //hash array construction
    hash1[0]=0;
    for (int i=1;i<=N;i++) hash1[i]=hash1[i-1]*base+a[i];
    hash2[0]=0;
    for (int i=1;i<=N;i++) hash2[i]=hash2[i-1]*base+b[i];
    powc[0]=1;
    for (int i=1;i<=N;i++) powc[i]=powc[i-1]*base;

    //Manacher-in-hash
    int left,right,mid;
    for (int i=1;i<=N;i++)
    {
        left=0;right=min(i-1,N-i);
        while (left<=right)
        {
            mid=(left+right)/2;
            if (equal(i-mid,N+1-i-mid,mid*2+1)) left=mid+1; else right=mid-1;
        }
        kuo[i]=right;
    }
    //for (int i=1;i<=N;i++) cout<<kuo[i]<<endl;

    //two rmq constructions
    for (int i=N;i>=1;i--)
    {
        r1[i][0]=which[i];
        r2[i][0]=height[i];
        r3[i][0]=which[i];
        for (int j=1;j<=17;j++)
            r1[i][j]=min(r1[i][j-1],r1[i+(1<<(j-1))][j-1]),
            r2[i][j]=min(r2[i][j-1],r2[i+(1<<(j-1))][j-1]),
            r3[i][j]=max(r3[i][j-1],r3[i+(1<<(j-1))][j-1]);
    }
    lou2[1]=0;
    for (int i=2;i<=N;i++) lou2[i]=lou2[i/2]+1;

    o=0;
    for (int i=1;i<=N;i++)
    {
        for (int j=kuo[i];j>=0;j--)
        {
            xc=i-j;
            yc=i+j;
            cc=hash1[yc]-hash1[xc-1]*powc[yc-xc+1];
            ltk=hwc.l_b(cc);
            if ((*ltk)==cc) break;
            ++o,tq[o]=m_p(xc,yc);
            hwc.insert(cc);
        }
    }

    //first part
    memset(fp,0,sizeof(fp));
    memset(sp,0,sizeof(sp));
    for (int i=1;i<=o;i++)
    {
        xc=tq[i].w1,yc=tq[i].w2;
        mj=rank[xc];
        int left=1,right=mj,mid;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (equal_2(which[mid],xc,yc-xc+1)) right=mid-1; else left=mid+1;
        }
        ll=left;
        left=mj,right=N;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (equal_2(which[mid],xc,yc-xc+1)) left=mid+1; else right=mid-1;
        }
        rr=right;
        fp[getmin_r1(ll,rr)+(yc-xc)]++;
        sp[getmax_r3(ll,rr)]++;
    }
    for (int i=1;i<=N;i++) fp[i]=fp[i-1]+fp[i];
    for (int i=N;i>=1;i--) sp[i]=sp[i+1]+sp[i];

    LL ans=0,tdk=0,Q;
    //second part
    for (int i=N;i>=2;i--)
    {
        f.insert(rank[i]);
        jcb=f.l_b(rank[i]);
        if (jcb==f.begin()) xx=-1; else --jcb,xx=(*jcb),++jcb;
        ++jcb;
        if (jcb==f.end()) yy=-1; else yy=(*jcb);
        --jcb;
        if ((xx!=-1)&&(yy!=-1))
            tdk=tdk-getmin_r2(xx+1,yy)+getmin_r2(xx+1,rank[i])+getmin_r2(rank[i]+1,yy);
        else
        {
            if (yy!=-1)
                tdk+=getmin_r2(rank[i]+1,yy);
            else
                tdk+=getmin_r2(xx+1,rank[i]);
        }
        //cout<<tdk<<" "<<rank[i]<<endl;
        Q=(LL)(N-i+1)*(N-i+2)/2;
        ans=max(ans,(LL)fp[i-1]*(Q-tdk-sp[i]));
        //cout<<i<<" "<<fp[i-1]<<" "<<Q-tdk-sp[i]<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
