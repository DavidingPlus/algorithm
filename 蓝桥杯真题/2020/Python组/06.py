# https://www.lanqiao.cn/problems/502/learning/?page=1&first_category_id=1&name=%E6%88%90%E7%BB%A9%E7%BB%9F%E8%AE%A1

n = int(input())
passRate = 0
excellentRate = 0
for i in range(n):
    score = int(input())
    if score >= 60:
        passRate += 1
    if score >= 85:
        excellentRate += 1
# 直接保留两位小数再相乘和先算为百分比在保留整数还是有区别的哈!!!
print(f"{ round(passRate / n * 100 )}%")
print(f"{ round(excellentRate / n * 100 )}%")
