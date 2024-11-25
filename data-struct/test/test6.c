/**
 * 实现一个基本的栈 - 顺序
 */

#include <stdio.h>
#include <stdlib.h>

// 定义栈结构
typedef struct
{
  int *data;    // 动态分配的存储数据的数组
  int capacity; // 栈的容量
  int top;      // 栈顶指针，-1表示空栈
} Stack;

void InitStack(Stack *stack, int initial_capacity)
{
  stack->capacity = initial_capacity;                          // 初始容量
  stack->top = -1;                                             // 栈顶指针初始化为-1，表示空栈
  stack->data = (int *)malloc(initial_capacity * sizeof(int)); // 动态分配内存
  if (stack->data == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1); // 内存分配失败，退出程序
  }
}

void DestroyStack(Stack *stack)
{
  free(stack->data); // 释放内存
  stack->data = NULL;
  stack->top = -1;
  stack->capacity = 0;
}

int push(Stack *stack, int data)
{
  if (stack->top + 1 == stack->capacity)
  {
    // 栈满，需要扩容
    int new_capacity = stack->capacity * 2;
    int *new_data = (int *)realloc(stack->data, new_capacity * sizeof(int));
    if (new_data == NULL)
    {
      fprintf(stderr, "Memory allocation failed\n");
      return 0; // 内存分配失败
    }
    stack->data = new_data;
    stack->capacity = new_capacity;
  }

  stack->data[++stack->top] = data; // 将元素压入栈顶
  return 1;                         // 入栈成功
}

int pop(Stack *stack, int *data)
{
  if (stack->top == -1)
  {
    fprintf(stderr, "Stack is empty\n");
    return 0; // 栈为空
  }

  *data = stack->data[stack->top--]; // 弹出栈顶元素
  return 1;                          // 弹出成功
}

int GetTop(Stack *stack, int *data)
{
  if (stack->top == -1)
  {
    fprintf(stderr, "Stack is empty\n");
    return 0; // 栈为空
  }

  *data = stack->data[stack->top]; // 获取栈顶元素
  return 1;                        // 获取成功
}

int StackEmpty(Stack *stack)
{
  return stack->top == -1;
}

int main()
{
  Stack myStack;
  InitStack(&myStack, 10); // 初始化栈，初始容量为10

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