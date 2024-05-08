#include <iostream>

int main()
{
    int a = 0, b = 1;
    int ans = 0;
    for (long long i = 1; i <= 2024041331404202; ++i)
    {
        a = (a + i) % 100;
        b = (b * i) % 100;
        if (a == b)
        {
            ans += 1;
        }
    }

    return 0;
}
