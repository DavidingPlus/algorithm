/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
#include <vector>

class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        // 在preorder当中，除了根节点，第一个小于它的值，就是左子树的根节点；第一个大于他的值就是右子树的根节点

        return bstFromPreorder(preorder, 0, preorder.size() - 1);
    }

    // left和right是我要处理的preorder的区间，范围是[left,right]
    TreeNode *bstFromPreorder(vector<int> &preorder, int left, int right) {
        // 如果left大于right，则表明该子树不存在
        if (left > right)
            return nullptr;

        int root_val = preorder[left];
        // 找到第一个小于首元素的值和第一个大于首元素的位置
        // 理论上来说大于的第一个位置就是首元素加1，如果不存在那么就和max_pos相等，这样就可以判断了
        int pos = left + 1;
        // 如果右子树不存在则会越界，left大于right,这样就会返回nullptr
        // 如果左子树不存在则由于pos-1，则left还是大于right，还是返回nullptr
        // 所以注意条件是left>right，不取等号
        while (pos <= right && preorder[pos] < root_val)
            ++pos;

        TreeNode *root = new TreeNode(root_val);
        root->left = bstFromPreorder(preorder, left + 1, pos - 1);
        root->right = bstFromPreorder(preorder, pos, right);

        return root;
    }
};
// @lc code=end
