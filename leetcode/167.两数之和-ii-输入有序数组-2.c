/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <malloc.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *res = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i <= numbersSize; i++)
    {
        for (int j = 1 + i; j <= numbersSize; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                res[0] = 1 + i;
                res[1] = 1 + j;
                return res;
            }
        }
    }
    res[0] = -1;
    res[1] = -1;
    return res;
}

// @lc code=end
