/**
 * @file test.cpp
 * @author lzx0626 (2065666169@qq.com)
 * @brief 单调栈模板
 * @version 0.1
 * @date 2023-11-30
 *
 * Copyright (c) 2023 电子科技大学 刘治学
 *
 */

#include <iostream>
using namespace std;
#include <stack>
#include <vector>

// 输入一个数组 nums，请你返回一个等长的结果数组，结果数组中对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1
// 比如说，输入一个数组 nums = [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。因为第一个 2 后面比 2 大的数是 4; 1 后面比 1 大的数是 2；第二个 2 后面比 2 大的数是 4; 4 后面没有比 4 大的数，填 -1；3 后面没有比 3 大的数，填 -1
vector<int> nextGreaterElement(const vector<int> &nums)
{
    // 思路
    // 单调栈的思路是从后面开始遍历
    // 这个题里面，右边入栈，然后遇到第二个，查看栈里面有没有比他大的，有就是答案，因为我们在过程中会保证栈具有单调性，在这个题里面，3先进来，4进来后发现没有比top没有比他大的，因此返回-1，然后发现4比3大，因此把3踢出，直到遇到比自己大的(比自己大的有可能是别人的答案)或者为空，在进入栈，这也保证了栈的单调性，重复这个过程即可

    vector<int> res;
    res.resize(nums.size());

    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        // 先比较要进来的元素和栈内的元素的值，好出栈，保证栈的单调性
        // 这里的细节问题，s.top()栈空的时候报错，所以判空写在前面
        while (!s.empty() and s.top() <= nums[i])
            s.pop();

        // 本元素的答案就是栈顶元素或者为空就返回-1
        res[i] = s.empty() ? -1 : s.top();

        // 元素入栈
        s.push(nums[i]);
    }

    return res;
}

template <typename Container>
void print(const Container &nums)
{
    for (auto &val : nums)
        cout << val << ' ';
    cout << endl;
}

int main()
{
    vector<int> v{2, 1, 2, 4, 3};
    print(v);

    vector<int> res = nextGreaterElement(v);
    print(res);

    return 0;
}
