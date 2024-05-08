#include <iostream>
using namespace std;

const int N = 100010;
int n;

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
    scanf("%d", &n);
    _Stack s;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        // 思路：
        // 现在需要找到的的是第i个数往前数最近的一个比他小的数
        // 我们现在考虑i前面的两个数 ax和ay，并且x < y
        // 如果ax>=ay，那么符合后面要求的数永远不可能是ax，因为如果ax符合要求，ay小于等于ax并且距离更近，这个值可以扔掉
        // 显然ax也不符合ay的要求
        // 我们现在用栈来模拟这个过程
        // 现在我插入新的数，我判断类似刚才的数是否符合条件，如果不符合条件，现在从栈中删除
        // 那么怎么找到类似刚才的数呢？
        // 我们可以判断栈顶，如果栈顶不符合要求，则弹出，继续判断，直到符合要求，这个操作不仅帮自己避了雷，也帮后面避了雷
        // 这样就把栈变成了单调的，就是单调栈
        // 如果栈空了说明没有值满足，然后将本值插入栈进行下一回合的循环即可

        // 用 3 4 2 7 5 的测试样例自己验证一下即可

        while (s.gettop() >= x && !s._is_empty())  // 不满足条件则一直弹出
            s.pop();

        if (s._is_empty())
            printf("-1 ");
        else
            printf("%d ", s.gettop());

        s.push(x);
    }
    cout << endl;

    return 0;
}
