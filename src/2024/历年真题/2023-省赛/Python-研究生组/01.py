# # https://www.lanqiao.cn/problems/3494/learning/?page=1&first_category_id=1&name=%E5%B7%A5%E4%BD%9C%E6%97%B6%E9%95%BF

from datetime import datetime, timedelta


# 例子：2022-11-17 10:20:18
def stringToDate(s: str) -> datetime:
    cut = s.split()
    yearMonthDay = cut[0].split('-')
    hourMinSec = cut[1].split(':')
    return datetime(year=int(yearMonthDay[0]), month=int(yearMonthDay[1]), day=int(yearMonthDay[2]), hour=int(hourMinSec[0]), minute=int(hourMinSec[1]), second=int(hourMinSec[2]))


with open("./01_data.txt", mode="r", encoding="utf-8") as file:
    dates = []
    while True:
        dateStr = file.readline()
        # 读取完毕，退出
        if "" == dateStr:
            break
        # 弹掉末尾的 '\n'
        if '\n' == dateStr[len(dateStr)-1]:
            dateStr = dateStr[:-1:]
        dates.append(stringToDate(dateStr))
    # 排序， list 可以对 datetime 结构按照时间顺序进行排序，默认升序
    dates.sort(reverse=False)
    # 这样就可以简单计算时间了
    ans = 0
    for i in range(0, len(dates), 2):
        print(dates[i], dates[1+i])
        timeDelta: timedelta = dates[1+i] - dates[i]
        ans += int(timeDelta.total_seconds())
    print(ans)
# print(5101913)
