/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
    int water(int nowHeight, int heightNum)
    {
        return nowHeight < heightNum ? 0 : nowHeight - heightNum;
    }
    int trap(vector<int> &height)
    {
        // 本问题中，柱子之间构成一个个离散的“雨水容器”
        // 如果某两个点的高度大于它们中间全部其他点的高度，它们就构成一组“容器”的边界
        int n = height.size();
        if (n <= 2)
            return 0;
        int result = 0;
        vector<int> maxima;
        // Step1:首先，原本输入的height的信息是需要保留的，但是我们不必完整地复制构造一个新的Vector，
        // 根据上面的分析，边界点的必要条件是“局部最高点”，首先找出这些局部最高点，这样就能缩小研究范围
        if (height[0] > height[1])
        {
            maxima.push_back(0);
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (height[i] >= height[i - 1] && height[i] >= height[i + 1] &&
                (height[i] != height[i - 1] || height[i] != height[i + 1]))
            {
                maxima.push_back(i);
            }
        }
        if (height[n - 1] > height[n - 2])
        {
            maxima.push_back(n - 1);
        }
        // Step2:局部最高点找到以后，只是找到了【有可能】是容器边界的点；
        // 还需要根据“某两个点的高度大于它们中间全部其他点的高度”，排除并非真正是边界的点
        if (maxima.size() > 2)
        {
            int pastsize = maxima.size();
            int nowsize = maxima.size();
            do
            {
                pastsize = maxima.size();
                for (auto it = maxima.begin() + 1; it < maxima.end() - 1; it++)
                {
                    if (height[*it] <= height[*(it - 1)] && height[*it] <= height[*(it + 1)] &&
                        (height[*it] != height[*(it - 1)] || height[*it] != height[*(it + 1)]))
                    {
                        maxima.erase(it);
                    }
                }
                nowsize = maxima.size();
            } while (pastsize != nowsize);
        }
        if (maxima.size() < 2)
            return 0;
        // Step3:所有的雨水容器边界已被找到，可以计算了
        for (int j = 0; j < maxima.size() - 1; j++)
        {
            int leftpos = maxima[j], rightpos = maxima[j + 1];
            // 记录当前雨水容器的高度：两个端点中的较小者
            int nowHeight = min(height[leftpos], height[rightpos]);
            // 计算接水量
            for (int k = leftpos; k < rightpos; k++)
            {
                result += water(nowHeight, height[k]);
            }
        };
        return result;
    }
};

// @lc code=end
