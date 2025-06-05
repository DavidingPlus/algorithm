# 排列 permutation
# 组合 combinations
from math import factorial, perm, comb
from itertools import permutations, combinations


# [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]
print(list(permutations([1, 2, 3], 2)))
# [(1, 2), (1, 3), (2, 3)]
print(list(combinations([1, 2, 3], 2)))


# 数学上的排列，组合计算公式
# a >= b
def myComb(a, b):
    return factorial(a) // (factorial(b) * factorial(a-b))


# a >= b
def myPerm(a, b):
    return myComb(a, b) * factorial(b)


print(comb(3, 2))  # 3
print(perm(3, 2))  # 6

print(myComb(3, 2))  # 3
print(myPerm(3, 2))  # 6
