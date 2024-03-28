#include <cstdio>
#include <cmath>
using namespace std;

const int N = 55;

bool o[N][N];
char G[N][N][20];
double v[N][N];

double work(int i, int j) {
    if (o[i][j]) return v[i][j];
    o[i][j] = true;
    char *s = G[i][j];
    if (*s == 'S' || *s == 'A') { // command
        double P = 0, Q = 0;
        int x1, y1, x2, y2;
        sscanf(s + 4, "%d,%d:%d,%d", &x1, &y1, &x2, &y2);
        for (int x = x1; x <= x2; ++x)
            for (int y = y1; y <= y2; ++y) {
                double v = work(x, y);
                P += v, Q += v * v;
            }
        int sz = (x2 - x1 + 1) * (y2 - y1 + 1);
        if (s[1] == 'U') v[i][j] = P;
        if (s[1] == 'V') v[i][j] = P / sz;
        if (s[1] == 'T') v[i][j] = sqrt(Q / sz - (P / sz) * (P / sz));
    } else {
        sscanf(s, "%lf", &v[i][j]);
    }
    return v[i][j];
}

int main() {
//    freopen("excel.in" , "r", stdin);
//    freopen("excel.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%s", G[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            printf("%.2f%c", work(i, j), j == m ? '\n' : ' ');
    return 0;
}
