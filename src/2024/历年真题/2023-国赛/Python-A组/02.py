# https://www.lanqiao.cn/problems/17114/learning/?page=1&first_category_id=1&name=%E6%AE%8B%E7%BC%BA%E7%9A%84%E6%95%B0%E5%AD%97


# 对于显示出来的状态码，由于某些位没有亮，意思是显示为 0 的实际上可能是 1 ，因此从显示为 1 入手，显示为 1 就一定能够为 1

nums = ["1111110", "0110000", "1101101", "1111001", "0110011",
        "1011011", "1011111", "1110000", "1111111", "1111011"]

targets = ["0000011", "1001011", "0000001", "0100001", "0101011", "0110110", "1111111", "0010110", "0101001",
           "0010110", "1011100", "0100110", "1010000", "0010011", "0001111", "0101101", "0110101", "1101010"]


def check(nums: list, target: int):
    res = 0
    for e in nums:
        flag = True
        for i in range(len(target)):
            if '1' == target[i] and '0' == e[i]:
                flag = False
                break
        if flag:
            res += 1
    return res


ans = 1
for i in range(len(targets)):
    # 最高位不能为 0 ，这里人为计算发现不可能为 0 ，因此继续即可
    ans *= check(nums, targets[i])
print(ans)
# print(254016000)
