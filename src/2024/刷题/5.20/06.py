# 字符串哈希法

MOD = 998244353
SEED = 233
N = 100005

s = ""
h = [0] * N
qp = [0] * N


def init_hash(s):
    global h, qp
    qp[0] = 1
    h[0] = ord(s[0]) % MOD

    for i in range(1, len(s)):
        h[i] = (h[i - 1] * SEED % MOD + ord(s[i])) % MOD
        qp[i] = (qp[i - 1] * SEED) % MOD


def get_hash(l, r):
    if 0 == l:
        return h[r] % MOD

    prefix_hash = (h[r] - h[l - 1] * qp[r - l + 1] % MOD + MOD) % MOD
    return prefix_hash


# 测试
init_hash("abcss")
print(get_hash(2, 4))

init_hash("css")
print(get_hash(0, 2))
