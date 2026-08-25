#include <cassert>
#include <iostream>
#include <optional>

#include "../TreeNode.h"


int main()
{
    assert(TreeNode::createRoot({}) == nullptr);
    assert(TreeNode::createRoot({std::nullopt}) == nullptr);

    TreeNode *root = TreeNode::createRoot({1, 2, 3, 4, 5, std::nullopt, 7});
    assert(root != nullptr);
    assert(root->val == 1);
    assert(root->left != nullptr && root->left->val == 2);
    assert(root->right != nullptr && root->right->val == 3);
    assert(root->left->left != nullptr && root->left->left->val == 4);
    assert(root->left->right != nullptr && root->left->right->val == 5);
    assert(root->right->left == nullptr);
    assert(root->right->right != nullptr && root->right->right->val == 7);

    std::cout << "TreeNode:" << std::endl;
    TreeNode::print(root);

    TreeNode::freeTree(root);
    std::cout << "TreeNode test passed" << std::endl;
}
