#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int LEN = 30;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    bool edge[n + 1][n + 1];
    memset(edge, false, sizeof(edge));

    char* token;
    for (int i = 0; i < m; i++) {
        char input[LEN];
        fgets(input, LEN, stdin);

        token = strtok(input, " \n\t");
        int op = atoi(token);
        int a[2];
        for (int j = 0; j < 2; j++) {
            // 从上一位置继续分割同一字符串
            token = strtok(NULL, " \n\t");
            int t = atoi(token);
            a[j] = t;
        }
        if (op == 1) {
            // 插入
            edge[a[1]][a[0]] = true;
            edge[a[0]][a[1]] = true;
        } else {
            if (edge[a[1]][a[0]]) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}