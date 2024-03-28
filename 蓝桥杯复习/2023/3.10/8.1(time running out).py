# 满足n的阶乘末尾恰好有k个0的最小n是多少
# 如果这样的n不存在输出-1
# TODO

k = int(input())


def get_Factorial(num):
    ans = 1
    for i in range(2, num + 1):
        ans *= i
    return ans


# 判断num的阶乘的后面是是不是恰好有k个0
def judge(num):
    strs = str(get_Factorial(num))[::-1]
    return strs[:k] == "0" * k and strs[k] != "0"


# 判断是否不存在 因为如果0的个数较多的话不管n多大都不会在改变后面的0了 所以如果检测出个数比0多那么肯定不存在
def judge_not_exist(num):
    strs = str(get_Factorial(num))[::-1]
    return strs[:k] == "0" * k and strs[k] == "0"


n = 1
flag = False
while True:
    # 先判断是否不存在
    if judge_not_exist(n):
        flag = False
        break
    else:
        if judge(n):
            flag = True
            break
        n += 1
if flag:
    print(n)
else:
    print(-1)
