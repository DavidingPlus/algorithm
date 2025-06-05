// 完全背包
// https://www.acwing.com/problem/content/description/3/

#include <iostream>


const int MAXN = 1e3 + 10;


int main()
{
    int N = 0, V = 0;
    std::cin >> N >> V;

    int v[MAXN] = {0}, w[MAXN] = {0};
    for (int i = 1; i <= N; ++i) std::cin >> v[i] >> w[i];

    int dp[MAXN] = {0};
    for (int i = 1; i <= N; ++i)
    {
        // 完全背包和 01 背包唯一的区别见 02-优化.png，反映到滚动数组的代码里面就是遍历顺序不同
        for (int j = 0; j <= V; ++j)
        {
            if (j >= v[i]) dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    std::cout << dp[V] << std::endl;


    return 0;
}
