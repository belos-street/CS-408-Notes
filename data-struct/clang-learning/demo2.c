// 练习2：查找数组中的最大值
// 需求
// 1. 定义任意整型数组（长度自定）
// 2. 编写函数 int getMax(int arr[], int n)，返回数组最大值
// 3. 在main函数中调用并输出结果
// 考点
// 函数定义、数组传参、条件判断

#include <stdio.h>

int getMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) { // 循环可以从 i=1 开始，少循环 1 次
    int current = arr[i];
    (current > max) && (max = current);
  }
  return max;
}

int main(void) {
  int arr[5] = {1, 2, 99, 4, 5};
  int max = getMax(arr, 5);
  printf("max: %d\n", max);
  return 0;
}
