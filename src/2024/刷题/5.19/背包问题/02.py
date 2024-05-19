# 完全背包
# https://www.acwing.com/problem/content/description/3/

N, V = map(int, input().split())
v = [0 for _ in range(N)]
w = [0 for _ in range(N)]
for i in range(N):
    v[i], w[i] = map(int, input().split())

# 与 01 背包不同的是，这里的完全背包，每个物品可以使用无数次，因此状态转移方程的唯一区别就在于，如果要使用下一个物品，那么需要遍历下一个物品使用多少次的每一种情况
dp = [[0 for _ in range(1+V)]for _ in range(N)]

# 初始状态
for j in range(1+V):
    dp[0][j] = (j//v[0]) * w[0]

for i in range(1, N):
    for j in range(1+V):
        # 这个地方最直观的做法就是这样，但是请看 03-优化.png ，通过类似于递归的手法巧妙化解了这个问题

        # # 0==k 表示不使用新物品
        # for k in range(1+j//v[i]):
        #     dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*w[i])

        if j >= v[i]:
            # 这样以后 01背包和完全背包的代码就差一处
            # 01 背包是 dp[i-1][j-v[i]]+w[i]
            # 完全背包是 dp[i][j-v[i]]+w[i] ，注意这个的来源
            dp[i][j] = max(dp[i-1][j], dp[i][j-v[i]]+w[i])
        else:
            dp[i][j] = dp[i-1][j]
print(dp[N-1][V])
