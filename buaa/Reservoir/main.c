#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 200   // 定义最大矩阵大小为200
#define INF 20001  // 定义一个很大的数值用于初始化

// 定义一个结构体用于表示单元格的信息
typedef struct {
    int x, y, height;  // x和y表示单元格的位置，height表示单元格的高度
} Cell;

// 定义一个最小堆的结构体
typedef struct {
    Cell* data;    // 存储堆中元素的数组
    int size;      // 堆中当前元素的数量
    int capacity;  // 堆的容量
} MinHeap;

// 创建一个最小堆
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));    // 分配堆的内存
    heap->data = (Cell*)malloc(capacity * sizeof(Cell));  // 分配存储单元格的数组内存
    heap->size = 0;                                       // 初始化堆的大小为0
    heap->capacity = capacity;                            // 设置堆的容量
    return heap;
}

// 交换两个单元格
void swap(Cell* a, Cell* b) {
    Cell temp = *a;
    *a = *b;
    *b = temp;
}

// 向上调整堆
void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;  // 计算父节点的索引
        if (heap->data[parent].height <= heap->data[idx].height)
            break;                                    // 父节点小于当前节点，结束调整
        swap(&heap->data[parent], &heap->data[idx]);  // 交换父节点和当前节点
        idx = parent;                                 // 更新当前节点的索引为父节点的索引
    }
}

// 向下调整堆
void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;       // 初始化最小值索引为当前节点
    int left = 2 * idx + 1;   // 计算左子节点索引
    int right = 2 * idx + 2;  // 计算右子节点索引
    if (left < heap->size && heap->data[left].height < heap->data[smallest].height) {
        smallest = left;  // 如果左子节点更小，更新最小值索引
    }
    if (right < heap->size && heap->data[right].height < heap->data[smallest].height) {
        smallest = right;  // 如果右子节点更小，更新最小值索引
    }
    if (smallest != idx) {
        swap(&heap->data[smallest], &heap->data[idx]);  // 如果最小值索引不是当前节点，交换
        heapifyDown(heap, smallest);                    // 继续向下调整
    }
}

// 向堆中插入一个元素
void insertHeap(MinHeap* heap, Cell cell) {
    heap->data[heap->size++] = cell;  // 在堆的末尾插入新元素
    heapifyUp(heap, heap->size - 1);  // 向上调整堆
}

// 从堆中取出最小元素
Cell extractMin(MinHeap* heap) {
    Cell minCell = heap->data[0];              // 取出堆顶元素
    heap->data[0] = heap->data[--heap->size];  // 将最后一个元素移到堆顶
    heapifyDown(heap, 0);                      // 向下调整堆
    return minCell;
}

// 计算蓄水池中可以储存的水量
int trapRainWater(int n, int m, int heights[MAXN][MAXN]) {
    if (n < 3 || m < 3)
        return 0;  // 如果矩阵行数或列数小于3，不能存水

    bool visited[MAXN][MAXN] = {false};                         // 初始化访问标记数组
    MinHeap* heap = createHeap(n * m);                          // 创建一个最小堆
    int water = 0;                                              // 初始化储水量为0
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 定义四个方向

    // 将边界上的单元格插入堆中
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                insertHeap(heap, (Cell){i, j, heights[i][j]});  // 插入边界单元格
                visited[i][j] = true;                           // 标记为已访问
            }
        }
    }

    // 从堆中取出最小元素，并检查其四周的单元格
    while (heap->size > 0) {
        Cell cell = extractMin(heap);  // 取出最小元素
        for (int k = 0; k < 4; ++k) {
            int x = cell.x + directions[k][0];                                               // 计算新位置的x坐标
            int y = cell.y + directions[k][1];                                               // 计算新位置的y坐标
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {                      // 如果新位置合法且未访问
                visited[x][y] = true;                                                        // 标记为已访问
                water += (cell.height > heights[x][y]) ? (cell.height - heights[x][y]) : 0;  // 计算储水量
                // 计算最高的屏障
                insertHeap(heap, (Cell){x, y, (cell.height > heights[x][y]) ? cell.height : heights[x][y]});  // 插入新的单元格
            }
        }
    }

    free(heap->data);  // 释放堆内存
    free(heap);        // 释放堆结构体
    return water;      // 返回储水量
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  // 读取矩阵的行数和列数
    int heights[MAXN][MAXN];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &heights[i][j]);  // 读取每个单元格的高度
        }
    }
    int result = trapRainWater(n, m, heights);  // 计算储水量
    printf("%d\n", result);                     // 输出结果
    return 0;
}
