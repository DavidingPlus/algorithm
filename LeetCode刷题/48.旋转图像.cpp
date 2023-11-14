/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void rotate(vector<vector<int>>& matrix) {
        // 这题和之前那个反转字符串比较类似，那个题的思路是先反转整个字符串，然后再反转各自的字符串得到最终结果
        // 这个题的巧妙之处就在于先做镜像对称，然后再对每一行做翻转即可...
        // 当然，画图之后我们发现如果顺时针就对主对角线做镜像对称，逆时针就对副对角线做镜像对称

        int n = matrix.size();
        // 沿主对角线做镜像对称
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);

        // 每行做翻转
        for (auto& nums : matrix)
            reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
