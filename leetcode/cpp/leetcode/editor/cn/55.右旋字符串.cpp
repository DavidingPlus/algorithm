// https://kamacoder.com/problempage.php?pid=1065

#include <bits/stdc++.h>


void swapStr(std::string &s, int left, int right)
{
    for (; left <= right; ++left, --right) std::swap(s[left], s[right]);
}


int main()
{
    // 本题目在原串上原地操作
    // abcdefg -> fgabcde（在 e f 之间分界）
    // 过程可模拟为：先整个字符串翻转 gfedcba，现在的分界线在 f e 之间。然后两边各自翻转即可。

    std::string s;
    int pos;

    std::cin >> pos >> s;

    swapStr(s, 0, s.size() - 1);
    swapStr(s, 0, pos - 1);
    swapStr(s, pos, s.size() - 1);

    std::cout << s << std::endl;


    return 0;
}
