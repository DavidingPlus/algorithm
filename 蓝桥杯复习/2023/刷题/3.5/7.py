#等差数列
#思路：将数组排序，排序之后根据等差数列的项数公式计算出公差的大致上限
#然后根据公差的上限往下遍历，判断是不是合适的公差即可，直到1
n = int(input())
num_list = list(map(int, input().split(' ')))

#考虑两个问题：
# 1.len(num_list)-1有可能为0 需要单独考虑
# 2.不能去重 比如1 1 1 他是一个公差为0的等差数列

#测试用例
# 5
# 2 6 4 10 20

# 3
# 1 1 1

#注意长度为1的情况
if len(num_list) == 1:
    print(1)

else:
    # 计算项数上限(包含)
    num_list.sort(reverse=False)
    count_max = (num_list[-1] - num_list[0]) // (len(num_list) - 1)

    #如果conut_max为0 表明该数组所有项都相同，这时即为长度
    if count_max == 0:
        print(len(num_list))
    else:
        #从上开始遍历
        while count_max > 0:
            flag = False
            #由于是等差数列 那么后续的项必然可以通过第一项计算得到
            for i in range(1, len(num_list)):
                if (num_list[i] - num_list[0]) % count_max != 0:
                    #不等于0表示不是正确的公差
                    flag = True
                    break
            if flag == False:
                #表示是正确的公差 可以计算项数
                num = (num_list[-1] - num_list[0]) / count_max + 1
                print(int(num))
                break

            count_max -= 1
