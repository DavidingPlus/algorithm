/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{

public:

    // // 解法 1：验证中序遍历是否严格升序。
    // bool isValidBST(TreeNode *root)
    // {
    //     traverse(root);
    //     return res;
    // }

    // void traverse(TreeNode *root)
    // {
    //     if (!root) return;

    //     traverse(root->left);

    //     if (pre >= static_cast<long long>(root->val))
    //     {
    //         res = false;
    //         return;
    //     }

    //     pre = static_cast<long long>(root->val);

    //     traverse(root->right);
    // }


    // bool res = true;

    // // 使用一个变量存储遍历上一次的值，用来判断中序遍历的结果是否都是递增的。
    // // leetcode 你是懂的，给一个根节点为 std::numeric_limits<int>::min() 的树，导致需要开 long long。
    // // 在 C++ 里，int、long、long long 是不同的整数类型，但 long 不保证比 int 更宽：
    // // 1. int 通常是 32 位。
    // // 2. long 的宽度看平台：Windows 上通常也是 32 位；Linux 上通常是 64 位。
    // // 3. long long 至少 64 位，适合这里用作 int 值的更大范围初始哨兵。
    // long long pre = std::numeric_limits<long long>::min();


    // 解法 2：分解为自相似的子问题。
    bool isValidBST(TreeNode *root) { return isValidBSTWithRange(root, nullptr, nullptr); }

    // 对于一个 root，左右子树的根节点和 root 比较满足 BST 的条件，同时左右子树也是 BST，加起来不能判断整棵树是不是 BST。例如：左子树一直往右延申，直到超过根节点的值。
    // 因此还需要额外给左右子树限制范围，比如左子树的结点值不能大于等于根节点的值，右子树不能小于等于，这个通过函数参数传递。
    // 该函数返回 root 为根的子树的所有节点是否满足 max->val > root->val > min->val。
    bool isValidBSTWithRange(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        // XXX 这里有一个坑，就是左右子树根节点满足条件并且左右子树也是 BST，整棵树不一定是 BST。
        // 例子：（层序遍历）5 4 6 null null 3 6，注意 3 在右子树，但是也符合上述条件。

        // 所以我们这里需要判断左右子树的所有结点满足条件。
        // 我们来看左子树满足什么条件：它的所有值都小于根节点，右子树相反。
        // 所以可以维护两个值来记录过程中的最大和最小值。
        // 注意，在本题二叉搜索树的语境中，这个最大值和最小值是不能被取到的，是开区间。

        // 由于有数据为 int 类型的边界数据，我们用结点指针表示。

        if (!root) return true;

        // if (root->left && root->val <= root->left->val) return false;
        // if (root->right && root->val >= root->right->val) return false;

        // 上面的条件会在这两行被跑到。
        // 以左孩子为例，设当前节点是 root。递归调用是：isValidBSTWithRange(root->left, min, root)。也就是把当前节点 root 作为左孩子的 max。递归进入左孩子后，这个判断：if (max && root->val >= max->val) return false; 实际检查的就是“左孩子的值是否大于等于父节点的值”，和局部判断。和 if (root->left && root->val <= root->left->val) return false; 完全等价。右孩子同理：递归时父节点作为孩子的 min，会检查孩子是否小于等于父节点。
        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;


        return isValidBSTWithRange(root->left, min, root) && isValidBSTWithRange(root->right, root, max);
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
