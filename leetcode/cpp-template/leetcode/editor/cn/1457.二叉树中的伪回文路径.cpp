/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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

    // 以例子 "333" 和 "3223" 来分析如何判断回文串。回文串的长度可能是偶数或者奇数，除了奇数的中心点以外，其他的元素都能找到另一个匹配的元素。因此，伪回文串的判断条件是路径上所有元素出现的次数，最多只有一个是奇数，奇数多出来的这一个元素就用来做中心点。

    int res = 0;

    // 需要用哈希表记录实时的元素和出现次数的映射关系，方便更新 oddNum。
    std::unordered_map<int, int> valToCount;

    // 我们另外维护一个变量，用于记录路径上元素出现的次数为奇数的个数。
    int oddNum = 0;


    void traverse(TreeNode *root)
    {
        if (!root) return;

        valToCount[root->val]++ & 1 ? --oddNum : ++oddNum;

        if (!root->left && !root->right && oddNum <= 1) ++res;

        traverse(root->left), traverse(root->right);

        valToCount[root->val]-- & 1 ? --oddNum : ++oddNum;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        traverse(root);
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
