
/**
 * 实现一个基本的栈 - 基于链式
 */

#include <stdio.h>
#include <stdlib.h>

// 定义栈节点结构
typedef struct Node
{
  int data;          // 节点数据
  struct Node *next; // 指向下一个节点的指针
} Node;

// 定义栈结构
typedef struct
{
  Node *top; // 指向栈顶节点的指针
  int size;  // 栈的大小
} Stack;

void InitStack(Stack *stack)
{
  stack->top = NULL;
  stack->size = 0;
}

void DestroyStack(Stack *stack)
{
  Node *current = stack->top;
  Node *next;
  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  stack->top = NULL;
  stack->size = 0;
}

void push(Stack *stack, int data)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return;
  }
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

int pop(Stack *stack, int *data)
{
  if (stack->top == NULL)
  {
    fprintf(stderr, "Stack is empty\n");
    return 0; // 栈为空
  }

  Node *temp = stack->top;
  *data = temp->data;
  stack->top = temp->next;
  free(temp);
  stack->size--;
  return 1; // 弹出成功
}

int GetTop(Stack *stack, int *data)
{
  if (stack->top == NULL)
  {
    fprintf(stderr, "Stack is empty\n");
    return 0; // 栈为空
  }

  *data = stack->top->data;
  return 1; // 获取成功
}

int StackEmpty(Stack *stack)
{
  return stack->top == NULL;
}

int main()
{
  Stack myStack;
  InitStack(&myStack);

  // 入栈操作
  push(&myStack, 10);
  push(&myStack, 20);
  push(&myStack, 30);

  // 获取栈顶元素
  int topData;
  if (GetTop(&myStack, &topData))
  {
    printf("Top element: %d\n", topData);
  }

  // 出栈操作
  int poppedData;
  if (pop(&myStack, &poppedData))
  {
    printf("Popped element: %d\n", poppedData);
  }

  // 再次获取栈顶元素
  if (GetTop(&myStack, &topData))
  {
    printf("Top element: %d\n", topData);
  }

  // 判断栈是否为空
  if (StackEmpty(&myStack))
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Stack is not empty\n");
  }

  // 销毁栈
  DestroyStack(&myStack);

  return 0;
}