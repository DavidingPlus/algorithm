# https://www.lanqiao.cn/problems/1463/learning/?page=1&first_category_id=1&name=%E8%B4%A7%E7%89%A9%E6%91%86%E6%94%BE

# 先求因数
def getDigit(n) -> list:
    res = []
    i = 1
    while i*i <= n:
        if 0 == n % i:
            res.append(i)
            if i*i != n:
                res.append(n//i)
        i += 1
    return res


ans = 0
n = 2021041820210418
l = getDigit(n)
for i in l:
    for j in l:
        for k in l:
            if i*j*k == n:
                ans += 1
print(ans)
