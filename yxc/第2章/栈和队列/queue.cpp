#include <iostream>
using namespace std;

const int N = 100010;

class _Queue {
public:
    _Queue() {
        __init__();
    }

    void __init__() {
        // head,tail占据数组位置但是不是队列的值，意思是队列是从1号下标开始的
        head = 0;
        tail = 1;
        // 这样设置初始化可以保证在队尾插入，队头弹出的前提下head和tail指针都在往后移动
    }

    // 插入，队尾插入
    void push(int x) {
        _queue[tail++] = x;
    }

    // 弹出，队头演出
    void pop() {
        ++head;
    }

    // 得到队尾元素的值
    int get() {
        return _queue[head + 1];
    }

    // 判断是否为空
    bool _is_empty() {
        return tail - head == 1;
    }

private:
    int _queue[N], head, tail;  // 规定队尾插入，队头弹出
};

int main() {
    int M;
    cin >> M;

    _Queue q;

    while (M--) {
        string op;
        int x;

        cin >> op;
        if (op == "push") {
            cin >> x;
            q.push(x);
        } else if (op == "pop") {
            q.pop();
        } else if (op == "query") {
            cout << q.get() << endl;
        } else if (op == "empty") {
            cout << (q._is_empty() ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
