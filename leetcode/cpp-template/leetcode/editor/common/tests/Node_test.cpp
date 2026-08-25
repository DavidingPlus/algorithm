#include <cassert>
#include <iostream>

#include "../Node.h"


int main()
{
    assert(Node::createRoot({}) == nullptr);

    Node *root = Node::createRoot({1, 2, 3, 4, 5, 6, 7});
    assert(root != nullptr);
    assert(root->val == 1);
    assert(root->left != nullptr && root->left->val == 2);
    assert(root->right != nullptr && root->right->val == 3);
    assert(root->left->left != nullptr && root->left->left->val == 4);
    assert(root->right->right != nullptr && root->right->right->val == 7);

    // 模拟 116 题完成连接后的 next 链。
    root->left->next = root->right;
    root->left->left->next = root->left->right;
    root->left->right->next = root->right->left;
    root->right->left->next = root->right->right;

    assert(root->next == nullptr);
    assert(root->left->next == root->right);
    assert(root->left->left->next == root->left->right);
    assert(root->right->right->next == nullptr);

    std::cout << "Node:" << std::endl;
    Node::print(root);
    std::cout << "Node next:" << std::endl;
    Node::printNext(root);

    Node::freeTree(root);
    std::cout << "Node test passed" << std::endl;
}
