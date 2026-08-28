/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30404
 *
 * [378] 有序矩阵中第 K 小的元素
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int kthSmallest(const std::vector<std::vector<int>> &matrix, int k)
    {
        int res = 0;

        // 每行的元素都是升序的。那么把所有行当作 n 个链表，使用优先性队列的思路合并这 n 个链表即可。
        // 存储元素的位置 {i, j} 用于获取下一个下标。
        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::function<bool(const std::pair<int, int> &, const std::pair<int, int> &)>>
            pq([&matrix](const std::pair<int, int> &p1, const std::pair<int, int> &p2)
               {
                   return matrix[p1.first][p1.second] > matrix[p2.first][p2.second]; //
               });

        // 将所有数组首元素入队列。
        for (int i = 0; i < matrix.size(); ++i) pq.push({i, 0});

        // 执行合并多个有序链表的逻辑，找到第 k 小的元素。
        while (!pq.empty() && k > 0)
        {
            auto e = pq.top();
            pq.pop();

            res = matrix[e.first][e.second];
            --k;

            if (1 + e.second < matrix[e.first].size()) pq.push({e.first, 1 + e.second});
        }


        return res;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here

    // 13
    std::cout << solution.kthSmallest({{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}, 8) << std::endl;
    // -5
    std::cout << solution.kthSmallest({{-5}}, 1) << std::endl;
}


/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */
