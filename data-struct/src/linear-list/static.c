/**
 * 静态线性表的实现
 *
 * @date 2024-11-25
 */

#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 100
typedef int ElementType;

typedef struct {
  ElementType data[MAX_SIZE];
  int length;
} StaticLinearList;

/**
 * InitList - 初始化线性表为空表
 * Length - 获取线性表的长度
 * LocateElem - 查找线性表中指定元素的位置
 * GetElem - 获取线性表中指定位置的元素值
 * ListInsert - 在线性表中指定位置插入一个元素
 * ListDelete - 删除线性表中的指定元素
 * PrintList - 打印线性表中的所有元素
 * Empty - 判断线性表是否为空
 * DestroyList - 销毁线性表
 */

void InitList(StaticLinearList *L) { L->length = 0; }

int Length(StaticLinearList L) { return L.length; }

bool ListInsert(StaticLinearList *L, int index, int elem) {
  if (index < 1 || index > L->length + 1 || L->length >= MAX_SIZE)
    return false;

  // 在第 index 个位置插入新元素时，将 index 及其之后的元素向后移动一个位置
  for (int i = L->length; i >= index; i--) {
    L->data[i] = L->data[i - 1];
  }

  L->data[index - 1] = elem;
  L->length++;
  return true;
}

bool Empty(StaticLinearList L) { return L.length == 0; }

int main(void) {
  StaticLinearList L;
  InitList(&L);

  ListInsert(&L, 1, 100);
  ListInsert(&L, 2, 200);
  ListInsert(&L, 3, 300);
  printf("L length: %d\n", Length(L));
}
