# 区间修改、单点查询
# https://www.luogu.com.cn/problem/P3368

# 使用树状数组
# 由于是区间修改，构造差分数组， b(n) = a(n) - a(n-1) ，这样区间修改就转化为单点修改，求和的时候差分数组的前缀和是原数组的某位置的值
# TODO 超时 7/10 ，不过我比较满意了

N, M = map(int, input().split())
nums = [0] + list(map(int, input().split()))

diff = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    diff[i] = nums[i]-nums[i-1]

# 这个 f 数组处理的是差分数组
f = [0 for _ in range(1+N)]


def lowbit(n):
    return n & (-n)


def get(pos):
    global f

    ans = 0
    while pos > 0:
        ans += f[pos]
        pos -= lowbit(pos)
    return ans


def update(pos, v):
    global f

    while pos <= N:
        f[pos] += v
        pos += lowbit(pos)


for i in range(1, 1+N):
    update(i, diff[i])

for _ in range(M):
    l = list(map(int, input().split()))
    if 1 == l[0]:
        update(l[1], l[3])
        if l[2] < N:
            update(1+l[2], -l[3])
    else:
        print(get(l[1]))
