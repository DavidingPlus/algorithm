# 时间加法
# 现在是a点b分 过了t分钟后是几点几分
import datetime

a = int(input())
b = int(input())
t = int(input())

date = datetime.datetime(year=2023, month=3, day=11, hour=a, minute=b)
delta = datetime.timedelta(minutes=t)
date += delta
print(date.hour)
print(date.minute)
