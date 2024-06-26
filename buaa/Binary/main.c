#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long binaryToInt(const char* binary) {
    long long num = 0;
    while (*binary) {
        num = (num << 1) + (*binary - '0');
        binary++;
    }
    return num;
}

void intToBinary(long long num, char* binary) {
    if (num == 0) {
        strcpy(binary, "0");
        return;
    }
    char tmp[65];
    int i = 0;
    while (num) {
        // 注意这里ASCII码是+'0'
        tmp[i++] = (num % 2) + '0';
        num /= 2;
    }
    // 翻转字符串
    for (int j = 0; j < i; j++) {
        binary[j] = tmp[i - j - 1];
    }
    binary[i] = '\0';
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char binary[50005];
    char operations[50005];
    scanf("%s", binary);
    scanf("%s", operations);
    long long num = binaryToInt(binary);
    for (int i = 0; i < m; i++) {
        switch (operations[i]) {
            case '+':
                num += 1;
                break;
            case '-':
                num -= 1;
                break;
            case '*':
                num *= 2;
                break;
            case '/':
                num /= 2;
                break;
        }
    }
    char result[50005];
    intToBinary(num, result);
    printf("%s\n", result);
}