// All Mythin
// Create At 14:33 12-04 2012

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;

int64 readInt64() {
    char ch;
    for (ch = getchar(); !(ch >= '0' && ch <= '9'); ch = getchar());
    int64 res = ch - '0';
    for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) {
        res = res * 10 + (ch - '0');
    }
    return res;
}

void outInt64(int64 x) {
    if (x == 0) {
        return ;
    }
    outInt64(x / 10);
    putchar ('0' + x % 10);
}

const int MAXPOW = 40;
const int64 LIM = 1000000000000LL;

struct radio {
    int64 x, y;
    
    radio(int64 _x = 0, int64 _y = 1): x(_x), y(_y) {
        reduce();
    }
    void reduce() {
        int64 g = __gcd(x, y);
        x /= g; y /= g;
    }
    void output() {
        outInt64(x); putchar ('/');
        outInt64(y); puts ("");
    }
    bool try_mul(int64& mul) {
        if (mul % y != 0) {
            return false;
        }
        mul /= y; mul *= x;
        return true;
    }
};

map<int64, map<int, int> > all_pow;
map<int64, map<int, int> > all_pow_rev;

void get_all_pow() {
    repf (i, 2, 1000000) {
        int64 cur = (int64)i * i;
        int pnt = 2;
        while (cur <= LIM) {
            if (pnt > 2) {
                all_pow[cur][pnt] = i;
                all_pow_rev[cur][i] = pnt;
            }
            cur *= i; ++pnt;
        }
    }
}

int64 a[128];
int n;

int64 get_sqrt(int64 x) {
    int64 sqrx = (int64)(sqrt(1.0 * x) + 1e-8);
    repf (off, -1, 1) {
        int64 cur = sqrx + off;
        if (cur != 0 && x / cur == cur && cur * cur == x) {
            return cur;
        }
    }
    return -1;
}

int64 get_pow(int64 x, int p) {
    if (x == 1) return 1;
    if (p == 2) return get_sqrt(x);
    if (all_pow[x].find(p) != all_pow[x].end()) {
        return all_pow[x][p];
    }
    return p == 1? x : -1;
}

int get_pow_num(int64 x, int64 y) {
    if (x == y) return 1;
    if (y != 0 && x / y == y && y * y == x) {
        return 2;
    }
    if (all_pow_rev[x].find(y) != all_pow_rev[x].end()) {
        return all_pow_rev[x][y];
    }
    return -1;
}   

bool get_gcf(vector<radio> allr) {
    repf (pnum, 1, MAXPOW) {
        int64 fx = get_pow(allr[0].x, pnum);
        int64 fy = get_pow(allr[0].y, pnum);
        if (fx == -1 || fy == -1) {
            continue ;
        }
        bool all_match = true;
        repeach (it, allr) {
            int nx = get_pow_num(it->x, fx);
            int ny = get_pow_num(it->y, fy);
            if (it->y == 1 && fy == 1) {
                ny = nx;
            }
            if (nx == -1 || ny == -1 || nx != ny) {
                all_match = false;
                break ;
            }
        }
        if (all_match) {
            radio(fx, fy).output();
            return true;
        }
    }
    return false;
}

void solve() {
    vector<radio> allr;
    rep (i, n - 1) {
        allr.push_back(radio(a[i + 1], a[i]));
    }
    if (!get_gcf(allr)) {
        puts ("Illegal");
    }
}

int main() {
    //freopen ("bonus_gen_6.in", "r", stdin);
    //freopen ("bonus.out", "w", stdout);
    get_all_pow();
    
    int Case = 1;
    repcase {
        scanf ("%d", &n);
        rep (i, n) {
            a[i] = readInt64();
        }
        sort (a, a + n);
        n = unique(a, a + n) - a;
        
        printf ("Case %d: ", Case++);
        if (n == 1) {
            puts ("INF");
        } else if (n == 2) {
            radio(a[1], a[0]).output();
        } else {
            solve();
        }
    }
    return 0;
}

