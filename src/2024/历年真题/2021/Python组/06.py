# https://www.lanqiao.cn/problems/1452/learning/?page=1&first_category_id=1&name=%E6%97%B6%E9%97%B4%E6%98%BE%E7%A4%BA

import datetime


def timeFormat(val):
    return "%02d" % val


n = int(input())

# datatime 构造函数中不能设置 毫秒 milliseceonds，只能设置微秒 microseconds，注意二者的区别!!!
start = datetime.datetime(1970, 1, 1, 0, 0, 0)
start += datetime.timedelta(milliseconds=n)

# 双引号里用单引号!!!
print(f"{timeFormat(start.hour)}:{timeFormat(start.minute)}:{timeFormat(start.second)}")
