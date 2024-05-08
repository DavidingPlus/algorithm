/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] 二叉树中的链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string traverse_str = string();
    bool flag = false;  // 代表是否成功

    // 解法1，遍历这棵树
    void traverse(TreeNode *root, const string &list_str) {
        // 遍历到空的还没有判断成功，则表明不对，需要回退
        if (!root)
            return;

        // node_val在1到100之间，所以可以用ASCII码代表
        traverse_str += root->val;
        if (traverse_str.find(list_str) != string::npos) {
            flag = true;
            return;
        }

        traverse(root->left, list_str);
        traverse(root->right, list_str);

        // 回退，需要把元素删除
        traverse_str.pop_back();
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        string list_str = string();
        for (auto move = head; move; move = move->next)
            list_str += move->val;

        traverse(root, list_str);

        return flag;
    }

    // 解法2：将问题分解为类似的子问题
    // bool isSubPath_root(ListNode* head, TreeNode* root) {
    //     if (!head)
    //         return true;
    //     if (head && !root)
    //         return false;

    //     // 下面开始查看
    //     if (head->val != root->val)
    //         return false;
    //     return isSubPath_root(head->next, root->left) ||
    //            isSubPath_root(head->next, root->right);
    // }

    // bool isSubPath(ListNode* head, TreeNode* root) {
    //     if (!head)
    //         return true;
    //     if (head && !root)
    //         return false;

    //     // 三种情况可能匹配，当前根节点，左子树，右子树
    //     // 如果用之前错误的两个递归的话，肯定会导致head指针回不到最开始，就算可以回到，那么也会判断很多特殊情况，得不偿失
    //     return isSubPath_root(head, root) ||
    //            isSubPath(head, root->left) ||
    //            isSubPath(head, root->right);
    // }
};
// @lc code=end
