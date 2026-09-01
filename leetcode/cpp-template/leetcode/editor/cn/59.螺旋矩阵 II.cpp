/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30404
 *
 * [59] 螺旋矩阵 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> generateMatrix(int n)
    {
        // 二维数组可以这样初始化。
        std::vector<std::vector<int>> res(n, std::vector<int>(n));

        int up = 0, down = n - 1, left = 0, right = n - 1;

        int num = 0;
        while (true)
        {
            // 向右。
            for (int j = left; j <= right; ++j) res[up][j] = ++num;
            ++up;
            if (n * n == num) break;

            // 向下。
            for (int i = up; i <= down; ++i) res[i][right] = ++num;
            --right;
            if (n * n == num) break;

            // 向左。
            for (int j = right; j >= left; --j) res[down][j] = ++num;
            --down;
            if (n * n == num) break;

            // 向上。
            for (int i = down; i >= up; --i) res[i][left] = ++num;
            ++left;
            if (n * n == num) break;
        }


        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
