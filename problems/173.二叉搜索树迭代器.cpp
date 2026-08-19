/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
#include <stack>
#include <vector>

class BSTIterator {
public:
    // 自己的方法：时间复杂度高
    // vector<int> vals;

    // // 二叉搜索树的中序遍历就是按照顺序排序的结果
    // void traverse(TreeNode *root) {
    //     if (nullptr == root)
    //         return;

    //     traverse(root->left);

    //     vals.push_back(root->val);

    //     traverse(root->right);
    // }

    // BSTIterator(TreeNode *root) {
    //     traverse(root);
    // }

    // int next() {
    //     int ret = vals.front();

    //     vals.erase(vals.begin(), vals.begin() + 1);

    //     return ret;
    // }

    // bool hasNext() {
    //     return !vals.empty();
    // }

    // 另一个办法：非常清晰，理解重要！
    // 这是迭代的题目的模板
    // 我们不能直接把中序遍历的结果存进去，而是用多少存多少
    // 我们需要模拟中序遍历的过程

    // 用一个栈来存储遍历的结果
    stack<TreeNode *> s;

    // 左子树一直到底
    void push_left_branch(TreeNode *p) {
        while (p) {
            s.push(p);
            p = p->left;
        }
    }

    BSTIterator(TreeNode *root) {
        push_left_branch(root);
    }

    int next() {
        // 我们需要保证要next的时候我的栈中都是有元素的
        // 所以每次我弹出元素，我都把这个结点的右子树的全部元素入栈，这也是遍历的顺序
        auto node = s.top();
        s.pop();

        push_left_branch(node->right);

        return node->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated && called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
