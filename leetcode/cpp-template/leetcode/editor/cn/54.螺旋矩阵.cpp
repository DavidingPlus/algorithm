/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> res;

        // 因为遍历的顺序是确定的，给定四个遍历的边界。然后一轮按照顺时针的顺序遍历元素即可。
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;

        while (true)
        {
            // 向右。
            for (int j = left; j <= right; ++j) res.emplace_back(matrix[up][j]);
            ++up;
            // 因为结束肯定是在到达边界的时候结束，所以在这里做判断。
            if (m * n == res.size()) break;

            // 向下。
            for (int i = up; i <= down; ++i) res.emplace_back(matrix[i][right]);
            --right;
            if (m * n == res.size()) break;

            // 向左。
            for (int j = right; j >= left; --j) res.emplace_back(matrix[down][j]);
            --down;
            if (m * n == res.size()) break;

            // 向上。
            for (int i = down; i >= up; --i) res.emplace_back(matrix[i][left]);
            ++left;
            if (m * n == res.size()) break;
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
