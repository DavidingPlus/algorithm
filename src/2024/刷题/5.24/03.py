# 区间修改、区间求和
# https://www.lanqiao.cn/problems/1133/learning/

# 使用树状数组
# 同一题，构造差分数组， b(n) = a(n) - a(n-1) ，这样区间修改就转化为单点修改，求和的时候差分数组的前缀和是原数组的某位置的值，将当前位置存储下来，然后依次迭代遍历相加即可，当然由于需要求第一个前缀和，所以仍使用树状数组
# TODO 仍然超时 1/4 ，我没辙了

N, Q = map(int, input().split())
nums = [0] + list(map(int, input().split()))

diff = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    diff[i] = nums[i]-nums[i-1]

f = [0 for _ in range(1+N)]


def lowbit(n):
    return n & (-n)


def get(pos):
    ans = 0
    while pos > 0:
        ans += f[pos]
        pos -= lowbit(pos)
    return ans


def update(pos, v):
    while pos <= N:
        f[pos] += v
        pos += lowbit(pos)


for i in range(1, 1+N):
    update(i, diff[i])

for _ in range(Q):
    l = list(map(int, input().split()))
    if 1 == l[0]:
        diff[l[1]] += l[3]
        update(l[1], l[3])
        if l[2] < N:
            diff[1+l[2]] -= l[3]
            update(1+l[2], -l[3])
    else:
        ans = 0
        base = get(l[1]-1)
        for i in range(l[1], 1+l[2]):
            base += diff[i]
            ans += base
        print(ans)
