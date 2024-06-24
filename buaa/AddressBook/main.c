#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 21
#define MAX_NUMBER_LEN 21

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 创建一个哈希表
    hcreate(n);
    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LEN];
        char number[MAX_NUMBER_LEN];
        scanf("%s %s", name, number);
        // 创建条目
        ENTRY e;
        e.key = strdup(name);
        e.data = strdup(number);
        // 将条目插入哈希表
        hsearch(e, ENTER);
    }
    // 查询记录
    for (int i = 0; i < m; i++) {
        char query[MAX_NAME_LEN];
        scanf("%s", query);
        // 创建查询条目
        ENTRY e;
        e.key = query;
        // 在哈希表中查询条目
        ENTRY* result = hsearch(e, FIND);
        if (result != NULL) {
            printf("%s\n", (char*)result->data);
        } else {
            printf("Not Found~\n");
        }
    }
    hdestroy();

    return 0;
}
