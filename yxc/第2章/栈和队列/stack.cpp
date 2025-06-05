#include <iostream>
using namespace std;
#include <string>

const int N = 100010;

class _Stack {
public:
    _Stack() {
        __init__();
    }

    // 初始化
    void __init__() {
        top = -1;  // 数组下标从0开始
    }

    // 判断是否为空
    bool _is_empty() {
        return top == -1;
    }

    // 入栈
    void push(int x) {
        _stack[++top] = x;
    }

    // 出栈
    void pop() {
        --top;
    }

    // 得到栈顶元素的值
    int gettop() {
        return _stack[top];
    }

private:
    // 用数组模拟栈
    int _stack[N], top;
};

int main() {
    int M;
    cin >> M;

    _Stack s;

    while (M--) {
        string op;
        int x;

        cin >> op;
        if (op == "push") {
            cin >> x;
            s.push(x);
        } else if (op == "pop") {
            s.pop();
        } else if (op == "query") {
            cout << s.gettop() << endl;
        } else if (op == "empty") {
            cout << (s._is_empty() ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
