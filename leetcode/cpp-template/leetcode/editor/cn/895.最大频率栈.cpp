/*
 * @lc app=leetcode.cn id=895 lang=cpp
 * @lcpr version=30404
 *
 * [895] 最大频率栈
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start

/*
FreqStack 的核心要求是：每次 pop() 时优先弹出当前出现频率最高的元素；如果多个元素频率相同，则弹出其中最近被 push 的那个。使用 priority_queue 的思路比较直接：为每次 push 记录当前频率 freq、插入顺序 index 和元素值 val，并按照 (freq, index) 作为优先级排序。这样堆顶始终是当前最应该被弹出的元素，其中频率越高优先级越高，频率相同时插入时间越晚优先级越高。该方法本质上是在维护所有 push 操作的全局优先级顺序，因此 push 和 pop 都需要调整堆，时间复杂度为 O(log n)。

经典解法则进一步利用了题目的特殊性质，将“最高频率”和“同频率下的最近顺序”拆开维护。valToFreq 负责记录每个元素当前的出现频率，maxFreq 直接记录当前所有元素中的最高频率，而 freqToVals[freq] 使用一个栈记录元素达到频率 freq 时的先后顺序。执行 pop() 时，不需要像优先队列一样重新比较所有候选元素，只需要直接访问 freqToVals[maxFreq] 的栈顶即可：maxFreq 保证找到最高频率，栈顶则保证在频率相同时选择最近被 push 的元素。因此这种方法避免了全局排序，使 push 和 pop 都可以做到 O(1)。需要特别注意的是，freqToVals[freq] 并不是简单表示“当前频率等于 freq 的元素集合”，而是记录“哪些元素曾按照什么顺序达到过这个频率”，这是该解法正确处理最近插入顺序的关键。
*/


// 解法 1：大顶堆。
// class FreqStack
// {

// public:

//     FreqStack() {}

//     void push(int val)
//     {
//         int freq = ++valToFreq[val];

//         // 因为需要根据 val 去查询它出现的频率次数，同时需要根据 freq 和 index 去定义 priority_queue 的仿函数比较器规则，因此存储 freq 和 index 是非常必要的。
//         pq.push({freq, index++, val});
//     }

//     int pop()
//     {
//         auto [freq, index, val] = pq.top();
//         pq.pop();

//         --valToFreq[val];


//         return val;
//     }


// private:

//     // 大顶堆 {freq, index, val}。
//     // tuple 默认是按字典序比较：先比较第一个 freq。freq 相同，再比较第二个 index。index 相同，再比较第三个 val。配合大顶堆正好符合题目要求。
//     std::priority_queue<std::tuple<int, int, int>> pq;

//     // val -> freq。
//     std::unordered_map<int, int> valToFreq;

//     // 记录 push 顺序。
//     int index = 0;
// };


// XXX 解法 2：正常栈。思路见 ./895.gif。
class FreqStack
{

public:

    FreqStack() {}

    void push(int val)
    {
        int freq = ++valToFreq[val];

        freqToVals[freq].push(val);

        maxFreq = std::max(maxFreq, freq);
    }

    int pop()
    {
        int res = freqToVals[maxFreq].top();
        freqToVals[maxFreq].pop();

        --valToFreq[res];

        if (freqToVals[maxFreq].empty()) --maxFreq;


        return res;
    }


private:

    // 维护出现的最大频率。
    int maxFreq = 0;

    // val -> freq。
    std::unordered_map<int, int> valToFreq;

    // freqToVals 的作用是：对每一个 Freq，都记录一个 vals 列表，这样弹出时，先找 maxFreq 对应的栈，再根据插入的先后顺序，天然代表谁最接近顶部，该弹出哪个元素。
    // 如果 push 了 3 次 5，5 会出现在 freq 为 1、2、3 的三个栈中，这样并不冲突，因为随着 freq 的变化，例如 5 被 3 的栈弹出了，那么 5 的 freq 自然就变成 2 了，状态自然得到更新。
    std::unordered_map<int, std::stack<int>> freqToVals;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end


int main()
{
}


/*
// @lcpr case=start
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"]\n[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]\n
// @lcpr case=end

 */
