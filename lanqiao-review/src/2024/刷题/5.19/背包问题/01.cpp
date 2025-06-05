// 01 背包
// https: // www.acwing.com/problem/content/description/2/

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
        // 改为滚动数组优化空间复杂度，注意遍历的顺序需要从后往前，因为不能提前修改前面的值
        for (int j = V; j >= 0; --j)
        {
            if (j >= v[i]) dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    std::cout << dp[V] << std::endl;


    return 0;
}
