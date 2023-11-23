/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <iostream>
using namespace std;
#include <queue>

class Solution {
public:
    // 方法1，层序遍历
    Node* connect(Node* root) {
        if (nullptr == root)
            return nullptr;

        // 将头结点入队列
        queue<Node*> q;
        q.push(root);

        while (false == q.empty()) {
            // q.size()会一直变化，需要提前存储
            int n = q.size();

            // 一次拿出一层，对该节点做处理并且把左右子树入队列
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                if (i != n - 1)
                    node->next = q.front();
                else
                    node->next = nullptr;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return root;
    }
};
// @lc code=end
