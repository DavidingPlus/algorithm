/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start

#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> res; // 存储路径

    std::vector<std::vector<int>>
    allPathsSourceTarget(std::vector<std::vector<int>> &graph)
    {
        std::vector<int> path; // 实时维护路径
        traverseDFS(graph, 0, path);
        return res;
    }

    // 用深度优先来做，就直接递归了
    void traverseDFS(std::vector<std::vector<int>> &graph, int node, std::vector<int> &path)
    {
        path.push_back(node);

        // 由于是有向无环图，并且需要找出所有的路径，所以不需要设置 isVisited 数组，递归搜索下去一定能到达终止节点（题目数据保证）
        if (node == graph.size() - 1)
        {
            res.push_back(path);
            path.pop_back(); // 记得维护路径
            return;
        }

        for (auto &e : graph[node])
        {
            traverseDFS(graph, e, path);
        }
        // 回溯，将自己弹出路径
        path.pop_back();
    }
};

// @lc code=end
