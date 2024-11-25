/**
 * 定义一个简单的线性表的实现，
 * 使用动态分配的方式，
 * 有InitList函数。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义线性表的结构体
typedef struct
{
  int *data;    // 动态分配的存储数据的数组
  int capacity; // 线性表的容量
  int length;   // 当前线性表的长度
} List;

// 初始化线性表
void InitList(List *list, int initial_capacity)
{
  list->capacity = initial_capacity;                          // 初始容量
  list->length = 0;                                           // 初始长度为0
  list->data = (int *)malloc(initial_capacity * sizeof(int)); // 动态分配内存
  memset(list->data, 0, initial_capacity * sizeof(int));      // 使用 memset 将整个数组初始化为0
}

// 打印线性表
void PrintList(List *list)
{
  printf("List: ");
  for (int i = 0; i < list->length; i++)
  {
    printf("%d ", list->data[i]);
  }
  printf("\n");
}

// 增加动态数组的长度
void IncreaseCapacity(List *list, int len)
{
  int new_capacity = list->capacity + len;
  int *new_data = (int *)malloc(new_capacity * sizeof(int)); // 分配新的内存

  // 将旧数组中的数据复制到新数组中
  memcpy(new_data, list->data, list->length * sizeof(int));

  free(list->data); // 释放旧数组的内存

  // 更新线性表的容量和数据指针
  list->data = new_data;
  list->capacity = new_capacity;

  // 将新分配的内存初始化为0
  memset(list->data + list->length, 0, (new_capacity - list->length) * sizeof(int));
}

int ListInsert(List *list, int i, int e)
{
  if (i < 1 || i > list->length + 1)
  {
    fprintf(stderr, "Invalid position\n");
    return 0; // 位置无效
  }

  if (list->length >= list->capacity)
  {
    IncreaseCapacity(list, 10); // 增加容量，这里假设每次增加10个单位
  }

  // 将第i个位置及之后的元素向后移动一位
  for (int j = list->length; j >= i; j--)
  {
    list->data[j] = list->data[j - 1];
  }

  // 插入元素
  list->data[i - 1] = e;
  list->length++;

  return 1; // 插入成功
}

int ListDelete(List *list, int i, int *e)
{
  if (i < 1 || i > list->length)
  {
    fprintf(stderr, "Invalid position\n");
    return 0; // 位置无效
  }

  // 获取要删除的元素值
  *e = list->data[i - 1];

  // 将第i个位置之后的元素向前移动一位
  for (int j = i; j < list->length; j++)
  {
    list->data[j - 1] = list->data[j];
  }

  list->length--;

  return 1; // 删除成功
}

int LocateElem(List *list, int e)
{
  for (int i = 0; i < list->length; i++)
  {
    if (list->data[i] == e)
    {
      return i + 1; // 返回元素的位置，从1开始计数
    }
  }

  return -1; // 未找到
}

int main()
{
  List myList;
  InitList(&myList, 10); // 初始化线性表，初始容量为10

  for (int i = 0; i < 10; i++)
  {
    myList.data[i] = i * 10;
    myList.length++;
  }

  PrintList(&myList);
  // List: 0 10 20 30 40 50 60 70 80 90

  IncreaseCapacity(&myList, 5);
  for (int i = 10; i < 15; i++)
  {
    myList.data[i] = i * 10;
    myList.length++;
  }

  PrintList(&myList);
  // List: 0 10 20 30 40 50 60 70 80 90 100 110 120 130 140

  // 插入元素
  ListInsert(&myList, 3, 100);
  PrintList(&myList); // 再次打印线性表

  // 删除元素
  int deletedValue;
  ListDelete(&myList, 3, &deletedValue);
  printf("Deleted value: %d\n", deletedValue);
  PrintList(&myList); // 再次打印线性表

  // 按值查找
  int position = LocateElem(&myList, 30);
  if (position != -1)
  {
    printf("Element 30 found at position: %d\n", position);
  }
  else
  {
    printf("Element 30 not found\n");
  }

  return 0;
}