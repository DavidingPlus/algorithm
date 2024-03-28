# 给定正整数n，有多少个质数是n的约数
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
        for i in range(2, end):
            if num % i == 0:
                flag = True
                break
        if flag == True:
            return False
        else:
            return True


num_list = list()
# 有个东西叫质因数分解，将该数字分解为质因数的乘积，去掉重复的就是质数因数的个数
# 将质数因数存到列表当中 每个进来的因子判重
# TODO
def get_factor(num) -> None:
    global num_list

    if is_prime(num):
        if not (num in num_list):
            num_list.append(num)
    else:
        for i in range(2, num):
            if is_prime(i) and num % i == 0:
                if (i in num_list) == False:
                    num_list.append(i)
                num = num // i
                get_factor(num)


get_factor(n)
print(len(num_list))
