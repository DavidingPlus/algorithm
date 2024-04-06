#提示:这里为爷爷会更好点
#答案19550604
import datetime

date = datetime.datetime(year=1900, month=1, day=1)
delta = datetime.timedelta(days=1)


def get_date_str(date: datetime) -> str:
    date_str = str(date.year)
    date_str += format(date.month, '02d')
    date_str += format(date.day, '02d')
    return date_str


while True:
    #一天一天遍历
    date_num = int(get_date_str(date=date))
    if not date_num % 2012 and not date_num % 3 and not date_num % 12 and date.month == 6:
        print(get_date_str(date=date))
        break
    date += delta
