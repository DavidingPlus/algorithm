#include <stdio.h>
#include <stdlib.h>
const int MOD = 1e9;

int main() {
    int n;
    scanf("%d", &n);
    int dp[n + 1];
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    // 底
    for (int i = 1; i <= n; i <<= 1) {
        // 增量
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    printf("%d\n", dp[n]);
}