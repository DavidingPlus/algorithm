# https://www.lanqiao.cn/problems/17113/learning/?page=1&first_category_id=1&name=%E8%B7%91%E6%AD%A5%E8%AE%A1%E5%88%92

from datetime import datetime, timedelta

start = datetime(2023, 1, 1)
end = datetime(2024, 1, 1)

ans = 0
while start != end:
    # 查看日期中是否出现 1
    # 星期几，周一为 0 ，周天为 6
    if '1' in str(start) or 0 == start.weekday():
        ans += 5
    else:
        ans += 1
    start += timedelta(days=1)

print(ans)
# print(1333)
