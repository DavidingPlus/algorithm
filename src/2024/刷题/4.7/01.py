# https://www.lanqiao.cn/problems/2409/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023

nums = [99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18,
        99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77]

ans = 0
for i in range(len(nums)):
    for j in range(1+i, len(nums)):
        if nums[i]*nums[j] >= 2022:
            ans += 1
print(ans)
# print(189)
