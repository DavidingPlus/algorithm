# 不要 62
# 数位 DP 经典题
# https://www.luogu.com.cn/problem/T227747

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

dp = [[[-1 for _ in range(11)] for _ in range(2)] for _ in range(8)]
a = []
cnt = 0


# pos 从 0 开始， 也就是说 0 代表最高位
# 这个题目前导 0 不会对结果产生相关影响，因此不用特殊处理前导 0
def dfs(pos, limit, pre):
    global dp, a, cnt

    # pos == cnt - 1 表示最后一位的个数，那个时候只要不跳过（不合法数字），就会进入到这里，返回 1 代表这个数字是符合条件的，不是不合法数字，这才是这个递归出口的含义
    if pos == cnt:
        return 1

    if -1 != dp[pos][limit][pre]:
        return dp[pos][limit][pre]

    res = 0
    # 根据 limit 判断上限
    up = a[pos] if limit else 9
    for i in range(1+up):
        if 4 == i or (6 == pre and 2 == i):
            continue
        # 下一个 limit 为 true 的条件是，当前为 true 并且贴着当前的上界取值，其他情况都是 false ，后面的 up 会受到影响
        res += dfs(1+pos, limit and i == a[pos], i)

    dp[pos][limit][pre] = res
    return res


def f(n):
    global dp, a, cnt

    dp = [[[-1 for _ in range(11)] for _ in range(2)] for _ in range(8)]
    a = []
    cnt = 0

    while n > 0:
        a.append(n % 10)
        n = n//10
        cnt += 1
    a = a[::-1]+[0]

    # pre 设置为 10 ，表示没有前一位数字，并且不和前面进行混淆，又不让数组越界
    return dfs(0, True, 10)


while True:
    n, m = map(int, input().split())
    if 0 == n and 0 == m:
        break

    if 0 == n:
        print(f(m))
    else:
        print(f(m)-f(n-1))
