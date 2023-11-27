/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;  // 维护遍历过程中的路径

    // 力扣对图的表示是连接链表，用的是vector表示的
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 思路，和二叉树一样，遍历一次图即可，用递归深度优先
        traverse(graph, 0);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int nodeVal) {
        // 将节点存入
        path.push_back(nodeVal);

        // 如果遇到目标节点则退出
        if (nodeVal == graph.size() - 1) {
            res.push_back(path);
            // 记得维护路径
            path.pop_back();

            return;
        }

        // 递归遍历其余的节点
        for (auto& node : graph[nodeVal])
            traverse(graph, node);

        // 出去之后弹出
        path.pop_back();
    }
};
// @lc code=end
