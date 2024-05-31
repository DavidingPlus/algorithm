# 神奇数
# https://www.lanqiao.cn/problems/5891/learning/

# TODO 这个代码存在严重的逻辑问题，我还没理清楚这是为什么。。。

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

# 10 ** 200 最多有 664.3 位，这里开 1000 位， sumMod 一定在 0 到 9 之间，因此我们这里先处理最后一位
dp = [[[-1 for _ in range(10)]for _ in range(2)]for _ in range(1000)]
a = []
cnt = 0


# 一样从高位到低位进行枚举，只不过优先确定最后一位
# 这个题目还是需要考虑一下前导 0 ，因为不能枚举出来前面全是 0 ，最后合成的数不符合条件
def dfs(pos, limit, sumMod, pre, sn):
    global dp, a, cnt

    if -1 != dp[pos][limit][sumMod]:
        return dp[pos][limit][sumMod]

    res = 0
    up = a[pos] if limit else 9
    for i in range(1+up):
        # 递归出口，注意确定了最后一位以后还要向前在移一位
        if pos == cnt-2:
            if 0 == (sumMod+i) % sn and not pre:
                res += 1
        else:
            res += dfs(1+pos, limit and i == a[pos], (sumMod+i) % sn,
                       pre and 0 == i, sn)

    dp[pos][limit][sumMod] = res
    return res


def f(n):
    global dp, a, cnt

    dp = [[[-1 for _ in range(10)]for _ in range(2)]for _ in range(1000)]
    a = []
    cnt = 0

    while n > 0:
        a.append(n % 10)
        n //= 10
        cnt += 1
    a = a[::-1]

    res = 0
    # 题目保证 n >= 10
    for i in range(1, 10):
        res += dfs(0, True, 0, True, i)
    return res


l = int(input())
r = int(input())
print((f(r) - f(l-1)) % 998244353)
