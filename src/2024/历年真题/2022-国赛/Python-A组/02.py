# https://www.lanqiao.cn/problems/2239/learning/

nums = [0, 6, 2, 5, 5, 4, 5, 6, 3, 7, 6]  # 下标也从 1 开始
nums = [0]+nums[::-1]

# 我反过来拿，先取 9 ，再取 8 ，直到 0 ，用 dp 来存储这个最大的整数，每个数最多用十次，是一个背包问题
dp = [[0 for _ in range(1+300)]for _ in range(1+10)]

for i in range(1, 1+10):
    for j in range(1+300):
        k = 0
        while j - k*nums[i] >= 0 and k <= 10:
            newNum = dp[i-1][j - k*nums[i]]
            for l in range(k):
                newNum = 10*newNum+(10-i)
            k += 1

            dp[i][j] = max(dp[i][j], newNum)

print(dp[10][300])
# print(9999999999777777777755555555554444444444333333333322222222221111111111)
