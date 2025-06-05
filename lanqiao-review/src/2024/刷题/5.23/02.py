# 小明的字符串
# https://www.lanqiao.cn/problems/1203/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E6%98%8E%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2

S = input()
T = input()

for i in range(len(T)):
    if T[:len(T)-i] in S:
        print(len(T)-i)
        break
