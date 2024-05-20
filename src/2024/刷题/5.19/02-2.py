# 一个多重背包的问题变式
# https://www.lanqiao.cn/problems/1177/learning/

# TODO 这个也超时 6/9
# 上一种解法超时了，现在融合完全背包和多重背包的优化思路重新写一个
# 对于 s[i] 不为 0 的情况，视作多个相同体积的物品按照 01 背包的思路来做；s[i] == 0 的情况，按照完全背包的优化思路来做，应该能提高一些效率
N, V = map(int, input().split())
w_pre = [0 for _ in range(N)]
v_pre = [0 for _ in range(N)]
s = [0 for _ in range(N)]
for i in range(N):
    w_pre[i], v_pre[i], s[i] = map(int, input().split())

# w1 和 v1 表示有限个数的 01 背包的物品； w2 和 v2 表示无线个数的完全背包的物品
w1 = []
v1 = []
w2 = []
v2 = []

for i in range(N):
    if 0 != s[i]:
        # 二进制优化
        base = 1
        count = s[i]
        while base <= count:
            w1.append(base*w_pre[i])
            v1.append(base*v_pre[i])
            count -= base
            base *= 2
        w1.append(count*w_pre[i])
        v1.append(count*v_pre[i])
    else:
        w2.append(w_pre[i])
        v2.append(v_pre[i])

# 这里为了防止 01 背包或者完全背包某一方为空的情况，初始情况设置为空，也就是全为 0
dp = [0 for _ in range(1+V)]

# 先处理 01 背包
for i in range(len(w1)):
    tmp = [0 for _ in range(1+V)]
    for j in range(1+V):
        if j >= w1[i]:
            tmp[j] = max(dp[j], dp[j-w1[i]]+v1[i])
        else:
            tmp[j] = dp[j]
    dp = tmp

# 再处理完全背包
for i in range(len(w2)):
    tmp = [0 for _ in range(1+V)]
    for j in range(1+V):
        if j >= w2[i]:
            # 完全背包和 01 背包代码层面的唯一区别就在这里，但是要考虑清楚为什么
            tmp[j] = max(dp[j], tmp[j-w2[i]]+v2[i])
        else:
            tmp[j] = dp[j]
    dp = tmp

print(dp[V])
