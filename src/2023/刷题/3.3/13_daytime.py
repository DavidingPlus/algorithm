import datetime
#获取当前时间
print(datetime.datetime.now())
#获取当前日期
print(datetime.date.today())

#从时间戳获得日期
# Unix时间戳是特定日期到UTC的1970年1月1日之间的秒数。可以使用fromtimestamp()方法将时间戳转换为日期。
timestamp = datetime.date.fromtimestamp(1576244364)
print(timestamp)

datetime.datetime(year="", month="", day="")  #传入时间参数，返回时间格式的变量
datetime.timedelta(days="")  #返回参数对应的时间间隔，作用是可以进行时间加减
datetime.weekday()  #判断星期几，注意星期一返回0，星期二返回1，以此类推
