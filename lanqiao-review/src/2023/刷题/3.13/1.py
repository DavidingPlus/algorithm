# 长度最短也就是每两个相邻的都进行了交换，没有多余不交换的两个字符，利用率很高
# 所以交换次数==比较次数 对于冒泡排序，比较次数与n的关系 次数==n*(n-1)//2
# 15*14//2==105 14*13//2==91
# 长度为15
dest_str = "abcdefghijklmno"  # 排序过后的字符串
res_str = dest_str[::-1]  # 需要105次数的初始字符串(不是原字符串)
#'onmlkjihgfedcba'
# res排序105次到dest 原字符串排序100次到dest 所以res交换5次 保证字典序最小即可 把j交换到最前面
ans_str = "jonmlkihgfedcba"
print(ans_str)
