#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100100;
int n, L;
long long d[MAXN], t[MAXN];
long long s[MAXN], sd[MAXN], f[MAXN], g[MAXN];
int sta[MAXN], top;
long long ans;

void init()
{
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		d[i] = x;
		t[i] = y;
	}
	++n;
	d[n] = L;
	t[n] = 0;
	
	
	int j = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (d[i]==d[j])
			t[j] += t[i];
		else
		{
			++j;
			d[j] = d[i];
			t[j] = t[i];
		}
	}
	n = j;
}

class BigNumber {
public:
	int l, sig;
	int s[100];
	BigNumber(long long x)
	{
		if (x < 0)
		{
			sig = -1;
			x = -x;
		}
		else
			sig = 1;
		memset(s, 0, sizeof(s));
		l = 0;
		while (x>0LL)
		{
			s[l++] = x%10;
			x /= 10;
		}
		if (l==0)
			l = 1;
	}
	BigNumber operator *(const BigNumber &r) const {
		BigNumber ret(0LL);
		ret.sig = sig * r.sig;
		ret.l = l + r.l - 1;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r.l; ++j)
				ret.s[i+j] += s[i] * r.s[j];
		for (int i = 0; i < ret.l; ++i)
		{
			ret.s[i+1] += ret.s[i] / 10;
			ret.s[i] %= 10;
		}
		if (ret.s[ret.l])
			++ret.l;
		while (ret.l>1 && ret.s[ret.l-1]==0)
			--ret.l;
		if (ret.l==1 && ret.s[0]==0)
			ret.sig = 1;
		return ret;
	}
	bool operator <(const BigNumber &r) const {
		if (sig != r.sig) return sig < r.sig;
		if (l != r.l) return (l < r.l) ^ (sig == -1);
		for (int i = l - 1; i >= 0; --i)
			if (s[i] != r.s[i])
				return (s[i] < r.s[i]) ^ (sig == -1);
		return false;
	}
};


void process()
{
	long long oo = 100000LL * 1000000LL * 1000000LL + 1;
	s[0] = 0;
	sd[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		s[i] = s[i-1] + t[i];
		sd[i] = s[i] * d[i];
	}
	sta[0] = 0;
	top = 1;
	int best = 0;
	for (int i = 1; i <= n; ++i)
	{
		while (best+1<top && d[i]*(s[sta[best+1]]-s[sta[best]])>=(sd[sta[best+1]]-sd[sta[best]]))
			++best;
		f[i] = s[i] * d[i] - s[sta[best]] * (d[i] - d[sta[best]]);
		while (top>1 && BigNumber(sd[i]-sd[sta[top-1]])*BigNumber(s[sta[top-1]]-s[sta[top-2]])<BigNumber(sd[sta[top-1]]-sd[sta[top-2]])*BigNumber(s[i]-s[sta[top-1]]))
			--top;
		sta[top++] = i;
		if (best>=top)
			best = top-1;
	}
	for (int i = 1; i <= n; ++i)
		sd[i] = s[i] * (d[n]-d[i]);
	sta[0] = n;
	g[n] = 0;
	top = 1;
	best = 0;
	for (int i = n - 1; i >= 1; --i)
	{
		while (best+1<top && s[i]*(d[sta[best]]-d[sta[best+1]])<=-(sd[sta[best]]-sd[sta[best+1]]))
		{
			++best;
		}
		g[i] = (s[sta[best]]-s[i]) * d[sta[best]] + (s[n]-s[sta[best]]) * d[n];
		while (top>1 && BigNumber(sd[i]-sd[sta[top-1]])*BigNumber(d[sta[top-1]]-d[sta[top-2]])<BigNumber(sd[sta[top-1]]-sd[sta[top-2]])*BigNumber(d[i]-d[sta[top-1]]))
			--top;
		sta[top++] = i;
		if (best>=top)
			best = top-1;
	}
	ans = oo;
	for (int i = 1; i <= n; ++i)
		if (f[i] + g[i] < ans)
			ans = f[i] + g[i];
	long long tmp = 0;
	for (int i = 1; i <= n; ++i)
		ans -= (t[i]+0LL) * d[i];
		
}

void print()
{
	cout << ans << endl;
}

int main()
{
	init();
	process();
	print();
	return 0;
}

