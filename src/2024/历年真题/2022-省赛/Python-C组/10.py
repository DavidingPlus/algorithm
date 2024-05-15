# https://www.lanqiao.cn/problems/2139/learning/?page=1&first_category_id=1&name=%E5%9B%A0%E6%95%B0%E5%B9%B3%E6%96%B9%E5%92%8C


# 从因子的角度的角度考虑这个问题，见图
# 每个因子出现的次数等于 n // i（取下整)，因此公式就推导出来了
# 参考链接： https://gabrielxd.top/archives/lanqiao-p2139

def squareSum(a, b):
    return b*(b+1)*(2*b+1)//6 - (a-1)*((a-1)+1)*(2*(a-1)+1)//6


mod = pow(10, 9)+7
n = int(input())
ans = 0
# 但是其实这个地方仍然可以优化，根据 n // i 的结果可以将平方和进行分块，这样可以节省部分时间
# TODO 但是还是部分超时，不愧是压轴
left = 1
for i in range(1, n+1):
    if n//i != n//(i+1):
        # 计算 left 到 i 的和
        ans += n//i * squareSum(left, i)
        ans %= mod
        left = i+1
        if 1 == n // i:  # 从这里开始后面全都是 1 了，循环结束
            ans += squareSum(left, n)
            ans %= mod
            break
print(ans)
