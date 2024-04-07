# https://www.lanqiao.cn/problems/2412/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023

W, H, n, R = map(int, input().split())
towers = []
for _ in range(n):
    towers.append(list(map(int, input().split())))

ans = 0
for i in range(1+W):
    for j in range(1+H):
        for e in towers:
            if (i-e[0])**2+(j-e[1])**2 <= R**2:
                ans += 1
                break
print(ans)
