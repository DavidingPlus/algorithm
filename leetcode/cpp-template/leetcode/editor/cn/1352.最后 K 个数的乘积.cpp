/*
 * @lc app=leetcode.cn id=1352 lang=cpp
 * @lcpr version=30404
 *
 * [1352] 最后 K 个数的乘积
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class ProductOfNumbers
{

public:

    ProductOfNumbers() {}

    void add(int num)
    {
        // XXX 这个题最关键的点是遇到 0 该怎么处理。如果不处理，prefix 后面的值全都是 0。
        // 题目保证当前列表始终至少包含 k 个数字，也就是 k <= nums.size()。在 prefix 构造过程中，只要遇到 0，他前面的所有值都是废的，因为以 0 为分界，它左边的 getProduct() 的答案全都是 0，只有右侧是有效的。
        // 因此遇到 0 的时候我们把前面的部分丢弃，最后在计算结果的时候，如果 k > prefix.size() - 1（注意 prefix 有一个 dummyHead，所以有效部分的长度要减 1），说明过程中肯定遇到了 0 触发了丢弃逻辑，此时的答案应该是 0。
        if (0 == num)
        {
            prefix = {1};
        }
        else
        {
            prefix.emplace_back(prefix.back() * num);
        }
    }

    int getProduct(int k)
    {
        if (k > prefix.size() - 1)
        {
            return 0;
        }
        else
        {
            return prefix.back() / prefix[prefix.size() - k - 1];
        }
    }


    std::vector<int> prefix{1};
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end


int main()
{
}


/*
// @lcpr case=start
// ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]\n[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]\n
// @lcpr case=end

 */
