# 题目要求的非空子串应该是可以重复的
# 求一个字符串其中恰好出现一次的字符个数
# TODO
def num_onetime(strs: str) -> int:
    # 将字符和出现次数的信息传入字典中
    str_dict = dict()
    for ch in strs:
        try:
            str_dict[ch]
        except KeyError:
            str_dict[ch] = 1
        else:
            str_dict[ch] += 1
    # 得到字典过后遍历字典来找到出现一次的字符个数
    keys = str_dict.keys()
    count = 0
    for key in keys:
        if str_dict[key] == 1:
            count += 1
    return count


def num_onetime2(strs: str) -> int:
    # 遍历字符串 如果出现该字符的个数是1 那么个数加1
    count = 0
    for ch in strs:
        if strs.count(ch) == 1:
            count += 1
    return count


strs = input()
# 遍历该字符串的子串
sum = 0
for i in range(len(strs)):
    sum += 1  # 单个字符串必然是出现一次的字符 直接加1
    for j in range(i + 1, len(strs)):
        sum += num_onetime2(strs[i : j + 1])
print(sum)
# 这么暴力的话非常容易超时！！！
