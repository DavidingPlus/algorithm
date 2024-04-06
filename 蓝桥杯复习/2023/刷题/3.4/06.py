#求圆的面积 保留七位小数
import math

r = int(input())
s = math.pi * r**2
#由于需要四舍五入保留七位 需要用到format()函数
s = format(s, ".7f")  #.7f表示保留到小数点后面第七位
print(s)
