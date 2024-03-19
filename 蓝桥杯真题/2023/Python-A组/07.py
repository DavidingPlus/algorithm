# https://www.lanqiao.cn/problems/3527/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup
# 举一个例子
# 2! + 2! + 4! ， 这时 m 毫无疑问是 2， 因为 2! 没办法凑出一个 3! 来，除下来剩的小数不够凑成整数
# 本题中由于 Ai 之间可能相等，因此也存在可能合并成为下一个阶乘的可能，因此做所有的合并操作，直到不能合并，最小的即为答案
n = int(input())
A = list(map(int, input().split(' ')))
A.sort(reverse=False)

while True:
    num = A[0]
    # 无法合并直接 return
    if num >= len(A) or num != A[num]:
        break
    # 开始合并
    for i in range(1 + num):
        A.pop(0)
    # 插入新值
    num += 1
    A.insert(0, num)
    A.sort(reverse=False)

print(num)
