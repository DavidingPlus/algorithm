/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
#include <queue>
#include <vector>

class Solution {
public:
    // 思路和前面一样
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};

        vector<vector<int>> ret;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> layer;

            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                layer.push_back(cur->val);

                for (int j = 0; j < cur->children.size(); ++j)
                    if (cur->children[j])
                        q.push(cur->children[j]);

                q.pop();
            }

            ret.push_back(layer);
        }

        return ret;
    }
};
// @lc code=end
