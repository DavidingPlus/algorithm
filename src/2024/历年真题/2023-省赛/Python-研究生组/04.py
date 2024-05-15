# https://www.lanqiao.cn/problems/3522/learning/?page=1&first_category_id=1&name=%E4%BA%92%E8%B4%A8%E6%95%B0%E7%9A%84%E4%B8%AA%E6%95%B0

from math import gcd

mod = 998244353
ans = 0

a, b = map(int, input().split())
n = a ** b

# TODO 铁超时 3/10
for i in range(1, n):
    if 1 == gcd(i, n):
        ans += 1
        ans %= mod
print(ans)
