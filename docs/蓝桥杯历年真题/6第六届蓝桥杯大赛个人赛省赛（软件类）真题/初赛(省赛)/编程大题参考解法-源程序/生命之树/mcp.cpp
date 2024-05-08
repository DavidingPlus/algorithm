#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];
long long w[N], ans;

void dfs(int u, int fa) {
    for (int e = 0; e < (int)G[u].size(); ++e) {
        int v = G[u][e];
        if (v != fa) {
            dfs(v, u);
            w[u] += max(w[v], 0ll);
        }
    }
    if (ans < w[u]) ans = w[u];
}

int main() {
//    freopen("mcp.in" , "r", stdin );
//    freopen("mcp.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1, a; i <= n; ++i)
        scanf("%d", &a), w[i] = a;
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
