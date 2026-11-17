/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30404
 *
 * [124] 二叉树中的最大路径和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

public:

    // XXX 参考 543 题，整棵树的最大路径和就是每个结点为根节点的最大路径和的最大值。现在考虑每个结点为根节点的最大路径和，它的路径可能是有左右子树存在，最终结果是穿过根节点的情况。所以如果以这个函数递归的话，没有办法知道子树是否穿过它的根节点这个状态，如果穿过了，就没办法通过子树合理的求出根节点的答案。因此穿不穿过根节点这个状态很讨厌，我们不如把递归函数分为两段，也就是维护一个函数，记录当前根节点的单边最大路径和。由于题目的数据有负数，如果左右子树的答案为负数，相应的部分应舍去。

    int maxPathSum(TreeNode *root)
    {
        oneSideMax(root);
        return res;
    }

    int oneSideMax(TreeNode *root)
    {
        if (!root) return 0;

        int leftMax = std::max(0, oneSideMax(root->left)), rightMax = std::max(0, oneSideMax(root->right));

        res = std::max(res, leftMax + rightMax + root->val);


        return root->val + std::max(leftMax, rightMax);
    }


    // 结点最多 30000 个，每个结点最小值是 -1000，最小的和不会超过 INT_MIN。
    int res = std::numeric_limits<int>::min();
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */
