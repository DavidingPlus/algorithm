# https://www.lanqiao.cn/problems/17151/learning/?page=1&first_category_id=1&name=%E6%95%B4%E6%95%B0%E5%8F%98%E6%8D%A2

def getSum(n: int):
    res = 0
    s = str(n)
    for e in s:
        res += int(e)
    return res


# TODO 超时 6/10
n = int(input())
ans = 0
while 0 != n:
    n -= getSum(n)
    ans += 1
print(ans)
