#include <iostream>
using namespace std;

const int N = 100010;
// 用数组模拟单链表
int head;   // 单链表的头指针，指向链表的头结点
int e[N];   // 下标为i的结点的值
int ne[N];  // 下标为i的结点的后继结点的序号
int idx;    // 下一个可用的结点的序号

// 注意，这个单链表在数组当中的序号不一定是按照序号来进行排序的，但是我们在插入的过程中早已经把结点的关系记录好了
// idx存储的是下一个可以用的结点的序号，是按照插入的顺序来的，链表实际的顺序大概率不是按照序号顺序来的，因为插入的位置不一定都是末尾

// 初始化
void __init__() {
    head = -1;
    idx = 0;
}

// 将x插头结点后面
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    ++idx;
}

// 将x插到下标是k的点后面
void add_to_k(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    ++idx;
}

// 将下标是k的点的后面一个点删掉
// 对于删除操作，没有将结点回收，因为我们是在算法题里面模拟链表，为了保证效率，不用考虑其他的问题，哪个结点实际上还在数组当中，但是我们的ne[]关系将其删除了，看起来链表里就没有了这个东西
void remove_k(int k) {
    ne[k] = ne[ne[k]];
}

int M;

int main() {
    cin >> M;
    // 初始化链表
    __init__();

    for (int i = 0; i < M; ++i) {
        // 输入操作
        char op;
        int k, x;
        cin >> op;

        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            // 特殊判断，删除头结点
            if (k == 0)
                head = ne[head];

            // 删除第k个插入的数，下标是k-1，在现在的链表关系中顺序不一定是k-1
            remove_k(k - 1);
        } else if (op == 'I') {
            cin >> k >> x;
            add_to_k(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    cout << endl;

    return 0;
}
