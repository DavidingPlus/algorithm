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
    queue<TreeNode *> q;
    int height = 0;

    // 用层序遍历找到应该插入的位置，就是在depth-1的所有结点下面添加结点
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (nullptr == root)
            return nullptr;

        // depth==1的情况特判
        if (1 == depth) {
            TreeNode *newroot = new TreeNode(val);
            newroot->left = root;
            root = newroot;

            return root;
        }

        q.push(root);

        while (!q.empty()) {
            ++height;  // 这里的height至少为1，因此要特判depth==1的情况

            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();

                // 插入
                if (height == depth - 1) {
                    insert(cur, val);
                    // 插完之后没必要继续循环了
                    if (i == sz - 1)
                        return root;
                }

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
        }

        return root;
    }

    // 这个函数用于在目标节点后面插入结点，我们保证root有值
    void insert(TreeNode *root, int val) {
        TreeNode *newleft = new TreeNode(val),
                 *newright = new TreeNode(val);

        newleft->left = root->left;
        newright->right = root->right;
        root->left = newleft;
        root->right = newright;
    }
};
// @lc code=end
