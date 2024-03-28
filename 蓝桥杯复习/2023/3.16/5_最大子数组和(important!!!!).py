num = list(map(int, input().split(" ")))
# 测试案例
# -2 1 -3 4 -1 2 1 -5 4


def maxSubArray(nums: list[int]) -> int:
    n = len(nums)
    dp = [0] * n
    if n == 1:
        return nums[0]
    dp[0] = nums[0]
    maxvalue = dp[0]
    # 如果将dp定义为到i前面所有的子数组和最大值，这样新加入i的时候不好找递推关系
    # 反而如果将dp定义为以i结尾的子数组和的最大值,那么每个i都有唯一的一个最大值,将所有位置的值进行比较即可得出最大值
    for i in range(1, n):
        # 如果以第i个结尾的子数组和第i-1个结尾的子数组相连 则 dp[i]=dp[i-1]+nums[i]
        # 如果不相连 那么实际上就是第i个数字 则 dp[i]=nums[i]
        dp[i] = max(dp[i - 1] + nums[i], nums[i])
        maxvalue = max(maxvalue, dp[i])

    return maxvalue


print(maxSubArray(num))
