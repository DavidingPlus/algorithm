# https://www.lanqiao.cn/problems/606/learning/?page=1&first_category_id=1&name=%E6%95%B0%E7%9A%84%E5%88%86%E8%A7%A3

def check(num):
    s = str(num)
    return '2' not in s and '4' not in s


n = 2019
ans = 0
# 在遍历过程中保证 k > j > i，这样得到的结果是唯一的
for i in range(1, n):
    if check(i):
        for j in range(1+i, n):
            if check(j):
                k = n - i - j
                if k > j and check(k):
                    ans += 1
print(ans)
# print(40785)
