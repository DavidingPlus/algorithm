#蛇形填数字
num, i, j = 0, 0, 0

#考虑向左下移动和右上移动的情况 加起来偶数右上移动 奇数左下移动
while True:
    num += 1
    if i == 19 and j == 19:
        break
    if (i + j) % 2 == 0:
        if i > 0:
            i -= 1  #如果到了边界就不懂i 只动j来实现变动!!!
        j += 1
    else:
        if j > 0:
            j -= 1
        i += 1

print(num)