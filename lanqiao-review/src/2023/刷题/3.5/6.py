#求第n个质数
#判断是否为质数
def is_prime_num(num: int) -> bool:
    #先看是不是1或者2
    if num == 1:
        return False
    if num == 2:
        return True
    #优化下 大于2的偶数是合数
    if not num % 2:
        return False
    for i in range(2, num):
        if num % i == 0:
            return False
    return True


#求第n个质数
prime_count = 0
num = 1
n = int(input())
while prime_count < n:
    if is_prime_num(num) == True:
        prime_count += 1
    num += 1

print(num - 1)
