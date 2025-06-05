# m 表示背包最大容量 n表示物品数量
# 测试样例
# 10 4
# 3 1
# 4 5
# 5 6
# 7 9

m, n = input().split(" ")
m, n = int(m), int(n)
weight = list()
value = list()
for i in range(n):
    w_c = input().split(" ")
    weight.append(int(w_c[0]))
    value.append(int(w_c[1]))

# 定义dp表
dp = list([0] * (m + 1) for i in range(n + 1))
# print(dp)

# 初始化dp表数据
# dp[i][j]表的含义是当背包容量为j时，前i个物品放进去得到的最大价值
# 这里要考虑第i个物品放还是不放,如果不放，那么就等同于前i-1的物品价值 dp[i][j]=dp[i-1][j]
# 如果要放进去,那么要考虑在剩余的空间当中是否能放入其他的物品 dp[i][j]=value[i]+dp[i-1][j-weight(i)]
# 取二者的最大值就是状态方程
for i in range(n):
    for j in range(m + 1):
        # 放第一个物品需要特殊处理防止数组越界
        if i == 0:
            if j >= weight[i]:
                dp[i][j] = value[i]
            else:
                dp[i][j] = 0
        else:
            if j == 0:
                dp[i][0] == 0
            else:
                # 状态转移方程
                # 想要放进去的前提条件是能放下
                if j >= weight[i]:
                    dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]])
                else:
                    # 放不进去
                    dp[i][j] = dp[i - 1][j]
print(dp[n - 1][m])
