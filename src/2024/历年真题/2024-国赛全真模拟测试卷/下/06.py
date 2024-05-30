# https://www.lanqiao.cn/problems/17152/learning/

# 思考另一种进行暴力枚举的方式，对于每一个区间，都有一个最小值，我们完全可以认为这个区间是由改最小值开始向左向右蔓延得到的区间，并且过程中我们保证该区间的最小值就是该数字（如果超出就是另一个数字对应的该规则下的区间），因此最小值就找到了，所以最大值就有区间长度确定，因此需要的答案就是以每个数字为最小值，向外扩充得到的最长区间的乘积的最大值

# 因此我们需要知道一个数字右边和左边第一个小于它的值，这完全可以使用单调栈进行求解
def workRight(nums):
    n = len(nums)

    # 这里有一个关于 res 超时的点 ，因为头插，会导致所有元素的移动，因此我们先开数组，然后进行赋值
    res = [-1 for _ in range(n)]
    # 为了和单调队列统一， s 中还是记录下标，注意 s 不能先开了然后赋值哈，因为需要入栈和弹栈
    s = []

    for i in range(n-1, -1, -1):
        while 0 != len(s) and nums[i] <= nums[s[-1]]:
            s.pop(-1)

        if 0 == len(s):
            res[i] = -1
        else:
            res[i] = s[-1]

        # 注意这一条语句在 res 后面，原因见 01.py
        s.append(i)

    return res


def workLeft(nums):
    n = len(nums)

    res = [-1 for _ in range(n)]
    s = []

    for i in range(0, n, 1):
        while 0 != len(s) and nums[i] <= nums[s[-1]]:
            s.pop(-1)

        if 0 == len(s):
            res[i] = -1
        else:
            res[i] = s[-1]

        s.append(i)

    return res


n = int(input())
nums = list(map(int, input().split()))

leftList = workLeft(nums)
rightList = workRight(nums)

ans = -1
for i in range(n):
    left = 0 if -1 == leftList[i] else 1+leftList[i]
    right = n-1 if -1 == rightList[i] else rightList[i]-1

    ans = max(ans, (right-left+1)*nums[i])

print(ans)
