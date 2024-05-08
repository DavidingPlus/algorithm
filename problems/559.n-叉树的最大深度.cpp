/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int depth = 0;  // 用depth变量维护到该结点位置的深度
    int ret = 0;    // 记录最大深度

    // 第一种思路，我们遍历一遍这个N叉树
    void traverse(Node* root) {
        if (!root)
            return;

        ++depth;                // 到达一个新的结点深度++
        ret = max(ret, depth);  // 这个结点的深度需要进行比较

        for (auto child : root->children)
            traverse(child);

        --depth;  // 回退
    }

    int maxDepth(Node* root) {
        traverse(root);
        return ret;
    }

    // 还是两种思路，这是第二种
    // int maxDepth(Node* root) {
    //     if (!root)
    //         return 0;

    //     int ret = 0;
    //     for (auto child : root->children)
    //         // 获得当前节点的所有子树的最大深度
    //         ret = max(ret, maxDepth(child));

    //     return 1 + ret;
    // }
};
// @lc code=end
