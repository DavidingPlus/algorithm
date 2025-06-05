# https://www.lanqiao.cn/problems/17121/learning/

from math import sqrt


def check(n):
    # 判断 n 是否是一个混乘数字，处理它的因数即可
    for i in range(1, 1+int(sqrt(n))):
        if 0 == n % i:
            if sorted(str(n)) == sorted(str(i)+str(n//i)):
                return True
    return False


ans = 0
for i in range(1, 1+1000000):
    if (check(i)):
        ans += 1

print(ans)
# print(590)
