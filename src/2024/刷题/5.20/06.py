# 小明的字符串
# https://www.lanqiao.cn/problems/1203/learning/

S = input()
T = input()

# python 环境下的常规做法，因为 python 可以直接判断一个字符串是否包含另一个字符串，所以还是比较方便的
ans = 0
for i in range(len(T)):
    if T[:1+i] in S:
        ans = 1+i

print(ans)
