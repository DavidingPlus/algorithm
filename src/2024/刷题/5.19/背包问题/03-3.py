# 多重背包问题 2: 二进制优化
# https://www.acwing.com/problem/content/description/5/

N, V = map(int, input().split())
v_pre = [0 for _ in range(N)]
w_pre = [0 for _ in range(N)]
s = [0 for _ in range(N)]
for i in range(N):
    v_pre[i], w_pre[i], s[i] = map(int, input().split())

v = []
w = []
for i in range(N):
    # 二进制优化，进行分包的工作
    # 优化原理见 04-3-优化.png
    # 举个例子，拆分 13 ，我们的期望是能表示出 0 到 13 的任意一个数，并且通过拆分出的序列，每个数只使用一次
    # 1 ，剩 13 - 1 = 12
    # 2 ，剩 12 - 2 = 10
    # 4 ，剩 10 - 4 = 6
    # 6 < 8 ，不够了，因此剩下 6
    # 最终的结果就是 [1, 2, 4, 6] ，当然相应物品的体积和价值要乘以倍数
    # 为什么能表示呢？首先看 1 2 4 ，这三个是 2 的 幂次，画图分析二进制的图，很容易知道，能够表示出 0 到 7 的任意数，然后再加上 6 ，就能表示出 6 到 13 的任意数，结合起来，最终就能表示出 0 到 13 的任意数
    count = s[i]
    base = 1
    while base <= count:
        v.append(base * v_pre[i])
        w.append(base * w_pre[i])
        count -= base
        base *= 2
    # 处理最后剩下的数， count 一定大于 0 ，因为循环进入的条件就是 count >= base ，减掉以后依然为正， base 乘 2 大于 count 导致循环结束
    v.append(count * v_pre[i])
    w.append(count * w_pre[i])

# 后续按照 01 背包的思路来做就行
dp = [0 for _ in range(1+V)]
for j in range(1+V):
    if j >= v[0]:
        dp[j] = w[0]

for i in range(1, len(v)):
    tmp = [0 for _ in range(1+V)]
    for j in range(1+V):
        if j >= v[i]:
            tmp[j] = max(dp[j], dp[j-v[i]]+w[i])
        else:
            tmp[j] = dp[j]
    dp = tmp

print(dp[V])
