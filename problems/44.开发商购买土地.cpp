// https://kamacoder.com/problempage.php?pid=1044

#include <bits/stdc++.h>


int main()
{
    // 二维前缀和数组
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> vec(n, std::vector<int>(m));
    std::vector<std::vector<int>> preSum(1 + n, std::vector<int>(1 + m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> vec[i][j];

            preSum[1 + i][1 + j] = vec[i][j] + preSum[i][1 + j] + preSum[1 + i][j] - preSum[i][j];
        }
    }

    int res = INT_MAX;

    // 按行切
    for (int i = 0; i < n; ++i) res = std::min(res, std::abs(2 * preSum[1 + i][m] - preSum[n][m]));

    // 按列切
    for (int j = 0; j < m; ++j) res = std::min(res, std::abs(2 * preSum[n][1 + j] - preSum[n][m]));

    std::cout << res << std::endl;


    return 0;
}
