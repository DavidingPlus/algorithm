# 奇怪的段
# https://www.lanqiao.cn/problems/12112/learning/

n, k = map(int, input().split())
A = [0]+list(map(int, input().split()))
P = [0]+list(map(int, input().split()))

# TODO 其中有些地方还没理解，并且算法本身虽然应该是对的，但是我还是有一些地方不懂
# dp 数组表示处理前 i 个数，划分 j 个区间能凑成的最大值
# 对于当前状态，新进来的这个数，要么划分成一个新区间，要么不划分，转移方程就出来了
# 改成滚动数组，否则内存容易超
dp = [-float('inf') for _ in range(1+k)]
dp[0] = 0

for i in range(1, 1+n):
    tmp = [-float('inf') for _ in range(1+k)]
    for j in range(1, 1+k):
        tmp[j] = max(dp[j], dp[j-1])+A[i]*P[j]
    dp = tmp

print(dp[k])
