import datetime

m = int(input())
d = int(input())

try:
    date = datetime.datetime(year=2021, month=m, day=d)  # 日期不对的时候会ValueError
except ValueError:
    print("no")
else:
    print("yes")
