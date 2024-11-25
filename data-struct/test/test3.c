/**
 * 定义一个简单的线性表的实现，
 * 使用静态分配的方式，
 * 有InitList函数。
 */

#include <stdio.h>

#define MAX_SIZE 10 // 定义线性表的最大容量

// 定义线性表的结构体
typedef struct
{
  int data[MAX_SIZE]; // 存储数据的数组
  int length;         // 当前线性表的长度
} List;

void InitList(List *list)
{
  list->length = 0;                  // 初始长度为0
  for (int i = 0; i < MAX_SIZE; i++) // 将每个元素初始化为0
  {
    list->data[i] = 0;
  }
}

int main()
{
  List myList;       // 声明一个顺序表
  InitList(&myList); // 初始化线性表

  for (int i = 0; i < MAX_SIZE; i++)
  {
    printf("myList.data[%d] = %d\n", i, myList.data[i]);
  }

  return 0;
}