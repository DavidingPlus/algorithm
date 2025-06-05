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

        queue<Node*> q;
        // 将根节点入队
        q.push(root);
        while (false == q.empty()) {
            // 将某一层的节点出队，并且加入下层节点
            int n = q.size();  // 记录当前层数节点个数，因为q的大小一直在变
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                // 本题逻辑，连接下一个位置
                if (n - 1 != i)
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

    // 解法2：将完美二叉树抽象为一颗三叉树
    // TODO
    // Node* connect(Node* root) {}
};
// @lc code=end
