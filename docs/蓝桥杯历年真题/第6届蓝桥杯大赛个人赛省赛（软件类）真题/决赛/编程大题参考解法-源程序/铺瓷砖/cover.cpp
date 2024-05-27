//´É×©ÆÌ·Å
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 65521;

const int MM = 800;
const int RSIZE = 128;

const int MATRIX_SIZE = 256;

class Matrix {
public:
	unsigned int s[MATRIX_SIZE][MATRIX_SIZE];
};

long long n;
int m, M;
int tt[MM][RSIZE], fr[MM][RSIZE];
int *cur[MM], *curFr[MM];
int tc[MM], nc[MM];
Matrix tm, dst, tmpm;
bool mark[MM], canReach[MM];
int remap[MM], who[MM];

void search(int cp, int cl, int nl)
{
	if (cp > m)
		return ;
	if (cp == m)
	{
		*(cur[cl]++) = nl;
		*(curFr[nl]++) = cl;
		return ;
	}
	search(cp+1, cl*3+1, nl*3);
	search(cp+1, cl*3+2, nl*3+1);

	// (1) 
	search(cp+2, cl*3*3+1, nl*3*3+3+1);
	search(cp+3, cl*3*3*3, nl*3*3*3+9+3+1);
	search(cp+4, cl*3*3*3*3, nl*3*3*3*3+27+9+3);
	// (2)
	search(cp+2, cl*3*3, nl*3*3+1);
	// (3)
	search(cp+2, cl*3*3, nl*3*3+3);
	// (4)
	if (cp>0 && nl%3==0)
		search(cp+1, cl*3, nl*3+3+1);
	// (5)
	search(cp+2, cl*3*3+1, nl*3*3+3*2+1);
	search(cp+3, cl*3*3*3, nl*3*3*3+9*2+3+1);
	search(cp+4, cl*3*3*3*3, nl*3*3*3*3+27*2+9+3);
	// (6)
	search(cp+3, cl*3*3*3, nl*3*3*3+3);
	// (7)
	if (cp>0 && nl%3==0)
		search(cp+1, cl*3, nl*3+3+2);
	// (8)
	if (cp>0 && nl%3==0)
	{
		search(cp+2, cl*3*3+1, nl*3*3+9+3+1);
		search(cp+3, cl*3*3*3, nl*3*3*3+27+9+3+1);
		search(cp+4, cl*3*3*3*3, nl*3*3*3*3+81+27*2+9+3);
	}
}
void goto0(int x)
{
	if (canReach[x])
		return ;
	canReach[x] = true;
	for (int *pp = fr[x]; pp < curFr[x]; ++pp)
		goto0(*pp);
}

int ccnt = 0;
void go(int x)
{
	if (!canReach[x])
		return ;
	if (mark[x])
		return ;
	who[ccnt] = x;
	remap[x] = ccnt++;
	mark[x] = true;
	for (int *pp = tt[x]; pp < cur[x]; ++pp)
		go(*pp);
}
void pr3(int x, int w)
{
	if (w > 1)
		pr3(x/3, w-1);
	cout << x%3;
}
void prepare()
{
	memset(tt, 0, sizeof(tt));
	for (int i = 0; i < M; ++i)
	{
		cur[i] = tt[i];
		curFr[i] = fr[i];
	}
	search(0, 0, 0);

	int maxR = 0;
	for (int i = 0; i < M; ++i)
		if (cur[i]-tt[i] > maxR)
			maxR = cur[i] - tt[i];

	maxR = 0;
	for (int i = 0; i < M; ++i)
		if (curFr[i]-fr[i] > maxR)
			maxR = curFr[i] - fr[i];

	memset(canReach, 0, sizeof(canReach));
	goto0(0);
	
	memset(mark, 0, sizeof(mark));
	go(0);

	memset(&tm, 0, sizeof(tm));
	for (int i = 0; i < M; ++i)
		if (mark[i])
			for (int *pp = tt[i]; pp < cur[i]; ++pp)
				if (mark[*pp])
					tm.s[remap[i]][remap[*pp]]++;
}
void matrixMul(Matrix &dst, const Matrix &a, const Matrix &b)
{
	for (int i = 0; i < ccnt; ++i)
		for (int j = 0; j < ccnt; ++j)
		{
			long long r = 0;	
			const unsigned int *ai = a.s[i];
			for (int k = 0; k < ccnt; ++k)
				r += ai[k] * b.s[k][j];
			r %= MOD;
			dst.s[i][j] = r;
		}
}
long long getAns()
{
	long long cur = 1;
	memset(&dst, 0, sizeof(dst));
	for (int i = 0; i < ccnt; ++i)
		dst.s[i][i] = 1;
	while (n)
	{
		if (n&cur)
		{
			matrixMul(tmpm, dst, tm);
			dst = tmpm;
			n -= cur;
		}
		matrixMul(tmpm, tm, tm);
		tm = tmpm;
		cur *= 2;
	}
	return dst.s[0][0];
}
int main()
{
	cin >> n >> m;
	M = 1;
	for (int i = 0; i < m; ++i)
		M *= 3;
	prepare();
	cout << getAns() << endl;
	return 0;
}

