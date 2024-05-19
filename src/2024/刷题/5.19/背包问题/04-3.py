# 分组背包
# https://www.acwing.com/problem/content/description/9/

# 注意 N 这里是组数，不是物品个数
N, V = map(int, input().split())
data = []
for i in range(N):
    s = int(input())
    e = []
    for _ in range(s):
        e.append(list(map(int, input().split())))
    data.append(e)

# 每一组的物品只选择一个，那就按照组为单位
dp = [0 for _ in range(1+V)]
for i in range(N):
    tmp = [0 for _ in range(1+V)]
    for j in range(1+V):
        # 对组内所有的物品，取最大值
        target = 0
        for k in range(len(data[i])):
            if j >= data[i][k][0]:
                target = max(dp[j], dp[j-data[i][k][0]]+data[i][k][1])
            else:
                target = dp[j]
            tmp[j] = max(tmp[j], target)
    dp = tmp

print(dp[V])
