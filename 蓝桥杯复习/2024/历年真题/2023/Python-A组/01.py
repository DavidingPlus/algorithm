# https://www.lanqiao.cn/problems/2408/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup
import datetime

date = datetime.datetime(1900, 1, 1)
num = 0

while not (9999 == date.year and 12 == date.month and 31 == date.day):
    if date.year // 1000 + date.year % 1000 // 100 + date.year % 1000 % 100 \
       // 10 + date.year % 1000 % 100 % 10 == date.month // 10 + date.month \
       % 10 + date.day // 10 + date.day % 10:
        num += 1
    date += datetime.timedelta(days=1)
print(num)
