#include <iostream>
using ll = long long;

ll quickPower(ll a, ll b, ll mod)
{
    ll res = 1, base = a;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ll MOD = 2146516019;
    ll ans = 0;

    for (ll i = 1; i <= 233333333; ++i)
    {
        ans ^= quickPower(i, MOD - 2, MOD);
    }

    std::cout << ans << '\n';
    // std::cout << 1307261675 << '\n';

    return 0;
}
