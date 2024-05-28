# 区间最大值
# https://www.lanqiao.cn/problems/1205/learning/

from math import log2

# ST 表的思路，见 02-ST表.png 和 02-ST表-2.png
# 在本题中， f[i][j] 代表以 i 下标（ i 一般从 0 开始）为左端点，长度为 2**j 的区间的最大值，也就是区间的范围是 [i, i + 2**j -1] ，可以看出 j 是以 2 的指数范围增加的，因此只需要很小的值就能够表示出很大的范围。本题中数组长度 <= 5 * 1e5 ，对其开对数是 18.5 左右，因此选择 j 的上限是 20
# f 数组能由之前的结果导出， f[i][j] = max(f[i][j-1], f[i+(1 << (j-1))][j-1]) ，意思就把区间分为左右两个区间了，求这两个区间的最大值即可，但是可以看出需要计算出 j-1 的所有行才能得出 f[i][j] 的结果，因此先遍历 j ，再遍历 i ，这里要格外注意

N, Q = map(int, input().split())
nums = list(map(int, input().split()))

MAX = 1+int(log2(N))
f = [[0 for _ in range(MAX)] for _ in range(N)]

# 初始化
for i in range(N):
    f[i][0] = nums[i]

# 预处理 f 数组
for j in range(1, MAX):
    for i in range(N):
        # 很有可能出现 2 ** j 次方太大了，超出 N 的边界，甚至 2 ** (j-1) 也超出边界的情况，这时候取左边就行
        if i+(1 << (j-1)) >= N:
            f[i][j] = f[i][j-1]
        else:
            f[i][j] = max(f[i][j-1], f[i+(1 << (j-1))][j-1])

# 查询的时候计算出不超过该范围的最大 j 值即可，即 log2(range) 向下取整，然后左端点去一个，右端点去一个，这样能保证能遍布整个范围，极端情况是刚好是 2 的次方，这样刚好分为两半，一般情况会在中间重合，但是不会影响结果
for _ in range(Q):
    l, r = map(int, input().split())
    j = int(log2(r-l+1))
    print(max(f[l-1][j], f[r-(1 << j)][j]))
