# 在函数中修改全局变量的时候记得加上 global ，不管是简单类型还是复杂类型
a = 1


def f():
    global a
    a = 2


print(a)
f()
print(a)
