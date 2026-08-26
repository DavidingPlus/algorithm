/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

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

class Solution
{

public:

    const std::string SEP = ",";

    const std::string NULL_CHAR = "#";

    // 存储题目要的结果。
    std::vector<TreeNode *> res;

    // 存储序列化结果。
    std::unordered_map<std::string, int> um;


    // 这个函数代表后序遍历完某个结点时的序列化结果。
    std::string postSerialize(TreeNode *root)
    {
        if (!root) return NULL_CHAR + SEP;

        // 为了比较是否子树是否相同，我们需要通过后序获得当前节点的后序序列化字符串。
        // 这个序列化也是一个后序遍历的过程，所以我们把判断也写在里面了，提高效率。

        std::string s;

        s += postSerialize(root->left);
        s += postSerialize(root->right);

        s += std::to_string(root->val) + SEP;

        // 把已经有的序列化结果存储到哈希表中。使用等号判断保证只加一次。
        if (1 == um[s]++) res.emplace_back(root);


        return s;
    }

    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        postSerialize(root);
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;

    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   2   4
    //          /
    //         4
    //
    // 重复的子树根节点值应为 4 和 2。
    std::vector<std::optional<int>> values{
        1, 2, 3, 4, std::nullopt, 2, 4,
        std::nullopt, std::nullopt, 4};
    TreeNode *root = TreeNode::createRoot(values);

    std::vector<TreeNode *> duplicates = solution.findDuplicateSubtrees(root);

    std::cout << "duplicate subtree roots: ";
    for (TreeNode *node : duplicates) std::cout << node->val << ' ';
    std::cout << std::endl;

    TreeNode::freeTree(root);
}
