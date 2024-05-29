# https://www.lanqiao.cn/problems/17142/learning/

# 递推公式推出为 n*(n+1)*(n+2)//6

i = 1
while i*(i+1)*(i+2)//6 <= 20230610:
    i += 1

print(i-1)
# print(494)
