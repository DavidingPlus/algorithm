# 逆序对
# https://www.acwing.com/problem/content/description/790/

# 这个题目的思路，可以用数组 nums[i] 表示值为 i 的个数，由于我们是从左到右遍历，因此新进来的元素面对的 nums[i] 数组都是他之前的，因此可以很方便的通过前缀和的方法求得逆序对的个数，例如求比 1 大的（最大值是 4 ），只需要求 preSum[4] - preSum[1] 即可
# 涉及到前缀和，使用树状数组优化

N = int(input())
nums = list(map(int, input().split()))

# 由于 nums 数组的数据范围是 [1, 10**9] ，对于 999999992 999999993 999999994 999999995 999999996 999999991 这种恶心数据，没必要开这么大，全部使用相对值即可，即减去最小值
# 这样的相对最小值是 1 ，相对最大值就是 MAX-MIN+1 ，某一个 nums[i] 的相对值就是 nums[i]-MIN+1
MAX = max(nums)
MIN = min(nums)
f = [0 for _ in range(1+(MAX-MIN+1))]
# 修正下标问题，也为了防止干扰上面 MIN 的值
nums = [0]+nums


def lowbit(n):
    return n & (-n)


def get(pos):
    ans = 0
    while pos > 0:
        ans += f[pos]
        pos -= lowbit(pos)
    return ans


def update(pos, v):
    while pos <= MAX-MIN+1:
        f[pos] += v
        pos += lowbit(pos)


ans = 0
for i in range(1, 1+N):
    # 如果最大值 MAX 恰好是 nums[i] ，那么当前结果肯定是 0 ，可以优化一点点
    if MAX-MIN+1 != nums[i]-MIN+1:
        # get(MAX-MIN+1) 的值一定是目前为止所有的数的个数之和，因为是最大值的前缀和
        ans += (i-1)-get(nums[i]-MIN+1)
    update(nums[i]-MIN+1, 1)
print(ans)
