/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30404
 *
 * [118] 杨辉三角
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> res = {{1}};

        for (int i = 2; i <= numRows; ++i)
        {
            auto &prevNow = res.back();
            std::vector<int> newRow(prevNow.size() + 1, 1);

            for (int j = 0; j + 1 < prevNow.size(); ++j) newRow[1 + j] = prevNow[j] + prevNow[j + 1];

            res.emplace_back(newRow);
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
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
