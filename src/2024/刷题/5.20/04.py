# 包子凑数
# https://www.acwing.com/problem/content/1228/

from math import gcd

N = int(input())
A = [0 for _ in range(N)]
for i in range(N):
    A[i] = int(input())

# 题目需要用到数论的一些知识，参考链接: https://www.acwing.com/solution/content/17888/
# 见图 04-斐蜀定理.png

# 求这一组数的最大公约数
# 求 N 个数的最大公约数，直接利用前两个数的最大公约数和下一个数进行求解，然后循环，直到得出最后的结果
# 求 N 个数的最小公倍数，同理，直接利用前两个数的最小公倍数和下一个数进行求解，然后循环，直到得出最后的结果
g = A[0]
for i in range(1, N):
    g = gcd(g, A[i])

# 如果最大公约数不为 1 ，那么有无限个数表示不出来
if 1 != g:
    print("INF")
else:
    # 如果最大公约数是 1 的情况下，不能表示出来的包子个数的最大值是有上限的，因为 Ai 在 [0, 100] ，因此肯定不会超过 10000 ，因此取 10000 即可
    # 因此就转化为完全背包问题了，dp 表示的是能否凑出当前容量的背包
    dp = [False for _ in range(10000)]
    # 初始条件，什么都不使用，凑出体积为 0 是可以的，因此为 True
    dp[0] = True

    for i in range(N):
        tmp = [False for _ in range(10000)]
        for j in range(10000):
            if j >= A[i]:
                tmp[j] = dp[j] | tmp[j-A[i]]
            else:
                tmp[j] = dp[j]
        dp = tmp

    # 我们只关心 False 的个数，因此体积为 0 不会产生影响
    print(10000-sum(dp))
