#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int MOD = 10007;
int n, m, k;
int g[MAXN][MAXN];
int mp[MAXN], q[MAXN];
long long tt[MAXN];
long long pw[MAXN];

bool isIsomorphism(int p)
{
	for (int i = 1; i < p; ++i)
		if (g[p][i] ^ g[q[p]][q[i]])
			return false;
	return true;
}

void isomorphismSearch(int p, int cnt)
{
	if (p > n)
	{
		tt[cnt]++;
		return ;
	}
	for (int i = p; i <= n; ++i)
	{
		swap(q[p], q[i]);
		if (isIsomorphism(p))
		{
			int r = q[p];
			while (r<p)
				r = q[r];
			isomorphismSearch(p+1, cnt+(r==p));
		}
		swap(q[p], q[i]);
	}
}

void solve(long long a, long long b, long long c, long long &x, long long &y)
{
	if (b==0)
	{
		x = c/a; y = 0;
		return ;
	}
	solve(b, a%b, c, y, x);
	y -= a/b * x;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	for (int i = 1; i <= n; ++i)
		q[i] = i;
	pw[0] = 1;
	for (int i = 1; i <= n; ++i)
		pw[i] = (pw[i-1]*k) % MOD;

	memset(tt, 0, sizeof(tt));
	isomorphismSearch(1, 0);
	long long ans = 0, stt = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += ((tt[i]%MOD)*pw[i])%MOD;
		stt += tt[i];
	}
	ans %= MOD;
	long long x, y;
	solve(stt%MOD, MOD, ans, x, y);
	x %= MOD;
	if (x < 0)
		x += MOD;
	cout << x << endl;
	return 0;
}

