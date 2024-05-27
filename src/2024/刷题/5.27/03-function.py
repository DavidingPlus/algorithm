# 从 03.py 中提取出一些位运算的函数

# 判断某个数的二进制表示中是否存在相邻的两个 1
def hasAdjacentOnes(n):
    return 0 != n & (n >> 1)


# 判断两个数是否在同样的二进制位置都是 1
def hasCommonOnes(a, b):
    return 0 != a & b


# 计算一个数二进制中 1 的个数
def countOnes(n):
    cnt = 0
    while n > 0:
        if n & 1:
            cnt += 1
        n >>= 1
    return cnt


print(hasAdjacentOnes(6))  # True (110 in binary)
print(hasCommonOnes(5, 3))  # True (101 & 011)
print(countOnes(7))         # 3 (111 in binary)
