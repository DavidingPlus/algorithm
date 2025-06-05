# 1-2020之间有多少个字符'2'
num = 0
for i in range(1, 2021):
    ch = str(i)
    num += ch.count('2')
print(num)