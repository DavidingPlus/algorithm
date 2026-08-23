/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

#include "../common/globalmacros.h"
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

// class Node {
// public:
//     int val;
//     std::vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, std::vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


class Solution {
public:
    std::vector<int> ret;

    std::vector<int> preorder(Node* root) {
        if (!root)
            return {};

        ret.push_back(root->val);
        for (auto child : root->children)
            preorder(child);

        return ret;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
