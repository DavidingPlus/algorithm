/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include "_treenode.h"


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

    // 解法 1：最直观的做法，中序遍历导出为数组再判断
    // std::vector<int> res;

    // void traverse(TreeNode *root)
    // {
    //     if (!root) return;

    //     traverse(root->left);

    //     res.emplace_back(root->val);

    //     traverse(root->right);
    // }

    // bool isValidBST(TreeNode *root)
    // {
    //     traverse(root);

    //     for (int i = 0; i < res.size() - 1; ++i)
    //     {
    //         if (res[i] >= res[i + 1]) return false;
    //     }

    //     return true;
    // }


    // 解法 2：在中序遍历的过程中进行判断
    int pre = INT_MIN;
    bool flag = true, isRoot = true;

    void traverse(TreeNode *root)
    {
        if (!root) return;

        traverse(root->left);

        // 使用一个变量存储遍历上一次的值，用来判断中序遍历的结果是否都是递增的
        // leetcode 你是懂的，给一个根节点为 INT_MIN 的树，导致我还非得加一个 isRoot 的 bool 来进行判断
        if (isRoot || root->val > pre)
        {
            pre = root->val;

            if (isRoot) isRoot = false;
        }
        else
        {
            flag = false;
            return;
        }


        traverse(root->right);
    }

    bool isValidBST(TreeNode *root)
    {
        traverse(root);

        return flag;
    }


    // 解法 3：分解为自相似的子问题
    // bool isValidBST(TreeNode *root) { return isValidBSTWithRange(root, nullptr, nullptr); }

    // bool isValidBSTWithRange(TreeNode *root, TreeNode *min, TreeNode *max)
    // {
    //     // TODO 这里有一个坑，就是左右子树根节点满足条件并且左右子树也是 BST，整棵树不一定是 BST
    //     // 例子：(层序遍历) 5 4 6 null null 3 6，注意 3 在右子树，但是也符合上述条件

    //     // 所以我们这里需要判断左右子树的所有结点满足条件
    //     // 我们来看左子树满足什么条件：它的所有值都小于根节点，右子树相反
    //     // 所以可以维护两个值来记录过程中的最大和最小值
    //     // 注意，在本题二叉搜索树的语境中，这个最大值和最小值是不能被取到的，是开区间

    //     // 由于有数据为 int 类型的边界数据，我们用结点指针表示

    //     if (!root) return true;

    //     if (min && root->val <= min->val) return false;
    //     if (max && root->val >= max->val) return false;

    //     return isValidBSTWithRange(root->left, min, root) && isValidBSTWithRange(root->right, root, max);
    // }
};

// @lc code=end
