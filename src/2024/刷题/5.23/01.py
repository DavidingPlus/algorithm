# 字符串哈希模板
def init_hash(s, seed, mod):
    h = [0] * len(s)  # 记录哈希前缀和结果
    qp = [0] * len(s)  # 记录 seed 的幂取模
    h[0] = ord(s[0]) % mod
    qp[0] = 1

    for i in range(1, len(s)):
        # 递推公式注意画图理解
        h[i] = ((h[i-1] * seed) % mod + ord(s[i])) % mod
        qp[i] = (qp[i-1] * seed) % mod

    return [h, qp]


# 保证 r >= l
def get_hash(l, r, h, qp, mod):
    # 递推公式注意画图理解
    # 下面用到 l-1 ，所以对 l == 0 做特判，否则越界
    if 0 == l:
        return h[r]
    # 减法可能为负数，加上 mod 再取模保证不为负数
    return (h[r] - (h[l-1] * qp[r-l+1]) % mod + mod) % mod


# 测试
h, qp = init_hash("abcss", 233, 998244353)
print(h, qp)
print(get_hash(2, 4, h, qp, 998244353))

h, qp = init_hash("css", 233, 998244353)
print(h, qp)
print(get_hash(0, 2, h, qp, 998244353))

print()

# by the way, python 自带 hash 函数
print(hash(("abcss")[2:]))
print(hash("css"))
