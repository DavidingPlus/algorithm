# https://www.lanqiao.cn/problems/193/learning/?page=1&first_category_id=1&name=%E5%90%8E%E7%BC%80%E8%A1%A8%E8%BE%BE%E5%BC%8F

# 测试数据
# 2 1
# -3 -2 1 5
# ans: 11

N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(reverse=False)
# 题目的意思就是给数组中的元素做运算，有加法，有减法，转化一下就是给一个数加上符号，再相加，能够得出的最大值（不完全正确）
# 但是注意后缀和加法的区别，比如看上面的例子，一个减法，那我可以 -3 + -2 ，然后再取负号，这样仍然只用了一次减法，结果是 11，最大
# TODO
