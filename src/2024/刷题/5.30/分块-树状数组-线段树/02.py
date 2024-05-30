# 单点修改、区间查询（树状数组）
# https://www.lanqiao.cn/problems/2340/learning/

N = int(input())
nums = list(map(int, input().split()))

# 对于每一个数 f[i] 维护 从这个数开始往前，长度为 lowbit(i) 的数组的和，由于 lowbit(i) 独有的性质，能够很方便的查询和更新
f = [0 for _ in range(1+N)]  # 为了契合前缀和以及这个算法， f 数组下标从 1 开始


def lowbit(n):
    return n & (-n)


def get(pos):
    global f

    ans = 0
    # 由于 i 下标从 1 开始，因此注意这里的条件
    while pos > 0:
        ans += f[pos]
        pos -= lowbit(pos)

    return ans


def update(pos, v):
    global f, N

    # 同理，由于 i 下标从 1 开始，因此注意这里的条件
    while pos <= N:
        f[pos] += v
        pos += lowbit(pos)


for i in range(N):
    update(1+i, nums[i])

m = int(input())
for _ in range(m):
    l = list(map(int, input().split()))

    if 1 == l[0]:
        update(l[1], l[2])
    else:
        print(get(l[2])-get(l[1]-1))
