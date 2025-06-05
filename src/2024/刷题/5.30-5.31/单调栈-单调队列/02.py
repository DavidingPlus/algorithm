# 单调队列 模板题
# https://www.lanqiao.cn/problems/6251/learning/

# 求移动区间的最大值和最小值，使用单调队列
def work(nums, k, isMax):
    res = []
    q = []

    # i 代表队列的末尾指针， q 存储的是下标，方便判断队头是否出界
    n = len(nums)
    for i in range(n):
        # 先看队头是否出队
        if 0 != len(q) and i-k+1 > q[0]:
            q.pop(0)

        # 然后维持单调队列的性质
        if isMax:
            while 0 != len(q) and nums[i] >= nums[q[-1]]:
                q.pop(-1)
        else:
            while 0 != len(q) and nums[i] <= nums[q[-1]]:
                q.pop(-1)

        # 当前元素入队（注意这一条语句在 res 的前面，和单调栈的模板不同，因为 q 有可能为空，一个区间的最大值和最小值当然有可能是他自己，因此先入队；而单调栈不一样，他求的是第一个大于或者小于它的坐标，需要根据单调栈是否为空来进行判断，并且自己不可能是答案，因此入栈在后面）
        q.append(i)

        # i 代表的是右坐标，前几个的最大值是没有意义的
        # 同单调栈的思路， res 最好先开，然后在赋值，但是由于这里不是头插，不会每次插入都有 O(n) 的挪动复杂度，所以这里就不改了
        if i-k+1 >= 0:
            res.append(nums[q[0]])

    return res


n, k = map(int, input().split())
nums = list(map(int, input().split()))

maxList = work(nums, k, True)
minList = work(nums, k, False)

# 经过数学公式推导（自己模拟一个计算过程，化简一下就知道了），答案是 (sum(maxList) - sum(minList)) / len(maxList)
print("{:.2f}".format((sum(maxList) - sum(minList)) / len(maxList)))
