#顺子日期
#日期当中出现 012和123这种
import datetime

start=datetime.datetime(year=2022,month=1,day=1)
end=datetime.datetime(year=2022,month=12,day=31)
delta=datetime.timedelta(days=1)

count=0
while start<=end:
    #判断顺子日期
    #2022不可能  所以只有看后面 必然是月份和日的组合 所以必然只可能是 012 123这种
    date_str=str(start.year)+str(format(start.month,'02d'))+str(format(start.day,'02d'))
    if '012'in date_str or '123'in date_str:
        count+=1
    start+=delta
print(count)
