/*
 * @lc app=leetcode.cn id=998 lang=cpp
 * @lcpr version=30404
 *
 * [998] 最大二叉树 II
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

    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        // 新加入的元素位于原数组的末尾，因此在最大二叉树中，它只可能出现在从根节点开始不断向右寻找的路径上。
        // 对当前节点 root 而言，root 代表当前区间中的最大值：
        // 1. 如果新加入的值大于 root->val，说明新值成为当前区间的最大值。按照最大二叉树的构造规则，原来的整棵树应该作为新节点的左子树，新节点本身成为当前子树的新根。
        // 2. 如果新加入的值小于 root->val，说明当前根节点仍然是最大值。由于新值位于数组末尾，所以它不可能进入左子树，只能位于右子树中。因此继续递归处理 root->right。按照这个逻辑不断向右查找，直到新值大于当前节点，或者找到空的右子树。如果找到空节点，说明新值直接作为当前节点的右孩子插入。整个过程只需要沿着右侧路径遍历，不需要重新构造整棵树。

        // 如果 root 为空，对应找到空节点的情况，这时候返回值就是以 val 值的新节点，左右子树为空。
        // 如果 root->val < val，对应新值大于当前节点的情况，需要将原 root 作为新节点的左子树。
        if (!root || root->val < val) return new TreeNode(val, root, nullptr);

        root->right = insertIntoMaxTree(root->right, val);


        return root;
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
// [4,1,3,null,null,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,2,4,null,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,2,3,null,1]\n4\n
// @lcpr case=end

 */
