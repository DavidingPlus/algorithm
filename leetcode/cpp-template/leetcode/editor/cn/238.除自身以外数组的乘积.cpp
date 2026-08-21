/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e5 + 10;

class Solution {
public:
    // 这个题不准用除法，那么只能用乘法，加上逆向思维，既然有前缀和自然也有对应的后缀和
    vector<int> productExceptSelf(vector<int>& nums) {
        _init(nums);

        vector<int> answer;
        for (int i = 0; i < nums.size(); ++i)
            answer.push_back(premul[i] * sufmul[i + 2]);

        return answer;
    }

private:
    void _init(vector<int>& nums) {
        // 处理前缀，处理边界
        premul[0] = 1;
        for (int i = 1; i <= nums.size(); ++i)
            premul[i] = premul[i - 1] * nums[i - 1];

        // 处理后缀，处理边界
        sufmul[nums.size() + 1] = 1;
        for (int i = nums.size(); i >= 1; --i)
            sufmul[i] = sufmul[i + 1] * nums[i - 1];
    }

private:
    // 关于c和c++初始化数组的一个坑！
    // 这里注意一个细节，使用初始化的时候，只有初始化为0，写{0}才会把所有的元素全部初始化为0
    // 如果写入的是非0，那么只有第一个数会被初始化为0，其他则为0！
    int premul[N] = {0};  // 定义前缀积
    int sufmul[N] = {0};  // 定义后缀积
};

// @lc code=end
