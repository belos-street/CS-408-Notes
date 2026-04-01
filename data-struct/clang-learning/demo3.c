// 练习3：函数值传递测试
// 需求
// 1. 定义函数 void change(int x)，函数内把x赋值为100
// 2. main函数中定义变量a=10，调用change(a)
// 3. 输出调用后的a，观察值是否改变
// 考点： C语言值传递特性（考研易错点） 同js的值传递
#include <stdio.h>

void change(int x) { x = 100; }

int main(void) {
  int x = 10;
  printf("x before: %d\n", x); // 输出 10
  change(x);                   // 传递的是 x 的值，而不是地址
  printf("x after: %d\n", x);  // 输出 10
  return 0;
}