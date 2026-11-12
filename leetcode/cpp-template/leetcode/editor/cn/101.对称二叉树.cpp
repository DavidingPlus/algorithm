/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

    // // 解法 1：递归，分解子问题。
    // bool isSymmetric(TreeNode *root)
    // {
    //     if (!root)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return isMirror(root->left, root->right);
    //     }
    // }

    // // 判断输入的 p 和 q 两棵树是否轴对称。
    // bool isMirror(TreeNode *p, TreeNode *q)
    // {
    //     // 都为空。
    //     if (!p && !q)
    //     {
    //         return true;
    //     }
    //     // 有一个不为空。
    //     else if (!p || !q)
    //     {
    //         return false;
    //     }
    //     // 都不为空。
    //     else
    //     {
    //         return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);
    //     }
    // }


    // 解法 2：迭代，成对层序遍历。
    bool isSymmetric(TreeNode *root)
    {
        if (!root) return true;

        // 这样设置的原因是：对称性需要同时看树的左右两侧，所以队列里存一对节点，而不是每次只存一个节点。比如根的左右孩子是 A 和 B，先比较 (A, B)；之后按镜像关系继续比较 (A.left, B.right) 和 (A.right, B.left)
        std::queue<std::pair<TreeNode *, TreeNode *>> q;
        // 从根节点的左右子树开始：它们必须互为镜像。
        q.emplace(root->left, root->right);

        while (!q.empty())
        {
            // 队列中的每一对，都是两侧对应且应该互为镜像的位置。
            auto [left, right] = q.front();
            q.pop();

            // 两个对应位置都为空，结构相符；这一对不需要继续展开。
            if (!left && !right)
            {
                continue;
            }
            // 只有一侧为空，说明结构不对称。
            else if (!left || !right)
            {
                return false;
            }
            // 两侧节点值不同，说明内容不对称。
            else if (left->val != right->val)
            {
                return false;
            }
            else
            {
                // 例如处理 (L, R) 后，继续比较 (L.left, R.right) 和 (L.right, R.left)。
                q.emplace(left->left, right->right);
                q.emplace(left->right, right->left);
            }
        }


        return true;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
