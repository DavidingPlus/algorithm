#ifndef _SIMULATE_H_
#define _SIMULATE_H_

#include <iostream>
#include <vector>
using namespace std;
#include <stack>

// 二叉树的数据结构表示
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

stack<TreeNode *> stk;

// 用迭代来模拟递归函数，需要用到栈，后进来的先出去
vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;

// 这个函数用来一口气往左走
void pushLeftBranch(TreeNode *root) {
    auto move = root;
    while (nullptr != move) {
        /*******前序遍历代码位置*******/
        pre_order.push_back(move->val);

        stk.push(move);
        move = move->left;
    }
}

void traverse(TreeNode *root) {
    // 我们引入一个visited变量来记录上一次遍历完毕的子树根节点
    TreeNode *visited = new TreeNode;

    // 开始遍历这棵树，先往左走
    pushLeftBranch(root);

    // 当栈为空的时候就代表遍历完毕了
    // 如果root为空的话，就不会进入到这个循环，所以不需要进行特殊判断
    // 进到这个循环代表走到了能够走到的最左边的位置
    while (!stk.empty()) {
        // 拿出栈顶元素，因为我们准备遍历这个元素的右子树
        TreeNode *p = stk.top();

        // p的左子树被遍历完了，并且右子树还没有被遍历
        // 我们如何对这个进行判断呢？我们需要引入一个visited变量来记录上一次遍历完毕的子树根节点
        if ((nullptr == p->left || visited == p->left) && visited != p->right) {
            /*******中序遍历代码位置*******/
            in_order.push_back(p->val);

            // 开始对右子树进行遍历
            pushLeftBranch(p->right);
        }
        // p的右子树被遍历完了，这代表需要回退
        if (nullptr == p->right || visited == p->right) {
            /*******后序遍历代码位置*******/
            post_order.push_back(p->val);

            // 以p为根节点的子树被遍历完了，更新visited变量
            visited = stk.top();
            stk.pop();
        }
    }
}

#endif
