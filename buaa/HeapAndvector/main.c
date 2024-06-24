// ac 用数组模拟堆

#include <stdbool.h>
#include <stdio.h>

bool isMaxHeap(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        if (2 * i < n && nums[i] < nums[2 * i]) {
            return false;
        }
        if (2 * i + 1 < n && nums[i] <= nums[2 * i + 1]) {
            return false;
        }
    }
    return true;
}

bool isMinHeap(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        if (2 * i + 2 < n) {
            if (nums[i] >= nums[2 * i + 2]) {
                return false;
            }
        }
        if (2 * i + 1 < n) {
            if (nums[i] >= nums[2 * i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int len;
        scanf("%d", &len);
        int nums[len];
        for (int i = 0; i < len; i++) {
            scanf("%d", &nums[i]);
        }
        if (isMaxHeap(nums, len)) {
            printf("Max heap\n");
        } else if (isMinHeap(nums, len)) {
            printf("Min heap\n");
        } else {
            printf("Not a heap!\n");
        }
    }
}