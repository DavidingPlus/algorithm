# https://www.lanqiao.cn/problems/504/learning/?page=1&first_category_id=1&name=%E5%8D%95%E8%AF%8D%E5%88%86%E6%9E%90

# 题目的长度不超过 1000，那直接暴力
s = input()
d = dict()
for ch in s:
    if not ch in d:
        d[ch] = 1
    else:
        d[ch] += 1
ans = [' ', -1]
for key in d.keys():
    # 注意次数相等返回字典序最小的哪个
    if ans[1] < d[key] or (ans[1] == d[key] and ans[0] > key):
        ans = [key, d[key]]
print(ans[0])
print(ans[1])
