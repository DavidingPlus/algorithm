/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

class RecentCounter
{

public:

    RecentCounter() {}

    int ping(int t)
    {
        q.push(t);
        while (t - q.front() > 3000) q.pop();


        return q.size();
    }

private:

    // 由于新的 ping 严格大于前面的 ping，因此以前的时间超出范围的后面肯定也用不到了，需要弹出，先进先出，因此考虑队列。
    std::queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated && called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end


int main()
{
}
