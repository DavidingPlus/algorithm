# 健身
# https://www.lanqiao.cn/problems/5130/learning/

# 关键是往已有的模板上靠
# 题目说明某些天是没办法健身的，这表明整个天数被划分为很多个区间，在各自的区间内是独立的，因此对于某一个区间，感觉有点像背包问题，区间总长度就是容量，某个计划的天数就是每个物品的容量，并且具有一定的价值，并且同一天不能进行两个或者两个以上的健身计划，这又把不同的健身计划在总天数中区分开了，因此完美契合完全背包问题
n, m, q = map(int, input().split())
t = list(map(int, input().split()))
k = [0 for _ in range(m)]
s = [0 for _ in range(m)]
for i in range(m):
    k[i], s[i] = map(int, input().split())
    # 完成计划需要 2 ** k[i] 天，同步修改
    k[i] = 2**k[i]

# 将 t 数组排序，从而计算出训练的区间
t.sort()
# 为什么要加上 0 和 1+n ，以 10==n 为例
# q 数组是 1 4 9 ，那么划分的区间就是 [2, 3], [5, 8], [10] ，经过数学验证，首尾加上 0 和 11 可以有效的保证第一个区间和最后一个区间不被遗漏
t = [0]+t
t = t+[1+n]
V = []
for i in range(len(t)):
    if len(t) - 1 != i:
        V.append(t[i+1]-t[i]-1)

ans = 0
for v in V:
    # 如果连续两天都有安排，在这里的结果就是 0==v
    if 0 == v:
        continue
    dp = [0 for _ in range(1+v)]
    for i in range(m):
        tmp = [0 for _ in range(1+v)]
        for j in range(1+v):
            if j >= k[i]:
                tmp[j] = max(dp[j], tmp[j-k[i]]+s[i])
            else:
                tmp[j] = dp[j]
        dp = tmp
    ans += dp[v]

print(ans)
