# https://www.lanqiao.cn/problems/2131/learning/?page=1&first_category_id=1&name=%E5%AF%BB%E6%89%BE

# 更详细的注释见 .cpp

# greatest common divisor 最大公约数
def gcd(val1, val2):
    # 辗转相除法
    # a 被除数 b 除数
    a, b = max(val1, val2), min(val1, val2)
    while a % b != 0:
        a, b = b, a % b
    return b

# least common multiple 最小公倍数
def lcm(val1, val2):
    return val1 // gcd(val1, val2) * val2

mod = [0, 0, 1, 2, 1, 4, 5, 4, 1, 2, 9, 0, 5, 10, 11, 14, 9, 0, 11, 18, 9, 11, 11, 15, 17, 9, 23, 20, 25, 16, 29, 27, 25, 11, 17, 4, 29, 22, 37, 23, 9, 1, 11, 11, 33, 29, 15, 5, 41, 46]

# 初始状态
ans, step = 3, 2
for i in range(3, 50):
    # 加入新的数，首先在原步长上进行判断
    while mod[i] != ans % i:
        ans += step
    # 更新步长
    step = lcm(step, i)

print(ans)  # 输出结果
