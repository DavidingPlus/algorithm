# 契合匹配
# https://www.lanqiao.cn/problems/5132/learning/?page=1&first_category_id=1&name=%E5%A5%91%E5%90%88%E5%8C%B9%E9%85%8D

# TODO 超时 28/35
n = int(input())
S = input()
T = input()

# 首先将 S 串的每个字符进行大小写转换
newS = str()
for i in range(n):
    if S[i].isupper():
        newS += S[i].lower()
    else:
        newS += S[i].upper()

# 至于循环问题，将字符串进行两倍扩展即可
# 例如 aBBcD 和 BcdaB ，将第一个字符串扩张两倍成为 aBBcDaBBcD ，判断 BcdaB 是否在里面即可
newS += newS
ans = newS.find(T)
if -1 != ans:
    print("Yes")
    print(min(ans, len(S)-ans))
else:
    print("No")
