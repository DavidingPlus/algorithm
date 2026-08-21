/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> ret;

    vector<int> preorder(Node* root) {
        if (!root)
            return {};

        ret.push_back(root->val);
        for (auto child : root->children)
            preorder(child);

        return ret;
    }
};
// @lc code=end
