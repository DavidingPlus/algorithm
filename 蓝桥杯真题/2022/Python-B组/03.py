# https://www.lanqiao.cn/problems/2120/learning/?page=1&first_category_id=1&name=%E7%BA%B8%E5%BC%A0%E5%B0%BA%E5%AF%B8

def swap(a, b) -> list:
    return [b, a]


a = 1189
b = 841
# 计算 A0 - A9 的纸张大小
A = [[-1]*2 for _ in range(10)]
for i in range(10):
    A[i] = [a, b]
    a //= 2
    if a <= b:
        a, b = swap(a, b)

s = input()
print(A[int(s[1])][0])
print(A[int(s[1])][1])
