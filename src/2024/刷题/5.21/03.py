# 欧拉函数
# https://www.acwing.com/problem/content/description/875/

def phi(n):
    # 特别规定 phi(1)==1 ，以及循环的初始值 phi(2)==1 ，都可以通过下面的循环得出正确的值，这也进一步验证了这个算法的正确性
    res = float(n)
    i = 2
    # 这里只用枚举到 sqrt(n) 的位置，和下面对应
    while i*i <= n:
        if 0 == n % i:
            while 0 == n % i:
                n /= i
            res *= 1-1/i
        i += 1
    # 一个数最多只有一个大于 sqrt(n) 的质因子（反证法很容易证明），因此只用看最后分解质因数剩下来的数是否为 1 即可知道
    if 1 != n:
        res *= 1-1/n
    return int(res)


n = int(input())
for _ in range(n):
    print(phi(int(input())))
