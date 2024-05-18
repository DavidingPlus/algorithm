# https://www.lanqiao.cn/problems/3601/learning/

# 测试数据
# 1
# 97 5 10 11
# 263 993 322 996 262 855 234 591 41 962 352 38 885 98 345 407 83 306 279 350 416 600 660 710 197 952 1 972 567 56 134 859 158 766 815 781 201 537 433 411 409 675 1 579 176 107 296 512 201 770 885 168 955 469 472 660 915 503 95 167 447 889 810 372 700 976 417 161 116 727 337 76 342 80 802 879 304 874 253 787 761 467 453 93 902 613 111 79 752 244 291 882 439 108 856 462 404
# 结果
# 9419


from sys import maxsize

T = int(input())
for _ in range(T):
    N, A, B, K = map(int, input().split())
    nums = [0] + list(map(int, input().split()))
    # dp[i][j] 表示跳 i 次，到达 j 处吃的昆虫数的最大值， j 从 1 开始
    # TODO 思路没有问题，二位 dp 数组，但是为什么把初始化的值改为 0 就会出问题呢？返回结果就不正确
    dp = [[-maxsize for _ in range(1+N)] for _ in range(1+K)]
    dp[0][0] = 0

    for i in range(1, 1+K):
        for j in range(1, 1+N):
            # 可以静止不动
            dp[i][j] = max(dp[i][j], dp[i-1][j])
            # 可以跳，但不能超出边界
            for k in range(A, 1+B):
                if j-k >= 0:
                    # j 从 1 开始，但是我已经在 nums 数组头部加上了一个占位符
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k] + nums[j])
    print(max(dp[K]))
