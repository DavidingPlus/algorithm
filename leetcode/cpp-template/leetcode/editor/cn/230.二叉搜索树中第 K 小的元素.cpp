/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30404
 *
 * [230] 二叉搜索树中第 K 小的元素
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

    int res = 0, rank = 0;

    // 二叉搜索树左子树值均小于根节点，右子树值均大于根节点，利用这个性质，中序遍历的结果是升序的。

    void traverse(TreeNode *root, int k)
    {
        if (!root) return;

        traverse(root->left, k);

        if (++rank == k)
        {
            res = root->val;
            return;
        }

        traverse(root->right, k);
    }


    int kthSmallest(TreeNode *root, int k)
    {
        traverse(root, k);
        return res;
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
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */
