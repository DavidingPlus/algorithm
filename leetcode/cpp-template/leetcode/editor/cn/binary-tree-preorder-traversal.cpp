#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    std::vector<int> res;

    // 返回前序遍历结果
    std::vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }

    // 二叉树遍历函数
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // 前序遍历位置
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    // your test code here
    Solution solution;
    TreeNode *root = TreeNode::createRoot({1, 22, 3, 4, 5, std::nullopt, 8, std::nullopt, std::nullopt, 6, 7, 9});
    std::vector<int> result = solution.preorderTraversal(root);
    for (int val : result) {
        std::cout << val << " ";
    }
}
