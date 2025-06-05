import datetime

#通过datetime模块来实现日期的遍历!!!


#将字符串转化为日期格式 8位
def get_date(date_string: str) -> datetime:
    year = int(date_string[:4])
    month = int(date_string[4:6])
    day = int(date_string[6:8])
    return datetime.datetime(year=year, month=month, day=day)


#将日期格式转化为字符串
def date_string(date: datetime) -> str:
    date_str = str(date.year)
    #注意月份没超过10需要补0
    date_str += format(date.month, '02d')  #第一个0代表空白位补0 第二个2代表位宽 就是整数部分的位数
    date_str += format(date.day, '02d')
    return date_str


date = get_date(input())
delta = datetime.timedelta(days=1)
#不包括本身
date += delta

#找到回文日期
while True:
    date_str = date_string(date)
    if date_str[:4] == date_str[4:8][::-1]:
        print(date_str)
        break
    date += delta

#找到ABAB型回文日期
while True:
    date_str = date_string(date)
    if date_str[:4] == date_str[4:8][::-1] and date_str[:2] == date_str[2:4]:
        print(date_str)
        break
    date += delta
