#ifndef LEETCODE_COMMON_NODE_INCLUDED
#define LEETCODE_COMMON_NODE_INCLUDED

#include <optional>
#include <vector>


class Node
{

public:

    int val;
    Node *left;
    Node *right;
    Node *next;

    Node();

    explicit Node(int x);

    Node(int x, Node *left, Node *right);

    Node(int x, Node *left, Node *right, Node *next);

    static Node *createRoot(const std::vector<std::optional<int>> &values);

    static void freeTree(Node *root);

    static void print(Node *root);

    static void printNext(Node *root);

private:

    static int getHeight(Node *node);

    static void fillTree(Node *node, int level, int left, int right, int totalHeight, std::vector<std::vector<char>> &mat);
};


#endif
