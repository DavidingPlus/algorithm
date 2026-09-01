/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=30404
 *
 * [1260] 二维网格迁移
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    // 举一个例子说明。假设 grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4。
    // 相当于是把 [12,0,21,13] 接到原 grid 的头部，但是由于这道题是二维数组，接到头部这种仿链表的思路不太好操作，因此我们考虑另一种思路。
    // 关键点是要把 [12,0,21,13] 通过某种手段放到 grid 头部，那么可以考虑翻转链表的思路。我们首先把整个 grid 反转，然后再分别把两部分的反转即可。
    // XXX 为了方便操作，我们使用一维数组的下标模拟访问二维数组（这个思路后面的题目都可以参考）。

    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size(), mn = m * n;

        k = k % mn;

        // 整体翻转。
        reverse(grid, 0, mn - 1);
        // 翻转前面的部分（原后面）。
        reverse(grid, 0, k - 1);
        // 翻转后面的部分（原前面）。
        reverse(grid, k, mn - 1);


        return grid;
    }

    int get(const std::vector<std::vector<int>> &grid, int index)
    {
        int n = grid[0].size();
        return grid[index / n][index % n];
    }

    void set(std::vector<std::vector<int>> &grid, int index, int val)
    {
        int n = grid[0].size();
        grid[index / n][index % n] = val;
    }

    void reverse(std::vector<std::vector<int>> &grid, int i, int j)
    {
        while (i <= j)
        {
            int temp = get(grid, i);
            set(grid, i, get(grid, j));
            set(grid, j, temp);

            ++i, --j;
        }
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
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

 */
