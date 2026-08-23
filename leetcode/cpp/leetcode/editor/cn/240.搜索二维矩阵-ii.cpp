/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start


class Solution {
public:
    // 这个矩阵和前面一个题的性质不同，需要注意
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // 这个矩阵从左到右增加，从上到下增加
        // 所以我们没有办法知道下一行的第一个元素和上一行的最后一个元素之间的关系
        // 所以我们从右上角开始，target小于我我就往左走，大于我就往右走，找到了就返回，越界表示找不到

        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j])
                return true;

            // 这里我想优化一下，同一行的查找用二分来做
            else if (matrix[i][j] > target)
                --j;
            else if (matrix[i][j] < target)
                ++i;
        }
        return false;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
