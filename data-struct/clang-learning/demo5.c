// ## 练习5：结构体存储学生信息

// ### 需求

// 1. 定义结构体`Student`，包含：学号(`int`)、姓名(`char[10]`)、分数(`int`)
// 2. 定义结构体变量，赋值并打印所有信息

// ### 考点

// 结构体定义、成员访问（`.`）

#include <stdio.h>
typedef struct {
  int id;
  char name[10];
  int score;
} Student;

int main(void) {
  Student stu = {1001, "张三", 90};
  printf("id: %d, name: %s, score: %d\n", stu.id, stu.name, stu.score);
  return 0;
}
