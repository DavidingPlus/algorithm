#include <iostream>
using namespace std;
#include <string>

const int N = 100010;
int e[N];  // 下标为i的结点的值
int l[N];  // 下标为i的结点的前驱节点
int r[N];  // 下标为i的结点的后继节点
int idx;   // 下一个可以用到的结点的序号

// 初始化
// 这里用数组的0号和1号当作左结点和右结点，当作边界，不算实际内容
void __init__() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在下标为k位置的后面，插入值为x
void add_to_k_back(int k, int x) {
    e[idx] = x;

    r[idx] = r[k];
    l[idx] = k;
    r[k] = idx;
    l[r[idx]] = idx;

    ++idx;
}

// 在下标为k位置的前面，插入值为x、
void add_to_k_front(int k, int x) {
    add_to_k_back(l[k], x);
}

// 在头部插入一个值
void add_to_head(int x) {
    add_to_k_back(0, x);
}

// 在尾部插入一个值
void add_to_tail(int x) {
    add_to_k_front(1, x);
}

// 将下标为k的数删除，注意是删除下标为k，不是下一个
void remove_k(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int M;

int main() {
    cin >> M;

    // 初始化
    __init__();

    for (int i = 0; i < M; ++i) {
        string op;
        int k, x;

        cin >> op;
        if (op == "L") {
            cin >> x;
            add_to_head(x);
        } else if (op == "R") {
            cin >> x;
            add_to_tail(x);
        } else if (op == "D") {
            cin >> k;
            remove_k(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            add_to_k_front(k + 1, x);
        } else if (op == "IR") {
            cin >> k >> x;
            add_to_k_back(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << ' ';
    cout << endl;

    return 0;
}
