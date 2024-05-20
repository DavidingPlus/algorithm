import functools
import time


# 加上 lru_cache ，自带备忘录功能
# tips： 为了兼容低版本的 python 和蓝桥杯测试环境的 python ，加上默认参数 None
@functools.lru_cache(None)
def fib(n):
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)


start_time = time.time()
print(fib(400))
end_time = time.time()

duration = end_time - start_time
print("Time: {:.8f} seconds".format(duration))
