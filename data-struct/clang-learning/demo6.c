// ## 练习6：指针操作数组

// ### 需求

// 1. 定义数组`int arr[] = {10,20,30}`
// 2. 定义指针指向数组首地址
// 3. 用指针遍历数组，修改所有元素为原来的2倍

// ### 考点

// 指针与数组的关系、指针遍历

#include <stdio.h>

int main(void) {
  int arr[] = {10, 20, 30};

  printf("修改前: ");
  for (int i = 0; i < 3; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int *p = arr; // 定义指针，指向数组首地址（等价于 &arr[0]）
  for (int i = 0; i < 3; i++) {
    *(p + i) = *(p + i) * 2; // 等价于 arr[i] = arr[i] * 2
  }

  printf("修改后: ");
  for (int i = 0; i < 3; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
