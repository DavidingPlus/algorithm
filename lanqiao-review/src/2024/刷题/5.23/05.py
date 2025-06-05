# 斤斤计较的小 Z
# https://www.lanqiao.cn/problems/2047/learning/?page=1&first_category_id=1&name=%E6%96%A4%E6%96%A4%E8%AE%A1%E8%BE%83%E7%9A%84%E5%B0%8FZ

s1 = input()
s2 = input()
# 本题可以通过在滑动窗口匹配的时候做出优化
print(s2.count(s1))
