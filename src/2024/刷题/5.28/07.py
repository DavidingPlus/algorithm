# 最大公约数
# https://www.lanqiao.cn/courses/38752/learning/

from math import log2, gcd

n = int(input())
nums = list(map(int, input().split()))

# 如果数组中原本就存在 1 ，那么只需要 n-count(1) 次数即可，从这些 1 开始向旁边扩张
if 1 in nums:
    print(n - nums.count(1))

else:
    MAX = 1+int(log2(n))
    f = [[0 for _ in range(MAX)] for _ in range(n)]

    for i in range(n):
        f[i][0] = nums[i]

    for j in range(1, MAX):
        for i in range(n):
            if i+(1 << (j-1)) >= n:
                f[i][j] = f[i][j-1]
            else:
                f[i][j] = gcd(f[i][j-1], f[i+(1 << (j-1))][j-1])

    def get(l, r):
        j = int(log2(r-l+1))
        return gcd(f[l][j], f[r+1-(1 << j)][j])

    # 如果整个序列的 gcd 不为 1 ，说明凑不出来
    if 1 != get(0, n-1):
        print(-1)

    else:
        ans = n
        for i in range(n):
            # 如果数组中原本就存在 1 ，那么只需要 n-count(1) 次数即可，从这些 1 开始向旁边扩张（这一步在前面已经做了）
            # 如果数组中没有 1 ，那么找到一个最短的 gcd 为 1 的子序列，这个最短的子序列当中得到一个 1 的次数是 len -1 ，之后回到前面的情况即可，查找最短子序列使用二分
            # TODO 这个东西经过数据验证是正确的，但是我不知道为什么

            l, r = i, n-1
            while l <= r:
                mid = (l+r)//2
                g = get(i, mid)

                # g 不可能小于 1 ，一个序列的最大公约数的最小值就是 1 ，因此不用考虑这个问题
                if 1 == g:
                    r = mid-1
                else:
                    l = 1+mid
            # 这里需要验证一下是否符合条件，例如 4 6 的最小值是 2 ，这时候这个序列显然是不能满足条件的，由于等于的时候改变 r ，因此使用 l
            if l < n and 1 == get(i, l):
                ans = min(ans, l-i+1)

        print(ans-1+n-1)
