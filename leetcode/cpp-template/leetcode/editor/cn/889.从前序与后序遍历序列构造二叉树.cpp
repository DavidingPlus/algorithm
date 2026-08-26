/*
 * @lc app=leetcode.cn id=889 lang=cpp
 * @lcpr version=30404
 *
 * [889] 从前序与后序遍历序列构造二叉树
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

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

    // 因为需要在 postorder 里面查询某个具体值的下标，为了节省时间，使用一个哈希表存储反向映射。
    std::unordered_map<int, int> valueToIndex;


public:

    TreeNode *constructFromPrePostFromRange(std::vector<int> &preorder, int preorderLeft, int preorderRight, std::vector<int> &postorder, int postorderLeft, int postorderRight)
    {
        // 当前前序区间为空，说明当前子树不存在。
        if (preorderLeft > preorderRight) return nullptr;

        // 当前区间只有一个节点时，它就是叶子节点。这里必须直接返回，因为下面需要访问 preorder[preorderLeft + 1]，而单节点区间中并不存在这个下标。
        // 这是和其他两道题不一样的地方，也是需要注意的地方。
        if (preorderLeft == preorderRight) return new TreeNode(preorder[preorderLeft]);

        // 前序遍历和后序遍历无法唯一确认一棵树，因为子树的连接策略可能不同。
        // 以 preorder = [1,2,4,5,3,6,7] 为例，首先找到根节点 1，然后下一个结点 2，由于没有中序遍历明确结点边界，我们无法直到 2 是左子树还是右子树，这里我们采取的策略是左子树策略，我们认为 2 是左子树的第一个结点。
        // 然后我们去 postorder = [4,5,2,6,7,3,1] 中找到结点 2，因此结点 4 和 5 属于结点 2 的子树，因此在前序遍历中 2、4、5 都是属于根结点的左子树的，其他结点一定不属于根节点的左子树，因为根节点左子树的第一个值是 2，如果属于，在后序遍历中一定在 2 结点左侧能遍历到这些结点，但实际上并没有，因此后续遍历右侧的结点只能属于根节点的右子树（除开后序遍历的末尾元素，那个就是对称的 root）。这样就明确了左右子树边界。

        int leftRootPostOrder = valueToIndex[preorder[1 + preorderLeft]];

        // 左子树节点数量：左子树根节点下标 - 后序区间起点 + 1。
        int leftSize = leftRootPostOrder - postorderLeft + 1;

        TreeNode *root = new TreeNode(preorder[preorderLeft]);

        // 前序遍历：根节点之后的 leftSize 个节点属于左子树。
        // 后序遍历：从 postorderLeft 到 leftRootPostOrder 属于左子树。后序遍历的最后一个节点是当前根节点，因此右子树的后序区间需要排除 postorderRight。
        root->left = constructFromPrePostFromRange(
            preorder,
            1 + preorderLeft,
            preorderLeft + leftSize,
            postorder,
            postorderLeft,
            leftRootPostOrder);
        root->right = constructFromPrePostFromRange(
            preorder,
            1 + preorderLeft + leftSize,
            preorderRight,
            postorder,
            1 + leftRootPostOrder,
            postorderRight - 1);


        return root;
    }

    TreeNode *constructFromPrePost(std::vector<int> &preorder, std::vector<int> &postorder)
    {
        for (int i = 0; i < postorder.size(); ++i) valueToIndex[postorder[i]] = i;


        return constructFromPrePostFromRange(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

// @lc code=end


int main()
{
    Solution solution;

    std::vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
    std::vector<int> postorder{4, 5, 2, 6, 7, 3, 1};

    TreeNode *root = solution.constructFromPrePost(preorder, postorder);

    std::vector<int> actualPreorder;
    std::vector<int> actualPostorder;

    std::function<void(TreeNode *)> collectPreorder =
        [&](TreeNode *node)
    {
        if (!node) return;

        actualPreorder.push_back(node->val);
        collectPreorder(node->left);
        collectPreorder(node->right);
    };

    std::function<void(TreeNode *)> collectPostorder =
        [&](TreeNode *node)
    {
        if (!node) return;

        collectPostorder(node->left);
        collectPostorder(node->right);
        actualPostorder.push_back(node->val);
    };

    collectPreorder(root);
    collectPostorder(root);

    std::cout << std::boolalpha
              << "preorder correct: " << (actualPreorder == preorder) << std::endl
              << "postorder correct: " << (actualPostorder == postorder) << std::endl;

    TreeNode::freeTree(root);
}


/*
// @lcpr case=start
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */
