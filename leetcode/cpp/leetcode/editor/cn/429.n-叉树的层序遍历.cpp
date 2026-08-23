/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    // 思路和前面一样
    std::vector<std::vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};

        std::vector<std::vector<int>> ret;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> layer;

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


int main()
{
    Solution solution;
    // your test code here
}
