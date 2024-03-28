# https://www.lanqiao.cn/problems/2122/learning/?page=1&first_category_id=1&name=%E6%95%B0%E4%BD%8D%E6%8E%92%E5%BA%8F

# TODO 20 个点，超时了 2 个点

# 计算数位和
def digitSum(n: int) -> int:
    res = 0
    for e in list(str(n)):
        res += int(e)
    return res


n = int(input())
m = int(input())
data = []
for i in range(n):
    data.append(1+i)
# 这个排序的 lambda 写法，表示按照第一个排序，相同则按照第二个
data.sort(key=lambda e: (digitSum(e), e), reverse=False)
print(data[m-1])
