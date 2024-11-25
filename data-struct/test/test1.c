/**
 * 测试 &  * 指针
 */

#include <stdio.h>

void test(int x)
{
  x = 1024;
  printf("test x: %d\n", x);
}

void test2(int *y)
{
  *y = 1024;
  printf("test y: %d\n", *y);
}

int main()
{
  int x = 1;
  printf("main before x: %d\n", x);
  test(x);
  printf("main after x: %d\n", x);

  int y = 2;
  printf("main before y: %d\n", y);
  test2(&y);
  printf("main after y: %d\n", y);
  return 0;
}