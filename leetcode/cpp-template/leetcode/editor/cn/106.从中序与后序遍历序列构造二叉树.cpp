/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

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

    // 为了防止在递归中每次创建 std::vector 浪费资源，给出范围 Range 的版本（左闭右闭）。
    TreeNode *buildTreeFromRange(std::vector<int> &inorder, int inorderLeft, int inorderRight, std::vector<int> &postorder, int postorderLeft, int postorderRight)
    {
        // 在递归的过程中，中序遍历和后序遍历的数组的大小时时刻刻是一样的，因此判断条件只需要写一个即可。
        if (inorderLeft > inorderRight) return nullptr;

        // 后序遍历的最后一个值是根节点，根据这个可以在中序遍历中找到这个结点，然后切分为左右两个子树进行分别构建。
        // 不管是中序遍历还是后序遍历，左子树都先于右子树，因此中序遍历划分的左子树的长度，直接去后序遍历从 postorderLeft 开始截取相同长度，即为后序遍历的左子树。

        int rootPosInorder = 0;
        for (int i = inorderLeft; i <= inorderRight; ++i)
        {
            if (postorder[postorderRight] == inorder[i])
            {
                rootPosInorder = i;
                break;
            }
        }

        TreeNode *root = new TreeNode(inorder[rootPosInorder]);

        // rootPosInorder 的基准值是 inorder 的首元素，也就是 0，因此注意坐标的换算。
        root->left = buildTreeFromRange(inorder, inorderLeft, rootPosInorder - 1, postorder, postorderLeft, postorderLeft + rootPosInorder - inorderLeft - 1);
        root->right = buildTreeFromRange(inorder, 1 + rootPosInorder, inorderRight, postorder, postorderLeft + rootPosInorder - inorderLeft, postorderRight - 1);


        return root;
    }

    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) { return buildTreeFromRange(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1); }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
