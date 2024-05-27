#include <cstdio>
#include <cstring>
using namespace std;

const int D = 6, MOD = 1e9 + 7;

typedef long long int64;
typedef int64 mat[D][D];

mat U, V, I;

void matmul(mat a, mat b, mat c) {
    mat t = {{0}};
    for (int i = 0; i < D; ++i)
        for (int j = 0; j < D; ++j)
            for (int k = 0; k < D; ++k)
                (t[i][j] += a[i][k] * b[k][j]) %= MOD;
    memcpy(c, t, sizeof(t));
}

int main() {
//    freopen("dice.in" , "r", stdin);
//    freopen("dice.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m), --n;
    for (int i = 0; i < D; ++i)
        for (int j = 0; j < D; ++j)
            U[i][j] = 4;
    for (int i = 1, a, b; i <= m; ++i) {
        scanf("%d%d", &a, &b), --a, --b;
        U[a][b < 3 ? (b + 3) : (b - 3)] = 0;
        U[b][a < 3 ? (a + 3) : (a - 3)] = 0;
    }
    for (int i = 0; i < D; ++i)
        V[i][i] = 4;

    for (; n; n >>= 1, matmul(U, U, U))
        n & 1 ? matmul(V, U, V), 0 : 0;
    int64 ans = 0;
    for (int i = 0; i < D; ++i)
        for (int j = 0; j < D; ++j)
            ans += V[i][j];
    printf("%d\n", (int)(ans % MOD));
    return 0;
}
