/*
    https://www.nowcoder.com/pat/5/problem/4109
*/

#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int Np, Ng;  // 程序员数量和一组老鼠的最大数量
vector<int> miceWeight;
vector<int> order;
vector<int> ranks;

void updateRank(vector<int>& v, int rank) {
    for (int i = 0; i < v.size(); i++) {
        ranks[v[i]] = rank;
    }
}

void findMax(vector<int>& nextList) {
    int size = nextList.size();
    if (size == 1) {
        ranks[nextList[0]] = 1;
        return;
    }

    vector<int> next;
    int groups = (size + Ng - 1) / Ng;  // 向上取整，确定组数
    int rank = groups + 1;              // 当前淘汰的排名

    for (int i = 0; i < size; i += Ng) {
        int maxWeight = -1, maxIdx;
        vector<int> group;
        for (int j = 0; j < Ng && i + j < size; j++) {
            int idx = nextList[i + j];
            group.push_back(idx);
            if (miceWeight[idx] > maxWeight) {
                maxWeight = miceWeight[idx];
                maxIdx = idx;
            }
        }
        next.push_back(maxIdx);
        updateRank(group, rank);  // 更新当前组内所有老鼠的排名
    }
    findMax(next);
}

int main() {
    cin >> Np >> Ng;
    miceWeight.resize(Np);
    order.resize(Np);
    ranks.resize(Np, 0);

    for (int i = 0; i < Np; i++) {
        cin >> miceWeight[i];
    }
    for (int i = 0; i < Np; i++) {
        cin >> order[i];
    }

    vector<int> initialOrder = order;
    findMax(initialOrder);

    for (int i = 0; i < Np; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << ranks[i];
    }
    cout << endl;
    return 0;
}
