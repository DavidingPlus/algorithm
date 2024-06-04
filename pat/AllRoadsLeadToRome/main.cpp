/*
    70%  https://www.nowcoder.com/pat/5/problem/4315
*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Edge
{
    string to; // 到达城市
    int cost;  // 花销
    Edge(string t, int c)
        : to(t), cost(c){};
    Edge(){};
};

const int MAXN = 1000;
const int INF = 1e9;
const string destination = "ROM";

int n, k;         // 城市数量, 不同城市通行数量
string beginCity; // 开始城市名

// key 城市名 value 幸福指数
unordered_map<string, int> happiness;

unordered_map<string, vector<Edge *>> adj;            // 临接矩阵
unordered_map<string, vector<pair<string, int>>> pre; // 最短前缀路径 到某一节点及其花费
unordered_map<string, bool> visitd;
unordered_map<string, int> d; // 最短距离
int routes = 0, sumOfHappiness = 0, tmpSumOfHappiness = 0;

int costs = INF, tmpCost = 0;
vector<string> path, tmpPath;

void dijkstra(string s)
{
    d[s] = 0; // 到自己的距离为0
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
    pq.push({s, d[s]});
    while (!pq.empty())
    {
        string u = pq.top().first; // 当前节点
        pq.pop();
        if (visitd[u])
        {
            continue;
        }
        visitd[u] = true;
        // 遍历节点的邻接表
        vector<Edge *> v = adj[u];
        for (auto i : v)
        {
            string node = i->to;
            if (visitd[node])
            {
                continue;
            }
            int cost = i->cost;
            if (d[u] + cost < d[node])
            {
                d[node] = d[u] + cost;
                pq.push({node, d[node]});
                pre[node].clear();
                pre[node].emplace_back(make_pair(u, cost));
            }
            else if (d[u] + cost == d[node])
            {
                pre[node].emplace_back(make_pair(u, cost));
            }
        }
    }
}

void dfs(string s)
{
    if (s == beginCity)
    {
        tmpPath.push_back(s);
        tmpSumOfHappiness += happiness[s];
        if (tmpCost < costs)
        {
            routes = 1;
            path = tmpPath;
            costs = tmpCost;
            sumOfHappiness = tmpSumOfHappiness;
        }
        else if (tmpCost == costs && tmpSumOfHappiness > sumOfHappiness)
        {
            routes++;
            sumOfHappiness = tmpSumOfHappiness;
            path = tmpPath;
        }
        else if (tmpCost == costs && sumOfHappiness == tmpSumOfHappiness && (sumOfHappiness / (path.size() - 1)) < (tmpSumOfHappiness / (tmpPath.size() - 1)))
        {
            path = tmpPath;
            routes++;
        }
        tmpPath.pop_back();
        tmpSumOfHappiness -= happiness[s];
        return;
    }
    tmpPath.push_back(s);
    tmpSumOfHappiness += happiness[s];
    for (auto city : pre[s])
    {
        tmpCost += city.second;
        dfs(city.first);
        tmpCost -= city.second;
    }
    tmpPath.pop_back();
    tmpSumOfHappiness -= happiness[s];
}

int main()
{
    cin >> n >> k >> beginCity;
    for (int i = 0; i < n - 1; i++)
    {
        string city;
        int happy;
        cin >> city >> happy;
        happiness[city] = happy;
        visitd[city] = false;
        d[city] = INF;
    }
    for (int i = 0; i < k; i++)
    {
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        Edge *edge1 = new Edge(to, cost);
        Edge *edge2 = new Edge(from, cost);
        adj[from].emplace_back(edge1);
        adj[to].emplace_back(edge2);
    }
    // 通过迪杰斯特拉算法找到最短路径
    dijkstra(beginCity);
    // dfs遍历,找到花费最小的路径
    dfs(destination);
    cout << routes << " " << costs << " " << sumOfHappiness << " " << int(sumOfHappiness / (path.size() - 1)) << endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << path[i];
        }
        else
        {
            cout << path[i] << "->";
        }
    }
    cout << endl;
}
