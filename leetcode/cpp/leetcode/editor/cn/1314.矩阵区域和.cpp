/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start


const int N = 100 + 10;

class Solution {
public:
    std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k) {
        // 先初始化数组和二维前缀和数组
        for (int i = 1; i <= mat.size(); ++i)
            for (int j = 1; j <= mat[0].size(); ++j) {
                nums[i][j] = mat[i - 1][j - 1];
                presums[i][j] = presums[i - 1][j] + presums[i][j - 1] - presums[i - 1][j - 1] + nums[i][j];
            }

        // 开始构造answer矩阵
        std::vector<std::vector<int>> answer;
        // TODO

        return answer;
    }

private:
    int nums[N][N] = {0};

    int presums[N][N] = {0};
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
