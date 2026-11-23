// 01 背包
// https://www.acwing.com/problem/content/description/2/

#include <iostream>
#include <vector>


void solution1();

void solution2();


int main()
{
    // solution1();
    solution2();
}


void solution1()
{
    int N, V;
    std::cin >> N >> V;

    std::vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) std::cin >> v[i] >> w[i];

    std::vector<std::vector<int>> dp(1 + N, std::vector<int>(1 + V, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            dp[i][j] = dp[i - 1][j];

            // 注意这里两层循环的 i 和 j 代表的是第几个，所以对应的下标要减 1。
            if (j - v[i - 1] >= 0) dp[i][j] = std::max(dp[i][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
        }
    }

    std::cout << dp[N][V] << std::endl;
}

// 滚动数组优化空间复杂度的版本。
void solution2()
{
    int N, V;
    std::cin >> N >> V;

    std::vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) std::cin >> v[i] >> w[i];

    std::vector<int> dp(1 + V, 0);
    for (int i = 1; i <= N; ++i)
    {
        std::vector<int> tmp(1 + V, 0);

        for (int j = 1; j <= V; ++j)
        {
            tmp[j] = dp[j];

            if (j - v[i - 1] >= 0) tmp[j] = std::max(tmp[j], w[i - 1] + dp[j - v[i - 1]]);
        }

        std::swap(dp, tmp);
    }

    std::cout << dp[V] << std::endl;
}
