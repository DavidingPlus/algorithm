# 最小质因子之和
# https://www.lanqiao.cn/problems/1151/learning/

# 同质因数的思路一样，考虑筛法
T = int(input())
l = []
top = -1
for _ in range(T):
    l.append(int(input()))
    top = max(top, l[len(l)-1])  # 题目数据会保证 top>=2

# 最大值选择列表中的最大值
prime = [0 for _ in range(1+top)]
for i in range(2, 1+top):
    if 0 == prime[i]:  # 代表是质数，最小质因子是其本身
        prime[i] = i
        for j in range(i+i, 1+top, i):
            if 0 == prime[j]:
                # 这里类似于先到先得的感觉，例如 2 先遇到 8 ，那么填 2 ，后续 4 再次遇到就不填，结果是正确的
                prime[j] = i

# 为了省事，再做一个前缀和
preSum = [0 for _ in range(1+top)]
preSum[2] = prime[2]
for i in range(3, 1+top):
    preSum[i] = preSum[i-1]+prime[i]

for i in range(T):
    print(preSum[l[i]])
