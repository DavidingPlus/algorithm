/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

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
#include <unordered_map>
#include <vector>

const int N = 1e3 + 10;

class Solution {
public:
    int ret = 0;                 // 维护答案
    int path[N] = {0};           // 定义路径数组
    long long pre_sum[N] = {0};  // 定义前缀和数组
    int depth = 0;               // 维护新元素在遍历当中的位置

    // 思路1：遍历一次二叉树
    void traverse(TreeNode *root, int targetSum) {
        if (nullptr == root)
            return;

        ++depth;
        path[depth] = root->val;
        pre_sum[depth] = pre_sum[depth - 1] + path[depth];

        // 每次前序进来之后，多出的和就是以该节点为结尾的路径，所以我们计算这部分的值
        for (int i = 1; i <= depth; ++i)
            if (targetSum == pre_sum[depth] - pre_sum[i - 1])
                ++ret;

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        --depth;
    }

    int pathSum(TreeNode *root, int targetSum) {
        traverse(root, targetSum);

        return ret;
    }

    // // 思路2：将大问题转化为小问题
    // void traverse(TreeNode *root, int targetSum, long long &count, long long &sum) {
    //     if (nullptr == root)
    //         return;

    //     sum += root->val;
    //     if (targetSum == sum)
    //         ++count;

    //     traverse(root->left, targetSum, count, sum);
    //     traverse(root->right, targetSum, count, sum);

    //     sum -= root->val;
    // }

    // // 这个函数表示以root为根节点的路径个数
    // int pathSum_root(TreeNode *root, int targetSum) {
    //     long long count = 0, sum = 0;
    //     traverse(root, targetSum, count, sum);

    //     return count;
    // }

    // int pathSum(TreeNode *root, int targetSum) {
    //     if (nullptr == root)
    //         return 0;

    //     return pathSum_root(root, targetSum) +
    //            pathSum(root->left, targetSum) +
    //            pathSum(root->right, targetSum);
    // }
};

// @lc code=end
