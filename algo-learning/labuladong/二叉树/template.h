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

// 二叉树的两种思路：
// 1.从遍历二叉树出发，看能否遍历一次二叉树来完成工作
// 2.二叉树是自相似结构，看能否把二叉树的问题分解为规模更小的子树的问题，直到到达我们可以处理的地方
// 这两种思路时间复杂度是一样的，现在最好每个题都用这两种方法实现

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
