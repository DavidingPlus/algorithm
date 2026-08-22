/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start

class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, std::vector<Node *> _children)
        : val(_val), children(std::move(_children)) {}
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    std::vector<int> ret;

    std::vector<int> postorder(Node* root) {
        if (!root)
            return {};

        for (auto child : root->children)
            postorder(child);

        ret.push_back(root->val);

        return ret;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
