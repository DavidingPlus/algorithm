# https://www.lanqiao.cn/problems/17113/learning/

from datetime import datetime, timedelta

start = datetime(2023, 1, 1)
end = datetime(2024, 1, 1)

ans = 0
while start != end:
    if '1' in str(start) or 0 == start.weekday():
        ans += 5
    else:
        ans += 1
    start += timedelta(days=1)

print(ans)
# print(1333)
