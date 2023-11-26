/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool flag = true;
    vector<int> tmp;

    // 方法1：中序遍历
    bool isValidBST(TreeNode *root) {
        traverse(root);
        return flag;
    }

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        traverse(root->left);

        // 我们每次都保证插入的元素都是已知的数组里面最大的，这样插进去的必然有序，所以就只用判断末尾的值
        if (false == tmp.empty() and root->val <= tmp.back()) {
            flag = false;
            return;
        }
        tmp.emplace_back(root->val);

        traverse(root->right);
    }

    // 方法2：转化为子问题
    // bool isValidBST(TreeNode *root) {
    //     // 这里有一个坑，就是左右子树根节点满足条件并且左右子树也是BST，整棵树不一定是BST
    //     // 例子：(层序遍历) 5 4 6 null null 3 7，注意3在右子树，但是他也符合上述条件

    //     // 所以我们这里需要判断左右子树的所有结点满足条件
    //     // 我们来看左子树满足什么条件：它的所有值都小于根节点，右子树相反
    //     // 所以可以维护两个值来记录过程中的最大和最小值

    //     // 由于有数据为int类型的边界数据，我们用结点表示
    //     return isValidBST(root, nullptr, nullptr);
    // }

    // // 这个函数用来判断这个树的所有值都在(min->val,min->val)之间
    // bool isValidBST(TreeNode *root, TreeNode *max, TreeNode *min) {
    //     if (nullptr == root)
    //         return true;

    //     // 如果max或者min为空，就代表目前来说没有限制
    //     // 判断当前结点是否符合要求，在判断左右子树是否符合要求
    //     // 在过程中需要实时更新最大值和最小值的要求
    //     if (max && root->val >= max->val)
    //         return false;
    //     if (min && root->val <= min->val)
    //         return false;

    //     return isValidBST(root->left, root, min) &&
    //            isValidBST(root->right, max, root);
    // }
};
// @lc code=end
