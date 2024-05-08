#include <iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int matrix[N][N] = {0}, differ_matrix[N][N] = {0};

// 自己画个图理解一下就明白了
void __operator(int x1, int y1, int x2, int y2, int c) {
    differ_matrix[x1][y1] += c;
    differ_matrix[x2 + 1][y1] -= c;
    differ_matrix[x1][y2 + 1] -= c;
    differ_matrix[x2 + 1][y2 + 1] += c;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &matrix[i][j]);

    // 求出最初的差分矩阵，把初始的矩阵一个一个插进去，然后更新差分矩阵
    // 修改原矩阵的某个子矩阵，可以用函数表示，然后现在把这个子矩阵修改为这个点的矩阵，也是一样的
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            __operator(i, j, i, j, matrix[i][j]);

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        __operator(x1, y1, x2, y2, c);
    }

    // 最后求一次前缀和就是最终的结果
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + differ_matrix[i][j];

    // output
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cout << matrix[i][j];
            if (j != m)
                cout << ' ';
            else if (j == m && i != n)
                cout << '\n';
        }

    return 0;
}
