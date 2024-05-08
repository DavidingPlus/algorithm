# https://www.lanqiao.cn/problems/5127/learning/?page=1&first_category_id=1&second_category_id=15&difficulty=20

n = int(input())
for _ in range(n):
    s = input()
    # 转为 set 的长度为 2 并且需要首字符只出现 1 次或者 3 次，这样两个条件都弥补了彼此的缺陷
    # 例如 aabb 满足第一个条件但不是， abbc 满足第二个条件但不是
    cnt = s.count(s[0])
    if 2 == len(set(s)) and (1 == cnt or 3 == cnt):
        print("Yes")
    else:
        print("No")
