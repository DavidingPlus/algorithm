# https://www.lanqiao.cn/problems/2360/learning/

from math import gcd

ans = 0
for i in range(1, 1+2020):
    if 1 == gcd(i, 1018):
        ans += 1

print(ans)
# print(1008)
