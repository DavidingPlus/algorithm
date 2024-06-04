/*
    ac
    https://www.nowcoder.com/pat/5/problem/4318
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    string idx;
    string parent;
    vector<string> childs;
};

int n, m;  // 总共的人口以及有孩子的人口
// 记录每一代的人
unordered_map<int, vector<string>> generations;
unordered_map<string, TreeNode*> inflect;

// 如何找出第一代: 第一代肯定有儿子,找出有孩子且不是比人孩子的即为第一代
set<string> parents;  // 记录有儿子的节点
set<string> sons;     // 记录是儿子的节点

int maxPopulation = 0;
int generator;
int MaxGeneration = 0;

vector<string> split(string s) {
    vector<string> ret;
    string delimiter = " ";
    int pos = 0;
    while ((pos = s.find(delimiter)) != string::npos) {
        string token = s.substr(0, pos);
        ret.emplace_back(token);
        s.erase(0, pos + delimiter.size());
    }
    ret.emplace_back(s);
    return ret;
}

void bfs(int generatorIdx, string childIdx) {
    if (generatorIdx > MaxGeneration) {
        MaxGeneration = generatorIdx;
    }
    generations[generatorIdx].emplace_back(childIdx);
    if (inflect.find(childIdx) != inflect.end()) {
        TreeNode* node = inflect[childIdx];
        // 该节点有孩子,递归
        if (node->childs.size() > 0) {
            // 有下一代,计算下一代长度
            for (auto childIdx1 : node->childs) {
                bfs(generatorIdx + 1, childIdx1);
            }
        }
    }
}

void findMaxPopulation() {
    for (int i = 1; i <= MaxGeneration; i++) {
        if (generations[i].size() > maxPopulation) {
            maxPopulation = generations[i].size();
            generator = i;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string idx;
        int numOfChilds;
        cin >> idx >> numOfChilds;
        string tmp;
        tmp += idx;
        tmp += " ";
        tmp += to_string(numOfChilds);
        tmp += " ";
        for (int j = 0; j < numOfChilds; j++) {
            string t;
            cin >> t;
            if (j == numOfChilds - 1) {
                tmp += t;
            } else {
                tmp += t;
                tmp += " ";
            }
        }
        vector<string> info = split(tmp);
        parents.insert(idx);
        TreeNode* node = new TreeNode();
        node->idx = idx;
        for (int i = 2; i < info.size(); i++) {
            node->childs.emplace_back(info[i]);
            sons.insert(info[i]);
        }
        inflect[idx] = node;
    }
    // 找出第一代
    for (auto i : parents) {
        if (sons.find(i) == sons.end()) {
            // 是第一代
            generations[1].emplace_back(i);
        }
    }
    for (auto idx : generations[1]) {
        TreeNode* node = inflect[idx];
        if (node->childs.size() > 0) {
            // 有下一代,计算下一代长度
            for (auto childIdx : node->childs) {
                bfs(2, childIdx);
            }
        }
    }

    findMaxPopulation();
    cout << maxPopulation << " " << generator << endl;
}