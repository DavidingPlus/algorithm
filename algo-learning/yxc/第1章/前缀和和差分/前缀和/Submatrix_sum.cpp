#include <iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int matrix[N][N] = {0}, prefix_sum[N][N] = {0};
int x1, y1, x2, y2;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &matrix[i][j]);

    // 求前缀和(画个图就理解了)
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            prefix_sum[i][j] = matrix[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];

    // 求部分和
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        cout << prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}
