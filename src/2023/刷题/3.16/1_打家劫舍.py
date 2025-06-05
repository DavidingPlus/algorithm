# 用dp[i]数组表示偷取前i个数组能偷到的最大值
nums = list(map(int, input().split(" ")))
n = len(nums)


def rob(nums):
    # 用dp数组存储到前n个房子能偷到的钱的最大值
    dp = [0] * n
    if n == 1:
        return nums[0]
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, n):
        # 如果第i个房子被偷,那么第i-1个房子必然不能被偷,第i-2个房子以及下面的情况就不知道了,这时就加上第i个房子的钱即可
        # 如果第i个房子不被偷,那么第i-1个房子以及一下的情况不知道，这时就是dp[i-1]
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    return dp[n - 1]


print(rob(nums))
