/*
    ac https://www.nowcoder.com/pat/5/problem/4316
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 100010;

/*
    简化为找最长链路问题,用树形
*/

struct TreeNode
{
    double prices; // 价格
    int len;       // 长度
    int idx;       // 对应下标
    int parent;    // 父节点下标
    vector<TreeNode *> childs;
    TreeNode(){};
    TreeNode(double p, int l, int idx)
        : prices(p), len(l), idx(idx){};
};

// 总人数, 供销商提供的价格, 每次倒手卖增长的利润
int n;
double p, r;

int num = 0; // 售卖最高价的零售商的个数

vector<int> path;
int maxPath = 0;
int numOfMaxPath = 0;
double maxPrice;
TreeNode *root;
// 节点对应的TreeNode
unordered_map<int, TreeNode *> indexs;
// 父亲节点对应的子节点
vector<int> inflect[N];

void buildTree(int idx)
{
    TreeNode *node = indexs[idx];
    vector<int> childList = inflect[idx];
    for (auto i : childList)
    {
        TreeNode *child = indexs[i];
        node->childs.emplace_back(child);
        child->len = node->len + 1;
        child->prices = node->prices * (1 + (r / 100));
        buildTree(child->idx);
    }
}

void dfs(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->childs.size() == 0)
    {
        if (node->len > maxPath)
        {
            maxPath = node->len;
            numOfMaxPath = 1;
            maxPrice = node->prices;
        }
        else if (node->len == maxPath)
        {
            numOfMaxPath++;
        }
        return;
    }
    for (auto child : node->childs)
    {
        dfs(child);
    }
}

int main()
{
    cin >> n >> p >> r;
    // 遍历每个商户
    int rootIdx;
    for (int i = 0; i < n; i++)
    {
        int parent;
        cin >> parent; // 父节点

        if (parent == -1)
        {
            root = new TreeNode(p, 1, i);
            indexs[i] = root;
            root->parent = parent;
            rootIdx = i;
        }
        else
        {
            TreeNode *node = new TreeNode();
            node->idx = i;
            node->parent = parent;
            indexs[i] = node;
            inflect[parent].emplace_back(node->idx);
        }
    }
    buildTree(rootIdx);
    dfs(root);
    printf("%.2f %d\n", maxPrice, numOfMaxPath);
}
