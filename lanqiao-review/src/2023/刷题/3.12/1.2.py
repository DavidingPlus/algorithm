# 先找到比n小的所有质数，再判断是否能被n整除
# 判断质数只用循环到n开方就可以了
n = int(input())

# 判断一个数是不是质数
def is_prime(num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        flag = False
        # 判断一个数是否为质数只需要循环到平方根的位置就可以了!!!!!
        end = int(num**0.5) + 1
        for i in range(2, end + 1):
            if num % i == 0:
                flag = True
                break
        if flag == True:
            return False
        else:
            return True


prime_list = list()
if n == 2:
    prime_list.append(2)
for i in range(2, n):
    if is_prime(i):
        prime_list.append(i)

count = 0
for elem in prime_list:
    if n % elem == 0:
        count += 1
print(count)
