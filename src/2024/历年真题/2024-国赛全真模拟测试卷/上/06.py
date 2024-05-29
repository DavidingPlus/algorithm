# https://www.lanqiao.cn/problems/17135/learning

ops = ['+', '-', '*', '/']


def opposite(op):
    if '+' == op:
        return '-'
    elif '-' == op:
        return '+'
    elif '*' == op:
        return '/'
    else:
        return '*'


def cal(a, b, op):
    if '+' == op:
        return a+b
    elif '-' == op:
        return a-b
    elif '*' == op:
        return a*b
    else:
        return a//b


s = input()

# 先按照 = 号分开，因为 = 号不会被擦掉
l = s.split('=')

# 如果擦掉的是 C
if '?' == l[1]:
    a, b = 0, 0
    for op in ops:
        nums = l[0].split(op)
        if 2 == len(nums):
            a, b = int(nums[0]), int(nums[1])
            print(cal(a, b, op))
            break
# 擦掉的是 A B 或者 op
else:
    nums = l[0].split('?')

    # 擦掉的是 A
    if '' == nums[0]:
        op = nums[1][0]
        b = int(nums[1][1:])
        print(cal(int(l[1]), b, opposite(op)))

    # 擦掉的是 B
    elif '' == nums[1]:
        op = nums[0][-1]
        a = int(nums[0][:-1])
        # 减法和处罚需要特殊处理一下
        if '-' == op:
            print(a-int(l[1]))
        elif '/' == op:
            print(a//int(l[1]))
        else:
            print(cal(int(l[1]), a, opposite(op)))

    # 擦掉的是 op
    else:
        a, b = int(nums[0]), int(nums[1])
        for op in ops:
            if int(l[1]) == cal(a, b, op):
                print(op)
                break
