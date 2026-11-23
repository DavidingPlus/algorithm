// 完全背包
// https://www.acwing.com/problem/content/description/3/

#include <iostream>
#include <vector>


void solution();


int main()
{
    solution();
}


void solution()
{
    int N, V;
    std::cin >> N >> V;

    std::vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) std::cin >> v[i] >> w[i];

    std::vector<int> dp(1 + V, 0);
    for (int i = 1; i <= N; ++i)
    {
        std::vector<int> tmp(1 + V, 0);

        // 注意这里两层循环的 i 和 j 代表的是第几个，所以对应的下标要减 1。

        for (int j = 1; j <= V; ++j)
        {
            // 最直接的思路是，枚举取 k 个第 i 个物品，进行状态转移，但是三层循环必然超时，肯定需要对状态转移方程做优化。
            // for (int k = 0; j - k * v[i - 1] >= 0; ++k) tmp[j] = std::max(tmp[j], k * w[i - 1] + dp[j - k * v[i - 1]]);

            tmp[j] = dp[j];

            if (j - v[i - 1] >= 0) tmp[j] = std::max(tmp[j], w[i - 1] + tmp[j - v[i - 1]]);
        }

        std::swap(dp, tmp);
    }

    std::cout << dp[V] << std::endl;
}
