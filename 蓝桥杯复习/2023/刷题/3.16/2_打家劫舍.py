# 这个题与上个题的区别在于最后一个元素是否选择 如果第一个元素被选择,那么最后一个元素就不能被选择,反之亦然
# 用dp[i]数组表示偷取前i个数组能偷到的最大值
num = list(map(int, input().split(" ")))
n = len(num)

# 定义一个全局变量来判断是否选择第0号元素
# 如果没选择则合法 选择了则换成n-1的情况 因为n选择不了
flag1 = False
flag2 = False

# 上一个题的代码
def rob_res(nums):
    global flag1
    global flag2
    n = len(nums)
    dp = [0] * n
    if n == 1:
        return nums[0]
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, n):
        # 这里加入两个全局变量来查看0号和最后一号元素是否被选中
        if i == 2:
            if dp[i - 1] <= dp[i - 2] + nums[i]:
                # 代表选择第0号元素
                flag1 = True
        if i == n - 1:
            if dp[i - 1] <= dp[i - 2] + nums[i]:
                # 代表选择最后一个元素
                flag2 = True
        # 如果第i个房子被偷,那么第i-1个房子必然不能被偷,第i-2个房子以及下面的情况就不知道了,这时就加上第i个房子的钱即可
        # 如果第i个房子不被偷,那么第i-1个房子以及一下的情况不知道，这时就是dp[i-1]
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    return dp[n - 1]


def rob(nums: list[int]):
    rob_res(nums)

    if not (flag1 and flag2):
        return rob_res(nums)
    # 这样的情况下不能同时取第一个和最后一个 所以值应该是分别出去0号元素和最后一号元素的在进行一次函数遍历的最大值
    # 1 2 3 就是这样的一个例子 这里1 3不能同时取 那么就看1 2 和2 3 里面的最大值就可以了
    return max(rob_res(nums[:-1]), rob_res(nums[1:]))


# 无非就两种情况 第一个元素选择或者不选择的问题
# 如果第一个元素选择，则最后一个元素不能选择 因此偷盗的最大的钱和i-1相同
# 如果第一个元素不选择，则最后一个元素可以选择也可以不选择，和之前的案例一样
print(rob(num))
