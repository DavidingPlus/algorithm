# https://www.lanqiao.cn/problems/2127/learning/?page=1&first_category_id=1&name=%E6%B6%88%E9%99%A4%E6%B8%B8%E6%88%8F


# 先拿到某次的所有边缘字符下标，然后删除，之后调用递归继续处理，直到为空或者找不到边缘字符
# TODO 该算法超时了，后续优化
def removeEdgeCh(s: str):
    # 递归出口
    if 0 == len(s):
        return "EMPTY"
    flags = [False] * len(s)
    # 第一个字符和最后一个字符不需要判断
    for i in range(1, len(s)-1):
        if s[i] == s[i-1] and s[i] != s[i+1]:
            flags[i] = True
            flags[i + 1] = True
        if s[i] == s[i+1] and s[i] != s[i-1]:
            flags[i] = True
            flags[i - 1] = True
    # 递归出口
    if not True in flags:
        return s
    newS = str()
    for i in range(len(s)):
        if False == flags[i]:
            newS += s[i]
    return removeEdgeCh(newS)


s = input()
print(removeEdgeCh(s))
