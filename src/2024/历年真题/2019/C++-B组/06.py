# https://www.lanqiao.cn/problems/191/learning/?page=1&first_category_id=1&name=%E7%89%B9%E5%88%AB%E6%95%B0%E7%9A%84%E5%92%8C

def check(n):
    s = str(n)
    return '2' in s or '0' in s or '1' in s or '9' in s


n = int(input())
ans = 0
for i in range(1, 1+n):
    if check(i):
        ans += i
print(ans)
