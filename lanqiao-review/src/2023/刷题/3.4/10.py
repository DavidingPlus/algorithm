#得到某一数值金币的最后日期 1 3 6 10
#                      1 2 3 4
#也就是说 得到第n枚金币的天数是 n*(n-1)/2 + 1 到 n*(n+1)/2
day = int(input())

coin = 0
coin_day = 1
#从第一天开始遍历得到金币数
for each in range(day):  #each+1才是真正的天数
    coin += coin_day
    if (each + 1) + 1 > coin_day * (coin_day + 1) / 2:
        coin_day += 1

print(coin)