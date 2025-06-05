/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#include <cmath>
#include <list>
#include <queue>
#include <string>
#include <vector>

// 层序遍历方法
// 混了，下次写...
// TODO
// 这个方法的好处是，每一层能够准确的给出下一层元素的个数
// 就是每一层非空的元素 * 2 就是 下一层的所有节点的个数，然后只有非空的节点是有效的
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    }
};

// 前序遍历方法
// class Codec {
// public:
//     void traverse(TreeNode* root, string& str) {
//         // 元素之间用空格分开
//         if (nullptr == root) {
//             str += "#,";
//             return;
//         }

//         str += to_string(root->val) + ",";

//         traverse(root->left, str);
//         traverse(root->right, str);
//     }

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string res;

//         traverse(root, res);

//         // 把末尾的','去掉
//         res.pop_back();

//         return res;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         // split
//         stringstream ss(data);
//         string item;
//         list<string> nodes;
//         while (getline(ss, item, ','))
//             if (!item.empty())
//                 nodes.push_back(item);

//         return deserialize(nodes);
//     }

//     TreeNode* deserialize(list<string>& nodes) {
//         // 前序遍历只维护节点的信息是没办法还原成为二叉树的
//         // 但是现在我们维护有空指针的信息，每一个位置就是一个节点
//         // 我们按照前序的方式去遍历就可以了
//         if (nodes.empty())
//             return nullptr;

//         string str = nodes.front();
//         // 这里弹出头部不要用vector，他还要一步一步的挪，用list
//         nodes.pop_front();  // 这一步弹出的操作很关键，为了保证子问题拿到的数据和原问题自洽
//         if ("#" == str)
//             return nullptr;

//         TreeNode* root = new TreeNode(atoi(str.c_str()));
//         // 递归处理左右子树
//         root->left = deserialize(nodes);
//         root->right = deserialize(nodes);

//         return root;
//     }
// };

// Your Codec object will be instantiated && called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
