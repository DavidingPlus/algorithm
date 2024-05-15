#include <iostream>

using ll = long long;

int main()
{
    ll n = 1001733993063167141;

    for (ll i = 2; i * i <= n; ++i)
    {
        if ((ll)0 == n % i)
        {
            std::cout << i << '\n'            // 891234941
                      << (ll)(n / i) << '\n'; // 1123984201

            break;
        }
    }

    return 0;
}
