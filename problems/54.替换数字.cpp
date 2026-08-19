// https://kamacoder.com/problempage.php?pid=1064

#include <bits/stdc++.h>


// 解法 1：开辟额外空间
// int main()
// {
//     std::string input;
//     std::cin >> input;

//     std::string res;
//     for (auto &c : input) c >= '0' &&c <= '9' ? res += "number" : res += c;

//     std::cout << res << std::endl;


//     return 0;
// }


// 解法 2：在原数组上操作
int main()
{
    std::string s;
    std::cin >> s;

    // 先找出原字符串中数字的个数，将原数组 resize 到相应大小，然后从后往前填充。因为在更替以后，所有的字符的新位置都是在之前的后面的，至少是相等。从后往前填充，当前位置的原始字符，要么刚好自我覆盖，要么早就在之前的从后往前的过程中填充过了，所以不用担心数据丢失的问题。同时右边的快指针最终刚好会和左边的慢指针在起点相遇，不会出现过程中超过而出现问题。

    int count = 0;
    for (auto &c : s)
    {
        if (c >= '0' && c <= '9') ++count;
    }

    int sz = s.size();
    s.resize(sz - count + count * 6);

    int newSz = s.size();
    for (int i = sz - 1, j = newSz - 1; i >= 0; --i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            s[j--] = 'r';
            s[j--] = 'e';
            s[j--] = 'b';
            s[j--] = 'm';
            s[j--] = 'u';
            s[j--] = 'n';
        }
        else
        {
            s[j--] = s[i];
        }
    }

    std::cout << s << std::endl;


    return 0;
}
