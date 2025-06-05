#给一个十六进制数，将其转化为十进制数
num_16 = input()
#转化为十进制
num_10 = int(num_16, 16)  #第二个参数填入16代表16进制 将其转化为16进制
print(num_10)

#十进制转化为十六进制 hex
num_10 = int(input())  #输入num_10 为65535
#转化为十六进制
num_16 = hex(num_10)
# print(num_16)  #结果为 0xffff 如果需要将其格式化需要处理 切片 upper()将小写变为大写
num_16 = num_16[2:].upper()
print(num_16)

#十进制转化为八进制 oct
num_10 = int(input())  #输入65535
#转化为八进制
num_8 = oct(num_10)
# print(num_8)  #0o177777 同上
num_8 = num_8[2:].upper()
print(num_8)

#十进制转化为二进制 bin
#略