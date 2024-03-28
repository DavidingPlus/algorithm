coins = list(map(int, input().split(" ")))
amount = int(input())


def coinChange(coins: list[int], amount: int) -> int:
    # 定义dp数组代表金额是i的时候的最小硬币个数
    # 金额为0必然可以兑换
    dp = [-1] * (amount + 1)
    # 先初始化 没有金额必然可以兑换
    dp[0] = 0

    # 逐个遍历
    # 当需要构成金额是i的时候，从已知的面额中寻找，dp[i]=dp[i-c]+1 如果dp[i-c]不存在那么返回-1
    for i in range(1, amount + 1):
        # 先看是不是可以直接兑换
        if i in coins:
            dp[i] = 1

        else:
            # 不能直接兑换则遍历已知的金额
            # 用一个数组来存放dp[i-c]
            list_c = list()
            for c in coins:
                # 需要金额i比较大才能兑换
                if i > c:
                    # 这一步需要取得最小的dp[i]值 切要保证dp[i-c]不为-1才能找到
                    if dp[i - c] != -1:
                        list_c.append(dp[i - c])
            # 要保证分出来的c和i-c都是满足题目条件的!!!
            # 如果没有c让其满足那么就没办法向下分割则返回-1
            if len(list_c) == 0:
                dp[i] = -1
            else:
                dp[i] = min(list_c) + 1

    return dp[amount]


print(coinChange(coins, amount))
