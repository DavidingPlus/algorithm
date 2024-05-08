import math


def get_combinations(n, m):
    return math.factorial(n) // (math.factorial(m) * math.factorial(n - m))


# math.comb(n,m)  # 组合


def get_permutation(n, m):
    return math.factorial(n) // math.factorial(n - m)


# math.perm(n,m)  # 排列

n = int(input())
ans = 0
if n == 1:
    ans = 1
    print(ans)
else:
    # 杨辉三角第k行对应到数列中的序号(从0开始) k(k-1)//2 到 k(k+1)//2-1
    # 每一行里面最大的元素的坐标(相较于)行首坐标 是中间的那个(偶数个数就是中间的那两个) 也就是(k^2-1)//2
    # 先找到该正整数可能位于第几行 从第三行开始遍历 注意第三行row=2
    # 如果该行的最大值都比n小 那么肯定不在这一行 其他行逐个遍历
    row = 2
    row_max = 2  # 第3行的row_max
    while row_max < n:
        row += 1
        row_max = get_combinations(row, row // 2)

    # 从第(row+1)行开始依次向上遍历
    while True:
        for i in range(row // 2 + 1):
            if get_combinations(row, i) == n:
                ans = row * (row + 1) // 2 + i + 1  # 由于是第几个数比下标多1
                print(ans)
                exit()
        row += 1
