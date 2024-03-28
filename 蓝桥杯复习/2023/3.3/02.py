# 小蓝给学生们组织了一场考试，卷面总分为 100 分，每个学生的得分都是一个 0 到 100 的整数。
# 如果得分至少是 60 分，则称为及格。如果得分至少为 85 分，则称为优秀。
# 请计算及格率和优秀率，用百分数表示，百分号前的部分四舍五入保留整数。
num = int(input())
scores = list()
for i in range(num):
    score = int(input())
    scores.append(score)

pass_num = 0
good_num = 0
for each in scores:
    if each >= 60:
        pass_num += 1
    if each >= 85:
        good_num += 1

pass_rate = pass_num / num
good_rate = good_num / num


#将其处理成为百分数 注意四舍五入的问题
def get_rate(rate: int):
    rate2 = int(rate * 1000)
    if rate2 - 10 * int(rate * 100) >= 5:  # 进位
        rate2 = int(rate * 100) + 1
    else:
        rate2 = int(rate * 100)
    final_rate = str(rate2) + '%'
    return final_rate


final_pass_rate = get_rate(pass_rate)
final_good_rate = get_rate(good_rate)

print(final_pass_rate)
print(final_good_rate)
