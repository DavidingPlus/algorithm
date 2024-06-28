#include <stdio.h>
int n;
int findValue(int matrix[][2 * n + 1], int row, int col) {
    int a = matrix[row][col - 1];
    int b = matrix[row][col];
    int c = matrix[row][col + 1];
    // a是中间值的情况
    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        return a;
    }
    // b是中间值的情况
    else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        return b;
    }
    // c是中间值的情况
    else {
        return c;
    }
}

int main() {
    scanf("%d", &n);
    int matrix[n][2 * n + 1];
    for (int j = 0; j < 2 * n - 1; j++) {
        scanf("%d", &matrix[n - 1][j]);
    }
    int t = n - 2;
    int begin = 1;
    while (t >= 0) {
        for (int i = begin; i < begin + 2 * (t + 1) - 1; i++) {
            matrix[t][i] = findValue(matrix, t + 1, i);
        }
        begin++;
        t--;
    }
    printf("%d\n", matrix[0][n - 1]);
}