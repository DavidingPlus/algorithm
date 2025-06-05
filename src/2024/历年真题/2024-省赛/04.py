n = int(input())
nums = list(map(int, input().split()))

# 奇数个数数组，直接将中间弹掉
if len(nums) & 1:
    nums.pop(len(nums)//2)

# 双指针，从内往外扩散
left, right = len(nums)//2-1, len(nums)//2

ans = 0
while left >= 0:
    if 0 == left:
        ans += abs(nums[0]-nums[len(nums)-1])
    else:
        step = nums[right]-nums[left]  # 带有正负
        nums[left] += step
        # 考虑前一个的变化
        delta = nums[1+right]-nums[left-1]
        if (delta) * (delta-step) <= 0:
            nums[left-1] = nums[1+right]
        else:
            if abs(delta) > abs(delta-step):
                nums[left-1] += step
        ans += abs(step)
    left -= 1
    right += 1

print(ans)
