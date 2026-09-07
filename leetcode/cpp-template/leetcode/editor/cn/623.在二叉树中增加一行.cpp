/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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

    // 解法 1：层序遍历。
    // TreeNode *addOneRow(TreeNode *root, int val, int depth)
    // {
    //     // 同链表思路，增加一个 dummyHead。这样不用特殊处理根节点。
    //     TreeNode *dummyHead = new TreeNode(-1, root, nullptr);

    //     std::queue<TreeNode *> q;
    //     q.push(dummyHead);

    //     int dep = -1;
    //     while (!q.empty())
    //     {
    //         ++dep;

    //         int n = q.size();
    //         for (int i = 0; i < n; ++i)
    //         {
    //             auto node = q.front();
    //             q.pop();

    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);

    //             // 我们在目标层的上一层遍历的时候添加新结点，这样能拿到父结点的信息。
    //             if (depth - 1 == dep)
    //             {
    //                 TreeNode *newLeftNode = new TreeNode(val, node->left, nullptr), *newRightNode = new TreeNode(val, nullptr, node->right);

    //                 node->left = newLeftNode, node->right = newRightNode;
    //             }
    //         }

    //         if (depth - 1 == depth) break;
    //     }


    //     return dummyHead->left;
    // }


    // 解法 2：递归遍历。
    int dep = -1, targetVal, targetDepth;


    void traverse(TreeNode *root)
    {
        if (!root) return;

        ++dep;

        if (targetDepth - 1 == dep)
        {
            TreeNode *newLeftNode = new TreeNode(targetVal, root->left, nullptr), *newRightNode = new TreeNode(targetVal, nullptr, root->right);

            root->left = newLeftNode, root->right = newRightNode;
        }

        traverse(root->left), traverse(root->right);

        --dep;
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        targetVal = val, targetDepth = depth;

        // 同上。
        TreeNode *dummyHead = new TreeNode(-1, root, nullptr);
        traverse(dummyHead);
        return dummyHead->left;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
