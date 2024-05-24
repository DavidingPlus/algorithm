# 树状数组，主要用于解决动态前缀和的问题
# 例题：单点修改、区间查询
# https://www.lanqiao.cn/problems/2340/learning/
# 通过这个题，可以记忆树状数组的模板

# 一个关键点就是 f 数组每个位置 i 存储的是从该位置往前的 lowbit(i) 长度的区间的和， lowbit 独特的性质决定了 i + lowbit(i) 能迭代到下一个更大的区间，并且新区间能覆盖原区间。比如 3(011) + lowbit(3)(1) 到 4(100) ，这样在维护 f 数组的时候迭代加上 lowbit(i) 即可，求和的时候反过来即可
# 结合图 01-树状数组-示意图.png 理解

N = int(input())
nums = [0] + list(map(int, input().split()))

f = [0 for _ in range(1+N)]


# 计算数组二进制从低位开始第一个非 0 与后面 0 构成的数，例如 6(110) 计算出来就是 2(10)
# 这个公式要记住
def lowbit(n):
    return n & (-n)


# 计算从开始到 pos 的前缀和数组（ pos 从 1 开始）
# 只要知道 pos 的范围是 [1, N] ， while 循环的条件就很明确了
def get(pos):
    ans = 0
    while pos > 0:
        ans += f[pos]
        pos -= lowbit(pos)
    return ans


# 将 pos 处的值加上 v ，更新 f 数组（ pos 从 1 开始）
def update(pos, v):
    while pos <= N:
        f[pos] += v
        pos += lowbit(pos)


# 初始化 f 数组
for i in range(1, 1+N):
    # nums 数组我在开头加上了一个 0 ，因此下标也是从 1 开始
    update(i, nums[i])

# 开始询问
m = int(input())
for _ in range(m):
    l = list(map(int, input().split()))
    if 1 == l[0]:
        update(l[1], l[2])
    else:
        print(get(l[2])-get(l[1]-1))
