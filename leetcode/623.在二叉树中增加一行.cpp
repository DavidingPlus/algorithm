/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

#include <iostream>
using namespace std;
#include <queue>

class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        // 层序遍历，找到depth-1的一层，然后修改对应的左子树和右子树
        if (nullptr == root)
            return nullptr;

        // 直接更改头节点需要特殊处理
        if (1 == depth) {
            auto newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode *> q;
        q.push(root);
        int dep = 0;  // 记录深度
        while (false == q.empty()) {
            ++dep;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                if (depth - 1 == dep) {
                    // 插入新节点
                    // 不能写在上面的if里面是因为，不管node的左右是否为空，都需要插入目标节点，画个图就知道了
                    auto newLeftNode = new TreeNode(val), newRightNode = new TreeNode(val);

                    newLeftNode->left = node->left;
                    node->left = newLeftNode;
                    newRightNode->right = node->right;
                    node->right = newRightNode;
                }
            }

            if (depth - 1 == dep)
                break;
        }
        return root;
    }
};
// @lc code=end
