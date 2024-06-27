#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, h, m;
    scanf("%d %d %d", &n, &h, &m);
    int* std = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        std[i] = h;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        for (int j = a + 1; j < b; j++) {
            std[j] = std[j] - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", std[i]);
    }
    free(std);
    return 0;
}
