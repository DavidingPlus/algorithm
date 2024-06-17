/**
 * @file main.cpp
 * @author 刘治学's father (jingxiaoyang@uestc.edu.cn)
 * @brief
 * @version 0.1
 * @date 2024-06-17
 *
 * @copyright Copyright (c) 2024
 * @url https://www.nowcoder.com/pat/5/problem/4323 ac
 * 最开始没有理解孩子下标与整个树的关系，导致出错
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> nums;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v)
        : val(v), left(nullptr), right(nullptr) {}
};

void buildTree(TreeNode* node, int index, const vector<pair<int, int>>& children) {
    if (index == -1) {
        return;
    }
    int l = children[index].first;
    int r = children[index].second;
    if (l != -1) {
        node->left = new TreeNode();
        buildTree(node->left, l, children);
    }
    if (r != -1) {
        node->right = new TreeNode();
        buildTree(node->right, r, children);
    }
}

void inOrder(TreeNode* node, vector<int>& nums, int& pos) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left, nums, pos);
    node->val = nums[pos++];
    inOrder(node->right, nums, pos);
}

void printTheTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool first = true;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (first) {
            cout << node->val;
            first = false;
        } else {
            cout << " " << node->val;
        }
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;
}

int main() {
    cin >> n;
    vector<pair<int, int>> children(n);
    // 注意下标对应的左右孩子的下标
    for (int i = 0; i < n; i++) {
        cin >> children[i].first >> children[i].second;
    }

    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    TreeNode* root = new TreeNode();
    buildTree(root, 0, children);

    int pos = 0;
    inOrder(root, nums, pos);

    printTheTree(root);

    return 0;
}
