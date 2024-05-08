# https://www.lanqiao.cn/problems/597/learning/?page=1&first_category_id=1&name=%E8%B7%91%E6%AD%A5%E9%94%BB%E7%82%BC

from datetime import datetime, timedelta

start = datetime(2000, 1, 1)
end = datetime(2020, 10, 2)  # 这里刻意多写一天，因为最后一天也要跑

ans = 0
while start != end:
    # 判断当天是不是周一或者月初
    # weekday() 接口，周一返回 0 ，周天返回 6
    ans += 1
    if 0 == start.weekday() or 1 == start.day:
        ans += 1  # 再多跑一公里

    start += timedelta(days=1)
print(ans)
# print(8879)
