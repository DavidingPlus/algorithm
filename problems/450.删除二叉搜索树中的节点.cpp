/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        // 自己画图分析得出四种情况，根据左右子树是否为空得出的
        if (nullptr == root)
            return nullptr;

        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        // 相等就代表需要进行删除
        else if (key == root->val) {
            // 1.左右子树都为空，直接删除节点
            if (nullptr == root->left && nullptr == root->right)
                return nullptr;
            // 2.左右子树有一个不为空，返回非空的那个节点
            if (!(root->left && root->right))
                return root->left ? root->left : root->right;
            // 3.左右子树都不为空，返回右子树里面最小的那个
            else
                return doWork(root);
        }

        return root;
    }

    // 这个函数用于将右子树里面最小的删除并且将他的值覆盖掉根节点的值
    // 内部调用，我们保证这棵树具有左右子树
    TreeNode *doWork(TreeNode *root) {
        if (nullptr == root)
            return nullptr;

        // 拿到右子树最小的节点，并且这里我需要他的父节点
        auto p = root->right;
        auto fa = root;
        while (p->left) {
            fa = p;
            p = p->left;
        }
        // 这个节点可能还有右子树，所以不能直接返回nullptr
        // 这个fa可能是root，也可能是右子树往左走的父节点，这个需要分情况
        if (root == fa)
            fa->right = p->right;
        else
            fa->left = p->right;

        root->val = p->val;

        return root;
    }

    /* 第一次做的时候的解法，里面的注释写的还不错，所以就留着了。 */
    // // 这个题非常经典，是二叉搜索树以及递归修改数据结构的典型例子!!!
    // TreeNode *deleteNode(TreeNode *root, int key) {
    //     if (nullptr == root)
    //         return nullptr;

    //     // 我们先试着递归查找到目标结点，注意递归修改数据结构的规则
    //     if (key < root->val)
    //         // 这样既做到了查找，又做到了链接(在原来的基础上链接无所谓)
    //         root->left = deleteNode(root->left, key);
    //     else if (key > root->val)
    //         root->right = deleteNode(root->right, key);
    //     // 开始真正的删除
    //     else if (key == root->val) {
    //         // 如果为叶节点，那么直接删除
    //         if (nullptr == root->left && nullptr == root->right)
    //             return nullptr;
    //         // 如果只存在左子树或者右子树，那么将子树接在父结点上
    //         if (root->left && nullptr == root->right)
    //             return root->left;
    //         if (root->right && nullptr == root->left)
    //             return root->right;
    //         // 如果左右子树都有，需要考虑一下了
    //         else {
    //             // 画个图，我们只需要把左子树中最大的元素或者右子树中最小的元素变为头结点即可
    //             // 我们以左子树最大的元素为例，它必然不可能有右子树
    //             // 所以在接到根节点的时候，我们需要把这个结点的左子树接给他的父节点来保证结构
    //             auto leftmax = get_leftmax(root->left);
    //             root->left = remove_leftmax(root->left);

    //             // 修改一些值
    //             leftmax->left = root->left;
    //             leftmax->right = root->right;
    //             root = leftmax;
    //         }
    //     }

    //     return root;
    // }

    // // 这个函数用于查找二叉搜索树当中最大元素的结点
    // TreeNode *get_leftmax(TreeNode *root) {
    //     auto p = root;
    //     while (p->right)
    //         p = p->right;

    //     return p;
    // }

    // // 这个函数用于将二叉搜索当中最大元素的结点删除，注意递归修改数据结构
    // TreeNode *remove_leftmax(TreeNode *root) {
    //     if (nullptr == root->right)
    //         // 这里不能直接返回空，因为这个子树可能还有左子树
    //         return root->left;

    //     root->right = remove_leftmax(root->right);

    //     return root;
    // }
};
// @lc code=end
