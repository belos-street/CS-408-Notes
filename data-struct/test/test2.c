/**
 * 定义一个简单的线性表的实现，包括插入、删除、查找等操作。
 */

#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
  int data[MAX_SIZE];
  int length;
} List;

void InitList(List *L)
{
  L->length = 0;
}

int Length(List L)
{
  return L.length;
}

int LocateElem(List L, int e)
{
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == e)
    {
      return i + 1; // 返回元素的位置，从1开始计数
    }
  }
  return -1; // 如果未找到，返回-1
}

int GetElem(List L, int i)
{
  if (i < 1 || i > L.length)
  {
    return -1; // 无效的位置
  }
  return L.data[i - 1]; // 返回第i个位置的元素值
}

int ListInsert(List *L, int i, int e)
{
  if (i < 1 || i > L->length + 1 || L->length >= MAX_SIZE)
  {
    return 0; // 无效的位置或表已满
  }
  for (int j = L->length; j >= i; j--)
  {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
  return 1; // 插入成功
}

int ListDelete(List *L, int i, int *e)
{
  if (i < 1 || i > L->length)
  {
    return 0; // 无效的位置
  }
  *e = L->data[i - 1];
  for (int j = i; j < L->length; j++)
  {
    L->data[j - 1] = L->data[j];
  }
  L->length--;
  return 1; // 删除成功
}

void PrintList(List L)
{
  for (int i = 0; i < L.length; i++)
  {
    printf("%d ", L.data[i]);
  }
  printf("\n");
}

int Empty(List L)
{
  return L.length == 0;
}

void DestroyList(List *L)
{
  L->length = 0; // 将表的长度设置为0，表示销毁
}

int main()
{
  List L;
  InitList(&L);

  ListInsert(&L, 1, 10);
  ListInsert(&L, 2, 20);
  ListInsert(&L, 3, 30);

  printf("Length of L: %d\n", Length(L));
  printf("Element at position 2: %d\n", GetElem(L, 2));
  printf("Position of element 20: %d\n", LocateElem(L, 20));

  int deletedValue;
  ListDelete(&L, 2, &deletedValue);
  printf("Deleted value: %d\n", deletedValue);

  PrintList(L);

  DestroyList(&L);
  printf("Is L empty? %s\n", Empty(L) ? "Yes" : "No");

  return 0;
}