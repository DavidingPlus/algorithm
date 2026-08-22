/*
 * @lc app=leetcode.cn id=919 lang=cpp
 * @lcpr version=20003
 *
 * [919] 完全二叉树插入器
 */

// @lc code=start

#include <bits/stdc++.h>

#include "_treenode.h"


class CBTInserter
{

public:

    TreeNode *m_tree = nullptr;

    int m_size = 0;

    CBTInserter(TreeNode *root) : m_tree(root)
    {
        // 通过广度遍历拿到节点的个数
        std::queue<TreeNode *> q;
        q.push(m_tree);

        if (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                ++m_size;

                auto node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }

    int insert(int val)
    {
        // TODO 给出数学证明
        // 我们知道节点的编号 x，那么就可以从高到低遍历 x 的每一个二进制位（忽略最高位的 1），如果为 0 就往左子节点移动，否则往右子节点移动，这样就可以到达节点需要被插入的位置。
    }

    TreeNode *get_root() { return m_tree; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

// @lc code=end


int main()
{
}
