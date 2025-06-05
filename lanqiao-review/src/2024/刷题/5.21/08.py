# 二进制枚举的思想应用（类似于状压 DP 的状态表示方法）
def binaryEnum(l):
    enums = []
    for i in range(1 << len(l)):
        tmp = []
        # 看每一位看状态是否激活
        for j in range(len(l)):
            if i & (1 << j):
                tmp.append(l[j])
        enums.append(tmp)
    return enums


l = [1, 2, 3]
enums = binaryEnum(l)
for e in enums:
    print(e)
