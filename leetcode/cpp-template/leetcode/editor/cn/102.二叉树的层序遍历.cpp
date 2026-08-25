/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{

public:

    // 解法 1：纯正的层次遍历模板。
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (!root) return {};

        std::vector<std::vector<int>> res;

        // 层次遍历，对应的是 bfs 广度优先算法，我们需要用到的是队列。
        std::queue<TreeNode *> q;
        // 将根节点入队列。
        q.push(root);

        // 一次 while 循环对应一层 while 的遍历，就是拿取这一层的结点遍历，然后把他们的子节点插入队列。
        while (!q.empty())
        {
            std::vector<int> layer;

            // for 循环会改变 q.size()，所以使用变量 n 存储。
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front();
                q.pop();

                layer.emplace_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.emplace_back(layer);
        }


        return res;
    }

    // 解法 2：我们用递归遍历来实现一下。

    // 维护一下递归遍历的高度，来看一下是哪一层。
    // int depth = 0;
    // std::vector<std::vector<int>> res;

    // void traverse(TreeNode *root)
    // {
    //     if (!root) return;

    //     ++depth;

    //     // 进入到这个结点的时候，判断是哪一层，然后加入到对应的位置。越界只可能越一个界。注意 0 号对应的是第一层。
    //     if (res.size() == depth - 1)
    //     {
    //         res.push_back({root->val});
    //     }
    //     else
    //     {
    //         res[depth - 1].emplace_back(root->val);
    //     }

    //     traverse(root->left), traverse(root->right);

    //     --depth;
    // }

    // std::vector<std::vector<int>> levelOrder(TreeNode *root)
    // {
    //     traverse(root);
    //     return res;
    // }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
