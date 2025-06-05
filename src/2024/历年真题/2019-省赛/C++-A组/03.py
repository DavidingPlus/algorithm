# https://www.lanqiao.cn/problems/601/learning/?page=1&first_category_id=1&name=%E6%9C%80%E5%A4%A7%E9%99%8D%E9%9B%A8%E9%87%8F

# x x x a x x x
# x x x b x x x
# x x x c x x x
# x x x max x x x
# x x x e x x x
# x x x f x x x
# x x x g x x x

# 画一个图就直观了，我们看那些地方是必须比 max 大的
# 首先是 max 这行后面三个
# e f g 肯定比 max 大，故他们后面三个也比 max 大，一行 4 个
print(7*7-3-3*4)
