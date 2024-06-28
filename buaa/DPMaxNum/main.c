#include <stdio.h>
#include <stdlib.h>

#define MAXN 2000000    // 定义最大元素数量为2000000
#define INF 1000000000  // 定义无穷大的值，用于初始化dp数组

int main() {
    int m, n;
    // 读取两个整数m和n，分别表示需要找到的子段数量和数列的长度
    scanf("%d %d", &m, &n);

    // 定义并读取数组a，存储数列的值
    int a[n + 1];
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 定义dp数组，dp[i][j]表示前i个元素中选取j个不相交子段的最大和
    int dp[n + 1][m + 1];
    // 初始化dp数组为-INF，表示无效的初始状态
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -INF;
        }
    }

    // 初始化：前0个元素选取0个子段的和为0
    dp[0][0] = 0;

    // 定义并计算前缀和数组，用于快速计算子段和
    int prefix_sum[n + 1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    // 遍历每一个位置i，考虑以它结尾的子段对状态的更新
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < i; k++) {
                // 只有在前k个元素选取j-1个子段的情况下有效时，才进行更新
                if (dp[k][j - 1] != -INF) {
                    // 计算子段和
                    int sum_segment = prefix_sum[i] - prefix_sum[k];
                    // 更新dp数组，选择较大的值
                    dp[i][j] = (dp[i][j] > dp[k][j - 1] + sum_segment) ? dp[i][j] : dp[k][j - 1] + sum_segment;
                }
            }
        }
    }

    // 找到结果，即dp数组中前n个元素选取m个不相交子段的最大和
    int result = -INF;
    for (int i = 1; i <= n; i++) {
        if (dp[i][m] > result) {
            result = dp[i][m];
        }
    }

    // 输出结果
    printf("%d\n", result);

    return 0;
}
