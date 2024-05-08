# https://www.lanqiao.cn/problems/3525/learning/?page=1&first_category_id=1&name=%E5%85%AC%E5%9B%A0%E6%95%B0%E5%8C%B9%E9%85%8D

from math import gcd

n = int(input())
A = list(map(int, input().split()))

# TODO 算法超时 4/9
# 如果存在多组，优先输出 i 小的，在输出 j 小的
ans = []
for i in range(n):
    flag = False
    for j in range(i+1, n):
        if gcd(A[i], A[j]) > 1:
            flag = True
            ans = [i, j]
            break
    if True == flag:
        break
print(1+ans[0], 1+ans[1])
