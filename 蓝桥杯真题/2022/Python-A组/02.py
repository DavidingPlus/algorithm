# https://www.lanqiao.cn/problems/2131/learning/?page=1&first_category_id=1&name=%E5%AF%BB%E6%89%BE

# 根据图，这个数必然是 11 和 17 的倍数

# 下面的条件不可能一次罗列完，所以每次的 i 下限是会改变的，为了节省时间
# 好吧这个程序我为了节省时间用 cpp 跑的
i = 87613307
while True:
    num = i * (11*17)
    if 1 == num % 2 and 2 == num % 3 and 1 == num % 4 and 5 == num % 6 and 4 == num % 7 and 1 == num % 8 and 2 == num % 9 and 9 == num % 10 and 5 == num % 12 and 10 == num % 13 and 11 == num % 14 and 14 == num % 15 and 9 == num % 16 and 11 == num % 18 and 18 == num % 19 and 9 == num % 20 and 11 == num % 21 and 15 == num % 23 and 17 == num % 24 and 9 == num % 25 and 23 == num % 26 and 20 == num % 27 and 25 == num % 28 and 16 == num % 29 and 29 == num % 30 and 27 == num % 31 and 25 == num % 32 and 11 == num % 33 and 17 == num % 34 and 4 == num % 35 and 29 == num % 36 and 22 == num % 37:
        print(num)
        break
    i += 1
