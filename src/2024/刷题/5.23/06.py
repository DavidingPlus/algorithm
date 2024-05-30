# 单点修改，区间查询
# https://www.lanqiao.cn/problems/2340/learning/

# TODO 超时 2/6

# 先用前缀和写一次
N = int(input())
nums = list(map(int, input().split()))
m = int(input())

preSum = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    preSum[i] = preSum[i-1] + nums[i-1]

for _ in range(m):
    l = map(int, input().split())
    # 增加
    if 1 == l[0]:
        for i in range(l[1], 1+N):
            preSum[i] += l[2]
    # 区间求和
    else:
        print(preSum[l[2]]-preSum[l[1]-1])
