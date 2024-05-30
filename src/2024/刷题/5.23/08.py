# 区间修改、区间求和
# https://www.lanqiao.cn/problems/1133/learning/

from math import sqrt

# 同上题，注释见 08.py
N, Q = map(int, input().split())
nums = list(map(int, input().split()))

distance = int(sqrt(N))+1
sums = [0 for _ in range(N//distance if 0 == N % distance else 1+N//distance)]
for i in range(N):
    sums[i//distance] += nums[i]

for _ in range(Q):
    l = list(map(int, input().split()))

    if 1 == l[0]:
        # 由于需要更新 nums 数组，只能一个一个更新
        # TODO 超时 1/4 ，后续（见 5.24 ）使用树状数组和线段树进行优化
        # 这个地方一个一个修改，太费时间了，主要是不知道查找的范围，需要更新 nums 数组， 只能一个一个更新
        for i in range(l[1]-1, l[2]):
            nums[i] += l[3]
            sums[i//distance] += l[3]
    else:
        ans = 0
        left = (l[1]-1)//distance
        right = (l[2]-1)//distance

        if left == right:
            for i in range(l[1]-1, l[2]):
                ans += nums[i]
        else:
            if 0 == (l[1]-1) % distance:
                ans += sums[left]
            else:
                for i in range(l[1]-1, distance*(1+left)):
                    ans += nums[i]

            for i in range(1+left, right):
                ans += sums[i]

            if 0 == l[2] % distance:
                ans += sums[right]
            else:
                for i in range(distance*right, l[2]):
                    ans += nums[i]

        print(ans)
