# 请你帮助小蓝，给了一个单词后，帮助他找到出现最多的字母和这个字母出现的次数。
# 如果有多个字母出现的次数相等，输出字典序最小的那个。字典序就是比较两个字符的大小 小的那个输出
word_num = dict()

str = input()
for ch in str:
    try:
        word_num[ch]
    except KeyError as e:
        word_num[ch] = 1
    else:
        word_num[ch] += 1

# 遍历word_num中出现最多的字母
max_ch = ''
max_num = 0
keys = word_num.keys()
for key in keys:
    # 第二个条件是按字典序最小输出
    if word_num[key] > max_num or (word_num[key] == max_num and key < max_ch):
        max_num = word_num[key]
        max_ch = key

print(max_ch)
print(max_num)

# print(word_num)
