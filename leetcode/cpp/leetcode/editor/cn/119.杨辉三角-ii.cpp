/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start


class Solution {
public:
    // 通过二叉树的递归思路，将大问题转化为子问题
    // std::vector<int> getRow(int rowIndex) {
    //     if (0 == rowIndex)
    //         return {1};

    //     // 先把上一个的拿到
    //     std::vector<int> last = getRow(rowIndex - 1);

    //     std::vector<int> ret = {1};
    //     for (int i = 0; i < last.size() - 1; ++i)
    //         ret.push_back(last[i] + last[i + 1]);
    //     ret.push_back(1);

    //     return ret;
    // }

    // 第二种，从0开始进行动态规划的思维
    std::vector<int> getRow(int rowIndex) {
        if (0 == rowIndex)
            return {1};

        std::vector<std::vector<int>> dp;
        dp.push_back({1});

        for (int i = 1; i <= rowIndex; ++i) {
            std::vector<int> new_row = {1};
            for (int j = 0; j < dp[i - 1].size() - 1; ++j)
                new_row.push_back(dp[i - 1][j] + dp[i - 1][j + 1]);
            new_row.push_back(1);

            dp.push_back(new_row);
        }

        return dp[rowIndex];
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
