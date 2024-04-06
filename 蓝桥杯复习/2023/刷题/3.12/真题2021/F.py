import datetime

millsecond = int(input())

start = datetime.datetime(year=1970, month=1, day=1)
delta = datetime.timedelta(milliseconds=millsecond)
end = start + delta

hours = format(end.hour, "02d")
mins = format(end.minute, "02d")
secs = format(end.second, "02d")
print(f"{hours}:{mins}:{secs}")
