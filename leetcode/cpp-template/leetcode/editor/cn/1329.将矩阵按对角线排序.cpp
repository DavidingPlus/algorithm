/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30404
 *
 * [1329] 将矩阵按对角线排序
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>> &mat)
    {
        // 相同对角线上元素的共同点是横坐标 i 减去纵坐标 j 是一样的（可正可负）。这样就能把原矩阵按照题目要求划分开了，然后再划分的元素里面排序即可。

        int m = mat.size(), n = mat[0].size();

        // 为了方便查询，使用哈希表存储，键是 i - j，值是最大堆（优先性队列）。
        std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> um;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) um[i - j].emplace(mat[i][j]);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = um[i - j].top();
                um[i - j].pop();
            }
        }


        return mat;
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
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */
