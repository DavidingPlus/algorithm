# https://www.lanqiao.cn/problems/3519/learning/?subject_code=3&group_code=3&match_num=14&match_flow=1&origin=cup

# 找子串是从前往后找，由于 ? 可以代表 0 或者 1 ，因此 0?, 1?, ?0, ?1, ?? 是代表 00 或者 01 的
# 找到 00 或者 01 将 i 往后挪两位，结合上面的情况，就很简单了这个题目

s = input()
judge = ['00', '11', '0?', '1?', '?0', '?1', '??']

ans = 0
i = 0
while i < len(s):
    if s[i: 2 + i] in judge:
        ans += 1
        i += 1
    i += 1
print(ans)
