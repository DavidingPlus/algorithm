/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

const int N = 1e5 + 10;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 先对宽度进行排序，按照从小到大的顺序，然后这样宽度这边就ok了，然后高度这边就查找最长递增子序列(不一定连续)即可，和上一个题一样的思路
        // 但是这样会遇到一个问题，就是宽度相同高度应该怎么处理；从最直观的思路来讲，无非就是递增和递减，如果是递增的话，那么高度递增，如果高度低的选中了，那么更高的高度是一定可以选中的，意思是宽度相同的被选进来了，这显然是不符合条件的，所以这样一分析发现最好是递减；并且由于相同宽度只能选中一个，所以高度递减的话能保证前面选中了后面的就一定不会被选中，这样才能保证是这个问题的解

        // 排序
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& elem1, const vector<int>& elem2) {
            if (elem1[0] != elem2[0])
                return elem1[0] < elem2[0];
            else
                return elem1[1] > elem2[1];
        });

        // 求关于高度的最长递增子序列
        int dp[N] = {0};
        dp[0] = 1;

        int res = 1;

        for (int i = 1; i < envelopes.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);

            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end
