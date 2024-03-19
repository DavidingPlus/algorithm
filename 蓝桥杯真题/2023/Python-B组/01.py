# https://www.lanqiao.cn/problems/3496/learning/?subject_code=3&group_code=4&match_num=14&match_flow=1&origin=cup

# def judge(num, num2):
#     l = list(str(num))
#     l2 = list(str(num2))
#     # 拿到这个列表之后，比如 20254 -> [ '2', '0', '2', '5', '4' ]
#     # 需要匹配 2024 ，那么从 2 开始从头开始在 20254 里面找 2024 的各个数，按照顺序找，一定能够找出来，否则找不出来
#     index = 0
#     for i in range(len(l)):
#         if l2[index] == l[i]:
#             index += 1
#             if index == len(l2):  # 这里 break 掉，以免越界
#                 break
#     return index == len(l2)  # index 判断之后加了 1 ，所以是等于长度


# ans = 0
# for i in range(12345678, 1 + 98765432):
#     if judge(i, 2023):
#         print(i) # print()的开销很大，时间很长，所以这里我们为了看进度，还是打印少一点的包含 2023 的数
#         ans += 1
# print(98765432 + 1 - 12345678 - ans)  # 98765432 + 1 - 12345678 - 460725
print(85959030)
