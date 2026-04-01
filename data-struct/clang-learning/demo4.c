//  练习4：指针实现两个整数交换
//  需求
// 1. 用指针传参编写交换函数 `void swap(int *a, int *b)`
// 2. 主函数定义两个变量，调用函数交换值
// 3. 输出结果
// 考点
// 取地址`&`、解引用`*`、地址传递（TS无此语法，核心难点）

#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a = 1;
  int b = 2;
  printf("before a: %d, b: %d\n", a, b);
  swap(&a, &b);
  printf("after a: %d, b: %d\n", a, b);
  return 0;
}
