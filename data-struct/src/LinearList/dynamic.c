/**
 * @details 实现顺序表 - 动态分配
 * @date 2024-11-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
  int *data;    // 动态分配的存储数据的数组
  int capacity; // 线性表的容量
  int length;   // 当前线性表的长度
} LinearList;

void InitList(LinearList *list, int init_capacity)
{
  list->capacity = init_capacity;
  list->length = 0;
  list->data = (int *)malloc(init_capacity * sizeof(int));
}

void PrintList(LinearList *list)
{
  printf("List: ");
  for (int i = 0; i < list->length; i++)
  {
    printf("%d ", list->data[i]);
  }
  printf("\n");
}

bool ListInsert(LinearList *list, int index, int elem)
{
  if (index < 0 || index > list->length + 1 || index > list->capacity - 1)
    return false;

  for (int i = list->length; i < list->length; i--)
  {
    list->data[i] = list->data[i - 1];
  }
  list->data[index - 1] = elem;
  list->length++;

  return true;
}

int main()
{
  LinearList list;
  InitList(&list, 10);

  for (int i = 0; i < 10; i++)
  {
    ListInsert(&list, i, i * 10);
    PrintList(&list);
  }

  return 0;
}