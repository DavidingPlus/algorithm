/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

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

    int res = 0;

    int diameterOfBinaryTree(TreeNode *root)
    {
        // 对每个结点而言，过该结点的最长直径就是左子树的高度加上右子树的高度，因此只需遍历所有的节点获得最大值即可。
        depth(root);
        return res;
    }

    int depth(TreeNode *root)
    {
        if (!root) return 0;

        // 如果我这里改为后序遍历，我就能够在下面获得函数的返回值，进而在一次遍历的时候就能够获得过该节点的最大直径。这个思路算是遍历加上划分为子问题合起来吧。
        int leftDepth = depth(root->left), rightDepth = depth(root->right);

        res = std::max(res, leftDepth + rightDepth);


        return 1 + std::max(leftDepth, rightDepth);
    }
};
// @lc code=end


int main()
{
    Solution solution;

    std::vector<std::optional<int>> values{4, -7, -3, std::nullopt, std::nullopt, -9, -3, 9, -7, -4, std::nullopt, 6, std::nullopt, -6, -6, std::nullopt, std::nullopt, 0, 6, 5, std::nullopt, 9, std::nullopt, std::nullopt, -1, -4, std::nullopt, std::nullopt, std::nullopt, -2};
    TreeNode *root = TreeNode::createRoot(values);

    std::cout << solution.diameterOfBinaryTree(root) << std::endl; // 8

    TreeNode::freeTree(root);
}
