# 单点修改、区间查询
# https://www.lanqiao.cn/problems/2340/learning/

from math import sqrt

# 通过分块的思想进行优化
N = int(input())
nums = list(map(int, input().split()))

# 计算出分块出来的区间的长度，最佳的值是根号 n ，这里为了防止为 0 ，加 1
# 有了区间长度 distance 以后，下标（从 0 开始）// distance 就可以求出所在区间
distance = int(sqrt(N))+1
sums = [0 for _ in range(N//distance if 0 == N % distance else 1+N//distance)]
for i in range(N):
    sums[i//distance] += nums[i]

m = int(input())
for _ in range(m):
    l = list(map(int, input().split()))

    # 注意 l[0]==1 时，l[1] 对应增加的下标从 1 开始； l[0]==2 的时候两个左右下标也是从 1 开始
    if 1 == l[0]:
        nums[l[1]-1] += l[2]
        sums[(l[1]-1)//distance] += l[2]
    else:
        ans = 0
        left = (l[1]-1)//distance
        right = (l[2]-1)//distance

        # 起点和终点如果在一个区间，那么直接暴力相加即可
        if left == right:
            for i in range(l[1]-1, l[2]):
                ans += nums[i]
        # 不在一个区间，那么只有起点和终点可能不是完整区间，中间的一定是完整区间
        else:
            # 起点恰好是区间起点，那么起点所在区间直接使用 sums 数组即可
            if 0 == (l[1]-1) % distance:
                ans += sums[left]
            else:
                for i in range(l[1]-1, distance*(1+left)):
                    ans += nums[i]
            # 中间的区间是完全的区间
            for i in range(1+left, right):
                ans += sums[i]
            # 最后的一个区间同理
            if 0 == l[2] % distance:
                ans += sums[right]
            else:
                for i in range(distance*right, l[2]):
                    ans += nums[i]
        print(ans)
