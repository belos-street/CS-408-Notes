// ## 练习7：动态内存分配（创建整型数组）

// ### 需求

// 1. 用`malloc`申请5个int大小的动态数组
// 2. 赋值、遍历、输出
// 3. 用`free`释放内存

// ### 考点

// `malloc`、`free`、动态内存

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = (int *)malloc(5 * sizeof(int));

  // 建议加空指针检查
  if (p == NULL) {
    return -1;
  }

  for (int i = 0; i < 5; i++) {
    *(p + i) = i * 10;
  }

  for (int i = 0; i < 5; i++) {
    printf("%d ", *(p + i));
  }

  free(p);
  p = NULL; // 建议释放后置空，避免悬空指针
}
