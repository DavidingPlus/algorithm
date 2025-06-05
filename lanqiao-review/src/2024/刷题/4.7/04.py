# https://www.lanqiao.cn/problems/2413/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023

# 数据规模 1 到 100，直接暴力就行了
# 优化的化可以考虑前缀和数组
n, m = map(int, input().split())
matrixs = [[0 for _ in range(m)]for _ in range(n)]
cleans = []
t = int(input())
for _ in range(t):
    cleans.append(list(map(int, input().split())))

for e in cleans:
    for i in range(e[0], 1+e[2]):
        for j in range(e[1], 1+e[3]):
            matrixs[i-1][j-1] = 1

ans = 0
for i in range(n):
    for j in range(m):
        if 0 == matrixs[i][j]:
            ans += 1
print(ans)
