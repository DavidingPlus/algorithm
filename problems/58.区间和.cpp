// https://kamacoder.com/problempage.php?pid=1070

#include <bits/stdc++.h>


int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i) std::cin >> vec[i];

    // 前缀和模板题
    std::vector<int> preSum(1 + n);
    preSum[0] = 0;

    for (int i = 0; i < n; ++i) preSum[1 + i] = preSum[i] + vec[i];

    int a = 0, b = 0; // 注意前缀和的下标比数组的下标要大 1
    while (std::cin >> a >> b) std::cout << preSum[1 + b] - preSum[a] << std::endl;


    return 0;
}
