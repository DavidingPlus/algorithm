# https://www.lanqiao.cn/problems/2133/learning/?page=1&first_category_id=1&name=GCD

# import math
# math 库中的 gcd() 和 icm() 分别求出两个或者多个数的最大公约数和最小公倍数
# 之前用辗转相除法自己推出了两个数的最大公约数和最小公倍数

# 题目保证 a 和 b 一定不同
a, b = map(int, input().split(' '))
# 我们保证 a < b
if a > b:
    a, b = [b, a]
# 关于 gcd(a+k, b+k)，我们考虑辗转相除的过程
# 7 / 5 = 1 ... 2
# 5 / 2 = 2 ... 1
# 2 / 1 = 2 ... 0
# 因此最大公约数是 1 ，我们观察发现第二三步就是 5 和 2 辗转相除的过程，因此 5 和 2 的最大公约数等于 7 和 5 的最大公约数
# 对应到题目就是 gcd(a+k, b+k) == gcd(a+k, b-a)，这就把第二个数变成定值了
# 所以最大公约数的答案一定是 b-a，只需要考虑步长就行了

# 这一部分也可以人为计算了
# k = 1
# while 0 != (a+k) % (b-a):
#     k += 1
# print(k)
print((b-a)-(a % (b-a)))
