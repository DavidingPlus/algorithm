from bisect import *

# 1)查找：
# bisect：查找目标元素右侧插入点
# bisect_left：查找目标元素左侧插入点
# bisect_right：查找目标元素右侧插入点
# 2)插入：
# insort：查找目标元素右侧插入点，并保序地插入元素
# insort_left： 查找目标元素左侧插入点，并保序地插入元素
# insort_right：查找目标元素右侧插入点，并保序地插入元素

# 注意最好是升序，升序目前返回的状态非常可观，其他顺序我没试过。。
l = [1, 2, 3, 3, 3, 4, 5]
pos = bisect(l, 3)  # 右
pos_left = bisect_left(l, 3)
pos_right = bisect_right(l, 3)
print(pos, pos_left, pos_right)  # 5 2 5 # 返回的下标是 1 开头的!!!

# 这个右侧左侧我不管
# 考试的时候我只使用 insort 因为插入能保证数组是有序的，知道这一点就行了
insort(l, 4.5)  # 右
print(l)  # [1, 2, 3, 3, 3, 4, 4.5, 5]
insort_left(l, 3)
print(l)  # [1, 2, 2.5, 3, 3, 3, 4, 4.5, 5]
insort_left(l, 5.5)
print(l)  # [1, 2, 2.5, 3, 3, 3, 4, 4.5, 5]
