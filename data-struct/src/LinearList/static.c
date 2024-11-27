/**
 * @details 实现顺序表 - 静态分配
 * @date 2024-11-25
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct
{
  int data[MAX_SIZE];
  int length;
} LinearList;

void InitList(LinearList *L)
{
  L->length = 0;
}

int Length(LinearList L)
{
  return L.length;
}

/**
 * 在线性列表中查找特定元素的位置
 *
 * @param L 待查找的线性列表
 * @param elem 要查找的元素
 * @return 如果找到元素，返回元素在线性列表中的位置（位置从1开始计数）；
 *         如果未找到元素，返回-1
 */
int LocateElem(LinearList L, int elem)
{
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == elem)
      return i + 1;
  }
  return -1;
}

// 按位查找元素
int GetElem(LinearList L, int index)
{
  if (index < 1 || index > L.length) // 无效的位置
    return -1;
  return L.data[index - 1]; // 返回第i个位置的元素值
}

// 判断线性表是否为空
bool Empty(LinearList L)
{
  return L.length == 0;
}

// 销毁线性表
void DestroyList(LinearList *L)
{
  if (L == NULL)
    return;

  memset(L->data, 0, sizeof(L->data)); // 清空数组内容
  L->length = 0;
}

void PrintList(LinearList L)
{
  for (int i = 0; i < L.length; i++)
  {
    printf("%d ", L.data[i]);
  }
  printf("\n");
}

/**
 * 在线性表中指定位置插入一个元素
 *
 * @param L 指向线性表的指针
 * @param index 插入位置的索引，索引从1开始
 * @param elem 要插入的元素
 * @return 如果插入成功，返回true；否则，返回false
 */
bool ListInsert(LinearList *L, int index, int elem)
{
  if (index < 1 || index > L->length + 1 || L->length >= MAX_SIZE) // 无效的位置或表已满
    return false;

  for (int i = L->length; i >= index; i--)
  {
    L->data[i] = L->data[i - 1];
  }

  L->data[index - 1] = elem;
  L->length++;
  return true;
}

/**
 * 删除线性表中的指定元素
 *
 * @param L 指向线性表的指针
 * @param index 要删除的元素的位置
 * @param elem 指向一个整数的指针，用于存储被删除的元素
 * @return 如果删除成功，则返回true，否则返回false
 */
bool ListDelete(LinearList *L, int index, int *elem)
{
  if (index < 1 || index > L->length + 1 || L->length >= MAX_SIZE) // 无效的位置或表已满
    return false;

  *elem = GetElem(*L, index);

  for (int i = index; i < L->length; i++)
  {
    L->data[i - 1] = L->data[i]; // 从左往右移动元素
  }

  L->length--;
  return true;
}

int main()
{
  LinearList L;
  InitList(&L);
  ListInsert(&L, 1, 1);
  ListInsert(&L, 2, 22);
  ListInsert(&L, 3, 333);
  PrintList(L); // 1 22 333

  ListInsert(&L, 4, 55555);
  ListInsert(&L, 4, 4444);
  PrintList(L); // 1 22 333 4444 55555

  printf("Element at position 2: %d\n", GetElem(L, 2));          // Element at position 2: 22
  printf("Position of element 4444: %d\n", LocateElem(L, 4444)); // Position of element 4444: 4

  int deletedValue;
  ListDelete(&L, 4, &deletedValue);
  printf("Deleted value: %d\n", deletedValue); // Deleted value: 4444
  PrintList(L);                                // 1 22 333 55555

  DestroyList(&L);
  printf("Is L empty? %s\n", Empty(L) ? "Yes" : "No");

  return 0;
}