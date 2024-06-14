/*
    ac,用队列规划层数
    https://www.nowcoder.com/pat/5/problem/4306
*/

#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
// key: 被关注者, value: 关注者
unordered_map<int, vector<int>> followed;
int n, l;  // 总数, 最多递归几层

int findMaxForwards(int idx) {
    queue<int> q;
    set<int> isfollowed;
    int t = l;
    q.push(idx);
    isfollowed.insert(idx);
    while (!q.empty() && t > 0) {
        int size = q.size();
        t--;
        while (size--) {
            int user = q.front();
            q.pop();
            for (int i = 0; i < followed[user].size(); i++) {
                // 去重
                if (isfollowed.count(followed[user][i]) == 0) {
                    q.push(followed[user][i]);
                    isfollowed.insert(followed[user][i]);
                }
            }
        }
    }
    return isfollowed.size() - 1;
}

int main() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        int follows;
        cin >> follows;
        for (int j = 0; j < follows; j++) {
            int idx;
            cin >> idx;
            // 构建被关注的关系,便于遍历
            followed[idx].emplace_back(i);
        }
    }
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int root;
        cin >> root;
        int forwards = findMaxForwards(root);
        cout << forwards << endl;
    }
}