// 练习1：一维数组遍历求和
// 需求
// 1. 定义一个长度为5的整型数组，手动赋值 {1,2,3,4,5}
// 2. 用 for 循环遍历数组，计算所有元素的和
// 3. 用 printf 输出结果
// 考点
// 数组、循环、输出、基础运算

#include <stdio.h>

#define length 5

int main(void) {
  int arr[length] = {1, 2, 3, 4, 5};
  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }

  printf("sum: %d\n", sum);
  return 0;
}
