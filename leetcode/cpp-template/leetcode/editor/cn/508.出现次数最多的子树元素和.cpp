/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */


#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

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


class Solution {
public:
    // 方法1：std::multimap存储，依靠key自己的排序
    //  最开始打算用一个int记录目前出现的最多次数的，但是这个设计有问题，有可能新的值出现了很多次，但是我们没有插入，这是不对的
    //  最后决定拿std::multimap存，key是出现次数，value是对应的值，这样排序就没问题了，返回来key是值，value是出现次数，stl没办法通过value排序...
    // std::multimap<int, int, std::greater<int>> m;

    // typename std::multimap<int, int, std::greater<int>>::const_iterator findValue(const std::multimap<int, int, std::greater<int>> &m, int target) {
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

    // std::vector<int> findFrequentTreeSum(TreeNode *root) {
    //     if (nullptr == root)
    //         return {};

    //     getSum(root);
    //     // 处理std::multimap中的数据
    //     std::vector<int> res;
    //     int count = m.begin()->first;

    //     for (auto &std::pair : m) {
    //         if (count == std::pair.first)
    //             res.push_back(std::pair.second);
    //         else
    //             break;
    //     }
    //     return res;
    // }

    // 方法2：拿哈希表存储，key是值，value是次数，自己去遍历一次得出最大的次数（注意和前面不一样）
    // 经leetcode测试，哈希表比std::map快多了，最大原因是std::map自适应内部排序花的时间太长了，远远大过我自己遍历一次的时间，这个东西自己需要权衡好
    std::unordered_map<int, int> um;

    int getSum(TreeNode *root) {
        if (nullptr == root)
            return 0;

        int leftSum = getSum(root->left);
        int rightSum = getSum(root->right);

        int sum = root->val + leftSum + rightSum;
        ++um[sum];

        return sum;
    }

    std::vector<int> findFrequentTreeSum(TreeNode *root) {
        getSum(root);

        std::vector<int> res;

        // 遍历一次得出最大的次数
        int maxCount = 0;
        for (auto &entry : um)
            maxCount = std::max(maxCount, entry.second);

        // 存储
        for (auto &entry : um) {
            if (maxCount == entry.second)
                res.push_back(entry.first);
        }
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
