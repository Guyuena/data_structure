//
// Created by jc on 2022/12/3.
//
//使用单链表来实现栈 stack
// 链式储存结构实际上就是一个单链表； 插入和删除操作只能在链表的栈顶进行，
// 栈顶指针Top应该在链表的头

//
// Created by jc on 2022/12/3.
//

#include<iostream>
#include "stackLink.h"


using namespace std;



// 栈stack的链表储存结构实现




//// 新建栈空间
// 返回栈储存数据的数组的指针

StackL StackLink::CreateStack(){
    StackL stack;
    stack = (StackL)malloc(sizeof(struct SLink)); // 动态申请内存空间
    std::cout <<"the size of stack : "<< (sizeof(struct SLink)) << " byte" << std::endl;
    //  字节数 = MaxSize * sizeof(ElementType) + sizeof(int);
    stack->next = NULL; // 空栈，栈顶指针赋值为-1
    return stack; // 返回指向这个栈存储结构的指针

}


////入栈
// 参数： stack 当前栈链表， item 入栈元素
void StackLink::Push(StackL stack, ElementType item){

    struct SLink *tmp;
    tmp = (struct SLink*) malloc(sizeof (struct SLink));
    tmp->Data=item;
    tmp->next=stack->next; // 当前链表节点要作为链表的头 Top
    stack->next = tmp;


}


//// 出栈
// 返回当前栈顶位置的元素

ElementType StackLink::Pop(StackL stack){
    struct SLink* firstCell; // 记录需要删除的节点
    ElementType TopData; // 需要返回的变量
    if (!isEmpty(stack)){
        firstCell = stack->next;
        TopData= stack->Data;
        stack->next= firstCell->next;
        free(firstCell); // 释放内存
        return TopData;

    } else{
        std::cout << " stack is empty! " <<std::endl;
        return NULL;
    }
}


//// 栈空判断
bool StackLink::isEmpty(StackL Ptrstack){
    if (Ptrstack->next == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}
//
//// 输出栈中所有元素

void StackLink::PrintStack(StackL stack){
    if (isEmpty(stack))
    {
        std::cout << "stack is empty error " << std::endl;
        return ;
    }

    StackL pri = stack->next;
    while (pri->next != NULL)
    {
        std::cout << pri->Data << std::endl;
        pri = pri->next;
    }

    std::cout << "print end " <<std::endl;

}

void  StackLink::StackTest(){

    StackL  stackL = CreateStack();
    std::cout << isEmpty(stackL) << std::endl;
    Pop(stackL);
    Push(stackL,5);
    PrintStack(stackL);
    Pop(stackL);


}

