/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::vector<std::vector<int>> generateMatrix(int n)
    {
        // 模拟整个操作的过程，以走一圈为一个周期
        std::vector<std::vector<int>> res(n, std::vector<int>(n));

        int base = 0, num = 1;

        // 知道 base 就知道每个周期的坐标该怎么走了，注意一个周期的边界判断逻辑
        while (base < n / 2)
        {
            // 向右走
            for (int y = base; y < n - base - 1; ++y) res[base][y] = num++;

            // 向下走
            for (int x = base; x < n - base - 1; ++x) res[x][n - base - 1] = num++;

            // 向左走
            for (int y = n - base - 1; y >= base + 1; --y) res[n - base - 1][y] = num++;

            // 向上走
            for (int x = n - base - 1; x >= base + 1; --x) res[x][base] = num++;

            // 进入下一个迭代
            ++base;
        }

        // 如果是奇数的边长需要手动填充中间的值
        if (n & 1) res[n / 2][n / 2] = n * n;

        return res;
    }
};

// @lc code=end
