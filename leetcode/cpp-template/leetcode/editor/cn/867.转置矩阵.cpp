/*
 * @lc app=leetcode.cn id=867 lang=cpp
 * @lcpr version=30404
 *
 * [867] 转置矩阵
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();

        // 题目的矩阵不一定是方阵，因此仅靠对角线交换的思路是局限的。
        std::vector<std::vector<int>> res(n, std::vector<int>(m));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) res[j][i] = matrix[i][j];
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
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
