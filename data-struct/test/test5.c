/**
 * 实现单链表
 */

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node
{
  int data;          // 节点数据
  struct Node *next; // 指向下一个节点的指针
} Node;

// 定义链表结构
typedef struct
{
  Node *head; // 指向链表头节点的指针
  int length; // 链表的长度
} LinkedList;

void InitLinkedList(LinkedList *list)
{
  list->head = NULL;
  list->length = 0;
}

int InsertNode(LinkedList *list, int index, int data)
{
  if (index < 0 || index > list->length)
  {
    fprintf(stderr, "Invalid position\n");
    return 0; // 位置无效
  }

  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return 0; // 内存分配失败
  }
  new_node->data = data;
  new_node->next = NULL;

  if (index == 0)
  {
    // 插入到链表头部
    new_node->next = list->head;
    list->head = new_node;
  }
  else
  {
    // 插入到中间或尾部
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
    {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }

  list->length++;
  return 1; // 插入成功
}

int DeleteNode(LinkedList *list, int index, int *data)
{
  if (index < 0 || index >= list->length)
  {
    fprintf(stderr, "Invalid position\n");
    return 0; // 位置无效
  }

  Node *to_delete;
  if (index == 0)
  {
    // 删除链表头部节点
    to_delete = list->head;
    list->head = list->head->next;
  }
  else
  {
    // 删除中间或尾部节点
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
    {
      current = current->next;
    }
    to_delete = current->next;
    current->next = to_delete->next;
  }

  *data = to_delete->data;
  free(to_delete);
  list->length--;
  return 1; // 删除成功
}

int FindNode(LinkedList *list, int data)
{
  Node *current = list->head;
  for (int i = 0; i < list->length; i++)
  {
    if (current->data == data)
    {
      return i; // 返回节点的位置
    }
    current = current->next;
  }
  return -1; // 未找到
}

void PrintLinkedList(LinkedList *list)
{
  Node *current = list->head;
  printf("LinkedList: ");
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main()
{
  LinkedList myList;
  InitLinkedList(&myList);

  // 插入节点
  InsertNode(&myList, 0, 10);
  InsertNode(&myList, 1, 20);
  InsertNode(&myList, 2, 30);
  InsertNode(&myList, 1, 15);

  PrintLinkedList(&myList); // 打印链表

  // 删除节点
  int deletedData;
  DeleteNode(&myList, 2, &deletedData);
  printf("Deleted data: %d\n", deletedData);
  PrintLinkedList(&myList); // 再次打印链表

  // 查找节点
  int position = FindNode(&myList, 15);
  if (position != -1)
  {
    printf("Element 15 found at position: %d\n", position);
  }
  else
  {
    printf("Element 15 not found\n");
  }

  return 0;
}