//
// Created by jc on 2022/12/3.
//

#ifndef PROJECT_SOURCE_STACKLINK_H
#define PROJECT_SOURCE_STACKLINK_H

//
// Created by jc on 2022/12/3.
//


typedef struct SLink* StackL;
typedef int ElementType;




//链表储存结构
struct SLink
{
    ElementType Data; // 一个个元素就存在这个数组里面
    struct SLink* next;
};





namespace StackLink{
    StackL CreateStack();
    void Push(StackL stack, ElementType item);
    ElementType Pop(StackL stack);
    bool isEmpty(StackL stack);
    void PrintStack(StackL stack);
    void  StackTest();
}





#endif //PROJECT_SOURCE_STACKLINK_H
