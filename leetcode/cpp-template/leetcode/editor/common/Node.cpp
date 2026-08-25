#include "Node.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>


Node::Node() : val(0), left(nullptr), right(nullptr), next(nullptr)
{
}

Node::Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr)
{
}

Node::Node(int x, Node *left, Node *right)
    : val(x), left(left), right(right), next(nullptr)
{
}

Node::Node(int x, Node *left, Node *right, Node *next)
    : val(x), left(left), right(right), next(next)
{
}

Node *Node::createRoot(const std::vector<std::optional<int>> &values)
{
    if (values.empty() || !values[0].has_value())
        return nullptr;

    Node *root = new Node(values[0].value());
    std::queue<Node *> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (i < values.size() && !nodeQueue.empty())
    {
        Node *current = nodeQueue.front();
        nodeQueue.pop();

        if (values[i].has_value())
        {
            current->left = new Node(values[i].value());
            nodeQueue.push(current->left);
        }
        ++i;

        if (i < values.size() && values[i].has_value())
        {
            current->right = new Node(values[i].value());
            nodeQueue.push(current->right);
        }
        ++i;
    }
    return root;
}

void Node::freeTree(Node *root)
{
    if (!root)
        return;

    // 只沿 left/right 释放，不能沿 next 释放，因为 next 可能指向同层节点。
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void Node::print(Node *root)
{
    if (!root)
    {
        std::cout << "(empty)" << std::endl;
        return;
    }

    int h = getHeight(root);
    int rows = h * 2 - 1;
    int cols = (1 << h) - 1;
    std::vector<std::vector<char>> mat(rows, std::vector<char>(cols, ' '));

    fillTree(root, 0, 0, cols - 1, h, mat);

    for (const auto &row : mat)
    {
        for (char ch : row)
            std::cout << ch;
        std::cout << std::endl;
    }
}

void Node::printNext(Node *root)
{
    if (!root)
    {
        std::cout << "(empty)" << std::endl;
        return;
    }

    std::queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        int levelSize = static_cast<int>(nodeQueue.size());
        for (int i = 0; i < levelSize; ++i)
        {
            Node *current = nodeQueue.front();
            nodeQueue.pop();

            std::cout << current->val << " -> ";
            if (current->next)
                std::cout << current->next->val;
            else
                std::cout << '#';

            if (i + 1 < levelSize)
                std::cout << " | ";

            if (current->left)
                nodeQueue.push(current->left);
            if (current->right)
                nodeQueue.push(current->right);
        }
        std::cout << std::endl;
    }
}

int Node::getHeight(Node *node)
{
    if (!node)
        return 0;
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

void Node::fillTree(Node *node, int level, int left, int right,
                    int totalHeight, std::vector<std::vector<char>> &mat)
{
    if (!node)
        return;

    int mid = (left + right) / 2;
    std::string valStr = std::to_string(node->val);
    int offset = (static_cast<int>(valStr.size()) - 1) / 2;
    for (int i = 0; i < static_cast<int>(valStr.size()) &&
                    (mid - offset + i) < static_cast<int>(mat[level * 2].size());
         ++i)
    {
        mat[level * 2][mid - offset + i] = valStr[i];
    }

    if (level == totalHeight - 1)
        return;

    if (node->left)
    {
        int branchPos = (left + mid) / 2;
        mat[level * 2 + 1][branchPos] = '/';
        fillTree(node->left, level + 1, left, mid - 1, totalHeight, mat);
    }

    if (node->right)
    {
        int branchPos = (mid + 1 + right) / 2;
        mat[level * 2 + 1][branchPos] = '\\';
        fillTree(node->right, level + 1, mid + 1, right, totalHeight, mat);
    }
}
