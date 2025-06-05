# accumulate 累加
from itertools import accumulate

# 可以用来求前缀和
# 如果提供了关键字参数 initial，则累加会以 initial 值开始，一般设置为 0 就是我们最常用的前缀和的模式
a = [1, 2, 3, 4]
print(list(accumulate(a)))  # [1, 3, 6, 10]
print(list(accumulate(a, initial=0)))  # [0, 1, 3, 6, 10]
print(list(accumulate(a, initial=1)))  # [1, 2, 4, 7, 11]
