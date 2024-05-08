#给定一个年份判断是不是闰年
# 给定一个年份，判断这一年是不是闰年。
# 当以下情况之一满足时，这一年是闰年：
# 1，年份是4的倍数而不是100的倍数；
# 2．年份是400的倍数。
# 具他的年份都不是闰年。

year = int(input())
if (not (year % 4) and year % 100) or not (year % 400):
    print('yes')
else:
    print('no')