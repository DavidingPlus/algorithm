#ifndef LEETCODE_COMMON_TREENODE_INCLUDED
#define LEETCODE_COMMON_TREENODE_INCLUDED

#include <optional>
#include <vector>


class TreeNode
{

public:

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();

    explicit TreeNode(int x);

    TreeNode(int x, TreeNode *left, TreeNode *right);

    static TreeNode *createRoot(const std::vector<std::optional<int>> &values);

    static void freeTree(TreeNode *root);

    static void print(TreeNode *root);


private:

    static int getHeight(TreeNode *node);

    static void fillTree(TreeNode *node, int level, int left, int right, int totalHeight, std::vector<std::vector<char>> &mat);
};


#endif
