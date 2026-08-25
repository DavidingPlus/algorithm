/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

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

class Solution
{

public:

    // 完美二叉树：每层都填满。
    // 完全二叉树：最后一层可以不满，但必须从左往右填。
    // 所有完美二叉树都是完全二叉树，但反过来不一定成立。

    // 解法 1：层序遍历。
    Node *connect(Node *root)
    {
        if (!root) return nullptr;

        std::queue<Node *> q;
        // 将根节点入队。
        q.push(root);

        while (!q.empty())
        {
            // 记录当前层数节点个数，因为 q 的大小一直在变。
            int n = q.size();
            // 将某一层的节点出队，并且加入下层节点。
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front();
                q.pop();

                node->next = i < n - 1 ? q.front() : nullptr;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }


        return root;
    }

    // TODO 解法 2：将完美二叉树抽象为一颗三叉树。
    // Node *connect(Node *root)
    // {
    // }
};
// @lc code=end


int main()
{
    Solution solution;

    // 空树。
    std::cout << "[TEST] empty tree" << std::endl;
    assert(solution.connect(nullptr) == nullptr);
    std::cout << "[PASS] empty tree" << std::endl;

    // 单节点树：根节点没有右侧节点。
    {
        std::cout << "[TEST] single-node tree" << std::endl;
        Node *root = Node::createRoot({1});
        assert(solution.connect(root) == root);
        Node::printNext(root);
        assert(root->next == nullptr);
        std::cout << "[PASS] single-node tree" << std::endl;
        Node::freeTree(root);
    }

    // 两层完美二叉树。
    {
        std::cout << "[TEST] two-level perfect tree" << std::endl;
        Node *root = Node::createRoot({1, 2, 3});
        assert(solution.connect(root) == root);
        Node::printNext(root);
        assert(root->next == nullptr);
        assert(root->left->next == root->right);
        assert(root->right->next == nullptr);
        std::cout << "[PASS] two-level perfect tree" << std::endl;
        Node::freeTree(root);
    }

    // 三层完美二叉树：检查每一层的 next 链，并确认每层末尾为 nullptr。
    {
        std::cout << "[TEST] three-level perfect tree" << std::endl;
        Node *root = Node::createRoot({1, 2, 3, 4, 5, 6, 7});

        // 预先写入错误连接，验证 connect 会覆盖已有的 next 指针。
        root->next = root->left;
        root->left->next = root->left->left;
        root->right->next = root->right->right;

        assert(solution.connect(root) == root);
        Node::printNext(root);
        assert(root->next == nullptr);
        assert(root->left->next == root->right);
        assert(root->right->next == nullptr);
        assert(root->left->left->next == root->left->right);
        assert(root->left->right->next == root->right->left);
        assert(root->right->left->next == root->right->right);
        assert(root->right->right->next == nullptr);

        std::cout << "[PASS] three-level perfect tree" << std::endl;
        Node::freeTree(root);
    }

    std::cout << "116 tests passed" << std::endl;
}
