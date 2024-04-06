# 小蓝每天都锻炼身体。
# 正常情况下，小蓝每天跑1千米。
# 如果某天是周一或者月初（1日），为了激励自己，小蓝要跑2千米。
# 如果同时是周一或月初，小蓝也是跑2千米。
# 小蓝跑步已经坚持了很长时间，从2000年1月1日周六（含）到2020年10月1日周四（含）。请问这段时间小蓝总共跑步多少千米？

#这里用时间模块来处理
import datetime

start = datetime.datetime(year=2000, month=1, day=1)
end = datetime.datetime(year=2020, month=10, day=1)
delta = datetime.timedelta(days=1)  #这个表示时间间隔!!!
distance = 0

while start <= end:
    #这个函数用来求周几 注意周一返回0
    if start.weekday() == 0 or start.day == 1:
        distance += 2
    else:
        distance += 1
    start += delta

print(distance)