/*
    ac
    https://www.nowcoder.com/pat/5/problem/4324
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge
{
    int to, len;
    Edge(int t, int l)
        : to(t), len(l) {}
};

const int INF = 1e9;  // 无穷大常量，用于初始化距离数组
const int MAXN = 510; // 最大站点数

int Cmax, N, Sp, M;                                       // Cmax: 每个站点的最大容量，N: 总站点数，Sp: 问题站点编号，M: 边数
int bikes[MAXN], d[MAXN], minNeed = INF, minRemain = INF; // bikes: 每个站点的自行车数量，d: 最短距离数组，minNeed: 最少需要带的自行车数，minRemain: 最少需要带回的自行车数
bool visited[MAXN];                                       // 记录站点是否被访问过
vector<Edge> adj[MAXN];                                   // 邻接表存储图
vector<int> pre[MAXN], path, tempPath;                    // pre: 最短路径前驱节点，path: 最优路径，tempPath: 当前路径

void Dijkstra(int s)
{
    // 初始化最短距离数组
    fill(d, d + MAXN, INF);
    fill(visited, visited + MAXN, false);
    d[s] = 0;                                                                           // 到节点本身距离为0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 优先队列，用于Dijkstra算法
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        // 当前节点是否被访问过
        if (visited[u])
            continue;
        visited[u] = true;
        // 访问当前节点的邻接节点
        for (Edge e : adj[u])
        {
            int v = e.to, len = e.len;
            if (!visited[v])
            {
                // 更新最短路径的前驱结点
                if (d[u] + len < d[v])
                {
                    d[v] = d[u] + len;
                    pq.push({d[v], v});
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + len == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v)
{
    if (v == 0)
    {
        tempPath.push_back(v);
        int need = 0, remain = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--)
        {
            int id = tempPath[i];
            if (bikes[id] > 0)
            {
                remain += bikes[id];
            }
            else
            {
                if (remain > abs(bikes[id]))
                {
                    remain -= abs(bikes[id]);
                }
                else
                {
                    need += abs(bikes[id]) - remain;
                    remain = 0;
                }
            }
        }
        if (need < minNeed)
        {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        }
        else if (need == minNeed && remain < minRemain)
        {
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int u : pre[v])
    {
        DFS(u);
    }
    tempPath.pop_back();
}

int main()
{
    // 输入最大容量Cmax，总站点数N，问题站点编号Sp，边数M
    cin >> Cmax >> N >> Sp >> M;
    Cmax /= 2;                    // 将最大容量除以2，计算每个站点的理想状态
    fill(bikes, bikes + MAXN, 0); // 初始化bikes数组
    for (int i = 1; i <= N; i++)
    {
        int Ci;
        cin >> Ci;
        bikes[i] = Ci - Cmax; // 计算每个站点相对于理想状态的自行车数量
    }
    for (int i = 0; i < M; i++)
    {
        int Si, Sj, Tij;
        cin >> Si >> Sj >> Tij;
        adj[Si].push_back(Edge(Sj, Tij));
        adj[Sj].push_back(Edge(Si, Tij));
    }
    Dijkstra(0); // 从起点0进行Dijkstra算法
    DFS(Sp);     // 从问题站点Sp进行DFS，找到最优路径
    cout << minNeed << " ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
            cout << "->";
    }
    cout << " " << minRemain << endl;
    return 0;
}
