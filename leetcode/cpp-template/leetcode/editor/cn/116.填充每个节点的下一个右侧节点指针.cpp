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

    // 将根节点入队。
    // 将某一层的节点出队，并且加入下层节点。
    // 记录当前层数节点个数，因为 q 的大小一直在变。

    // 解法 1：层序遍历。
    Node *connect(Node *root)
    {
        if (!root) return nullptr;
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
    // your test code here
}
