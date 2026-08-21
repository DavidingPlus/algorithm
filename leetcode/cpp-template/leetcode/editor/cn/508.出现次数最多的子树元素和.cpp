/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

#include <iostream>
using namespace std;
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // 方法1：multimap存储，依靠key自己的排序
    //  最开始打算用一个int记录目前出现的最多次数的，但是这个设计有问题，有可能新的值出现了很多次，但是我们没有插入，这是不对的
    //  最后决定拿multimap存，key是出现次数，value是对应的值，这样排序就没问题了，返回来key是值，value是出现次数，stl没办法通过value排序...
    // multimap<int, int, greater<int>> m;

    // typename multimap<int, int, greater<int>>::const_iterator findValue(const multimap<int, int, greater<int>> &m, int target) {
    //     for (auto iter = m.begin(); iter != m.end(); ++iter) {
    //         if (iter->second == target)
    //             return iter;
    //     }
    //     return m.end();
    // }

    // // 用这个函数存储元素和
    // int getSum(TreeNode *root) {
    //     if (nullptr == root)
    //         return 0;

    //     int leftSum = getSum(root->left);
    //     int rightSum = getSum(root->right);

    //     int sum = root->val + leftSum + rightSum;

    //     auto iter = findValue(m, sum);
    //     if (m.end() != iter)  // 找到了
    //     {
    //         auto count = iter->first;
    //         m.erase(iter);
    //         m.insert({++count, sum});
    //     } else
    //         m.insert({1, sum});

    //     return sum;
    // }

    // vector<int> findFrequentTreeSum(TreeNode *root) {
    //     if (nullptr == root)
    //         return {};

    //     getSum(root);
    //     // 处理multimap中的数据
    //     vector<int> res;
    //     int count = m.begin()->first;

    //     for (auto &pair : m) {
    //         if (count == pair.first)
    //             res.push_back(pair.second);
    //         else
    //             break;
    //     }
    //     return res;
    // }

    // 方法2：拿哈希表存储，key是值，value是次数，自己去遍历一次得出最大的次数（注意和前面不一样）
    // 经leetcode测试，哈希表比map快多了，最大原因是map自适应内部排序花的时间太长了，远远大过我自己遍历一次的时间，这个东西自己需要权衡好
    unordered_map<int, int> um;

    int getSum(TreeNode *root) {
        if (nullptr == root)
            return 0;

        int leftSum = getSum(root->left);
        int rightSum = getSum(root->right);

        int sum = root->val + leftSum + rightSum;
        ++um[sum];

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root) {
        getSum(root);

        vector<int> res;

        // 遍历一次得出最大的次数
        int maxCount = 0;
        for (auto &pair : um)
            maxCount = max(maxCount, pair.second);

        // 存储
        for (auto &pair : um) {
            if (maxCount == pair.second)
                res.push_back(pair.first);
        }
        return res;
    }
};
// @lc code=end
