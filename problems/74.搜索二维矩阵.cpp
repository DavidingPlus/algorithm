/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 框架是二分查找
        int left = 0, right = matrix.size() * matrix[0].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == at(matrix, mid))
                return true;
            else if (at(matrix, mid) > target)
                right = mid - 1;
            else if (at(matrix, mid) < target)
                left = mid + 1;
        }
        return false;
    }

    // 为了减少时间复杂度，我们通过一维坐标访问二维坐标的数组
    int at(vector<vector<int>>& matrix, int index) {
        int x = index / matrix[0].size(), y = index % matrix[0].size();

        return matrix[x][y];
    }
};
// @lc code=end
