# 最小质因子之和
# https://www.lanqiao.cn/problems/1151/learning/

# 使用筛法标记 [2, n] 中每个数的最小质因子
def work(n):
    mark = [-1 for _ in range(1+n)]

    for i in range(2, 1+n):
        if -1 == mark[i]:
            mark[i] = i

            for j in range(i+i, 1+n, i):
                if -1 == mark[j]:
                    mark[j] = i

    return mark


T = int(input())
nums = [0 for _ in range(T)]
N = 0
for i in range(T):
    nums[i] = int(input())
    N = max(N, nums[i])

l = work(N)

preSum = [0 for _ in range(1+N)]  # 为了兼容边界条件，初始化为 0
for i in range(2, 1+N):
    preSum[i] = preSum[i-1]+l[i]

for i in range(T):
    print(preSum[nums[i]] - preSum[2-1])
