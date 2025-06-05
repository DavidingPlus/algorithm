# https://www.lanqiao.cn/problems/600/learning/?page=1&first_category_id=1&name=%E6%95%B0%E5%88%97%E6%B1%82%E5%80%BC

# Fibo 数列变式
a, b, c = 1, 1, 1
for i in range(4, 20190324+1):
    # 只求最后四位数字，保留后四位即可
    tmp = (a+b+c) % 10000
    a = b
    b = c
    c = tmp
print(c)
# print(4659)
