/*
 * @lc app=leetcode.cn id=295 lang=cpp
 * @lcpr version=30404
 *
 * [295] 数据流的中位数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class MedianFinder
{

public:

    // 同一时刻数据流的个数只能是奇数或者偶数。最关键的一点是要维护某一个情况的唯一状态。
    // 当是偶数时，数据分居两侧，中位数是两个堆顶元素的平均值。
    // 当是奇数时，必然有一侧数据多了一个，那个值就是中位数。为了维护唯一状态，我们规定多出的这个元素放在小顶堆中，也就是奇数情况下小顶堆的个数必然比大顶堆多一个。

    MedianFinder() {}

    void addNum(int num)
    {
        // 插入前两堆一样大（偶数）；插入后总数为奇数，smallPq 需要多一个。
        if (m_largePq.size() == m_smallPq.size())
        {
            // 例如已有数据 [1, 2, 3, 5, 6, 7]：large={1,2,3}, small={5,6,7}，堆顶分别为 3 和 5。假设下一步进行如下操作。
            // 插入 0：0 < large.top()(3)，把 3 移到 small，再把 0 放入 large，得到 large={0,1,2}, small={3,5,6,7}。
            // 插入 3：3 >= large.top()(3)，直接放入 small，得到 large={1,2,3}, small={3,5,6,7}。
            // 插入 4：4 >= large.top()(3)，直接放入 small，得到 large={1,2,3}, small={4,5,6,7}。
            // 插入 8：8 >= large.top()(3)，也直接放入 small，得到 large={1,2,3}, small={5,6,7,8}。
            // m_largePq 为空时还没有较小的一半，不能调用 top()；首个数直接放入 smallPq。
            if (m_largePq.empty() || num >= m_largePq.top())
            {
                m_smallPq.push(num);
            }
            else
            {
                int node = m_largePq.top();
                m_largePq.pop();

                m_smallPq.push(node);
                m_largePq.push(num);
            }
        }
        // 插入前 m_smallPq 多一个；插入后总数为偶数，两堆应一样大。
        else
        {
            // 例如已有数据 [1, 2, 3, 5, 6]：large={1,2}, small={3,5,6}，small.top() 为 3。假设下一步进行如下操作。
            // 插入 0：0 <= small.top()(3)，直接放入 large，得到 large={0,1,2}, small={3,5,6}。
            // 插入 3：3 <= small.top()(3)，直接放入 large，得到 large={1,2,3}, small={3,5,6}。
            // 插入 4：4 > 3，把 3 移到 large，再把 4 放入 small，得到 large={1,2,3}, small={4,5,6}。
            // 插入 8：8 > 3，同样先移动 3，再放入 8，得到 large={1,2,3}, small={5,6,8}。
            if (num <= m_smallPq.top())
            {
                m_largePq.push(num);
            }
            else
            {
                int node = m_smallPq.top();
                m_smallPq.pop();

                m_largePq.push(node);
                m_smallPq.push(num);
            }
        }
    }

    double findMedian()
    {
        // 偶数。
        if (m_largePq.size() == m_smallPq.size())
        {
            return (static_cast<double>(m_smallPq.top()) + static_cast<double>(m_largePq.top())) / 2.0;
        }
        // 奇数。
        else if (m_largePq.size() < m_smallPq.size())
        {
            return static_cast<double>(m_smallPq.top());
        }
        // 不会走到这种情况。
        else
        {
            return {};
        }
    }


    // 一个小顶堆存储大于中位数的元素，大顶堆存储小于中位数的元素。这样中位数必然只和两个堆顶元素有关。
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_smallPq;
    std::priority_queue<int, std::vector<int>, std::less<int>> m_largePq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end


int main()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);                              // arr = [1]
    medianFinder.addNum(2);                              // arr = [1, 2]
    std::cout << medianFinder.findMedian() << std::endl; // 返回 1.5 ((1 + 2) / 2)
    medianFinder.addNum(3);                              // arr[1, 2, 3]
    std::cout << medianFinder.findMedian() << std::endl; // return 2.0
}


/*
// @lcpr case=start
// ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]\n
// @lcpr case=end

 */
