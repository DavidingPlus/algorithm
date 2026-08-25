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

class Solution {
public:
    std::vector<TreeNode *> res;
    std::unordered_map<std::string, int> um;  // 存储序列化结果

    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        postSerialize(root);
        return res;
    }

    // 为了比较是否子树是否相同，我们需要通过后序获得当前节点的后序序列化字符串
    // 这个序列化也是一个后序遍历的过程，所以我们把判断也写在里面了，提高效率
    std::string postSerialize(TreeNode *root) {
        if (nullptr == root)
            return "#";

        std::string left = postSerialize(root->left);
        std::string right = postSerialize(root->right);
        std::string myself = left + "," + right + "," + std::to_string(root->val);

        // 把已经有的序列化结果存储到哈希表中
        if (1 == um[myself])
            res.push_back(root);
        ++um[myself];

        return myself;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
