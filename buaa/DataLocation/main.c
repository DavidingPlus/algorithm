#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // 读取缓冲区的\n

    int nums[n];
    hcreate(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        ENTRY e;
        ENTRY* ep;
        char* key = malloc(20 * sizeof(char));
        sprintf(key, "%d", nums[i]);
        e.key = key;
        e.data = malloc(sizeof(int));
        *(int*)e.data = i + 1;

        ep = hsearch(e, ENTER);
        if (ep == NULL) {
            fprintf(stderr, "Entry failed");
            exit(1);
        }
    }

    getchar();

    // 如何接受多个输入
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    char* token = strtok(input, " \n\t");
    while (token != NULL) {
        int t = atoi(token);
        ENTRY e;
        ENTRY* ep;
        char key[20];
        sprintf(key, "%d", t);
        e.key = key;

        ep = hsearch(e, FIND);
        if (ep != NULL) {
            printf("%d\n", *(int*)ep->data);
        } else {
            printf("NO\n");
        }
        token = strtok(NULL, " \n\t");
    }
    hdestroy();
    return 0;
}
