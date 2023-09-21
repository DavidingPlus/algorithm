#ifndef _Template_H_
#define _Template_H_

#include <iostream>
#include <vector>
using namespace std;

// 二叉树的数据结构表示
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 二叉树算法的两个核心问题：
// 当前结点应该去做什么事情？
// 什么时候去做这件事情？

// 二叉树遍历框架
void traverse(TreeNode *root) {
    if (!root)
        return;

    // 我们用三个vector来存储不同的遍历结果
    vector<int> pre_order;
    vector<int> in_order;
    vector<int> post_order;

    // 访问该节点有三个时机，第一个是刚到这个节点，第二个是访问完左子树回到这个节点，第三个是访问完右子树最后回到这个结点
    // 这三个节点就构成了三种不同的访问机制

    // 前序遍历位置，代码写在这里
    pre_order.push_back(root->val);

    traverse(root->left);

    // 中序遍历位置，代码写在这里
    in_order.push_back(root->val);

    traverse(root->right);

    // 后序遍历位置，代码写在这里
    post_order.push_back(root->val);
}

#endif
