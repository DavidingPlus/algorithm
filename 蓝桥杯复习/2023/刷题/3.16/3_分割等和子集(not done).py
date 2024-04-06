nums = list(map(int, input().split(" ")))
# 定义一个全局数组来记录每个元素的使用次数
times = [0] * len(nums)


def coinChange(coins: list[int], amount: int) -> int:
    dp = [-1] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        if i in coins:
            dp[i] = 1

        else:
            list_c = list()
            for c in coins:
                if i > c:
                    if dp[i - c] != -1:
                        list_c.append(dp[i - c])
            if len(list_c) == 0:
                dp[i] = -1
            else:
                dp[i] = min(list_c) + 1

    return dp[amount]


def canPartition(nums: list[int]) -> bool:
    sums = sum(nums)
    if sums & 1:
        return False
    sums = sums // 2
    # 问题转变为在一个数组中，每个数可以取或者不取，求是否能组成sums值
    # 这个问题就和零钱兑换基本一摸一样了
    # 唯一的区别在于 这个题只能每个元素只能用一次!!!
    # TODO
    ret = coinChange(nums, sums)
    if ret != -1:
        return True
    return False


print(canPartition(nums))
