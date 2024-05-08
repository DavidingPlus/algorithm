#include <iostream>
using namespace std;

const int N = 1000010;

// 我设计的这个队列从尾巴进，可以从头部和尾巴弹出
class _Deque {
public:
    _Deque() {
        __init__();
    }

    void __init__() {
        // head,tail占据数组位置但是不是队列的值，意思是队列是从1号下标开始的
        head = 0;
        tail = 1;
        // 这样设置初始化可以保证在队尾插入，队头弹出的前提下head和tail指针都在往后移动
    }

    // 插入，队尾插入
    void push_back(int x) {
        _deque[tail++] = x;
    }

    // 弹出，队头演出
    void pop_front() {
        ++head;
    }

    // 队尾弹出
    void pop_back() {
        --tail;
    }

    // 得到队头元素的值
    int front() const {
        return _deque[head + 1];
    }

    int back() const {
        return _deque[tail - 1];
    }

    // 判断是否为空
    bool _is_empty() const {
        return tail - head == 1;
    }

    int _size() const { return tail - head - 1; }

public:
    int _deque[N], head, tail;  // 规定队尾插入，队头弹出
};

int n, k, a[N] = {0};

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);  // 和数组模拟的队列保持统一，也从1开始

    _Deque d;

    // 先把前几个入队列备用
    for (int i = 1; i <= k - 1; ++i)
        d.push_back(a[i]);
    // 滑动窗口的位置从1到n-(k-1)，进入的i的范围就是k到n
    for (int i = k; i <= n; ++i) {
        // 注意理解我用数组模拟队列的实现，数组下标从1开始，顺序往后递增

        // 先看队头是否划出
        if (;)  // 判断队头的条件需要修改
            d.pop_front();

        // 判断看是否需要弹出
        // 从后面进来的数由于需要保证队列的单调性，需要从后往前开始判断，删去多余的元素
        // 这个为什么，看例子 -3 5 ，后面进入 3 和 6 就知道了
        while (d.back() > a[i] && !d._is_empty())  // 这里就是典型的比我来得早能力还不如我，所以就应该淘汰掉
            d.pop_back();                          // 这里pop_back()之后head指针没有即使后移导致deque和实际的a[i]下标产生了偏差

        // 进入队列
        d.push_back(a[i]);

        // printf("%d ", d.front());

        for (int i = d.head + 1; i < d.tail; ++i)
            cout << d._deque[i] << ' ';
        cout << endl;
    }
    puts("");

    return 0;
}
