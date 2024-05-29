# https://www.lanqiao.cn/problems/2211/learning/

# 自己推导通项公式即可

def quickPower(a, b):
    res = 1
    base = a
    while b > 0:
        if b & 1:
            res = res * base
        base = base*base
        b >>= 1
    return res


n = int(input())
ans = 4 * (100*(quickPower(10, 2*n)-1)
           - 220*(quickPower(10, n)-1) + 99*n) // (9*99)
print(ans)
