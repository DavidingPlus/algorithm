/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

struct TreeNode
{
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

#include <bits/stdc++.h>


class Solution
{

public:

    // TODO

    // 第一种思路：遍历一次二叉树
    int minDepth(TreeNode *root) {}


    // 第二种思路：将大问题分解为小问题
    // int minDepth(TreeNode *root) {}


    // 第三种思路：层次遍历，在广度搜索的情况下如果遇到叶节点，那么就是最小的深度
    // 我们比较一下深度优先和广度优先，广度优先的优势在于，求最小的问题的时候一般可以不用把整个结构遍历完，比如这里就是遍历一部分就得出答案了，在这里效率会比深度优先会快很多!!
    // int minDepth(TreeNode *root) {}
};

// @lc code=end
