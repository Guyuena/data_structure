//
// Created by jc on 2022/12/3.
//

#ifndef PROJECT_SOURCE_STACK_H
#define PROJECT_SOURCE_STACK_H
#define MaxSize 100
typedef struct SNode* Stack;
typedef int ElementType;

// 栈的顺序存储实现


// struct SNode
// {
//     int *Data; // 存储元素的数组
//     int MaxSize; // 最大容量
//     int Top; // 栈顶指针
// };

//顺序储存结构
struct SNode
{
    ElementType Data[MaxSize]; // 一个个元素就存在这个数组里面
    int top;
};




namespace StackSeq{
    Stack CreateStack();
    void Push(Stack Ptrstack, ElementType item);
    ElementType Pop(Stack Ptrstack);
    bool isFull(Stack Ptrstack);
    bool isEmpty(Stack Ptrstack);
    void PrintStack(Stack Ptrstack);
    void  StackTest();
}




#endif //PROJECT_SOURCE_STACK_H
