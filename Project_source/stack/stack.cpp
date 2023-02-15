//
// Created by jc on 2022/12/3.
//

#include<iostream>
#include "stack.h"


using namespace std;



// 栈stack的顺序储存结构实现

//typedef struct SNode* Stack;
//typedef int ElementType;
//// struct SNode
//// {
////     int *Data; // 存储元素的数组
////     int MaxSize; // 最大容量
////     int Top; // 栈顶指针
//// };
//
//struct SNode
//{
//    ElementType Data[MaxSize]; // 一个个元素就存在这个数组里面
//    int top;
//};

Stack Ptrstack;

// 新建栈空间
// 返回栈储存数据的数组的指针

Stack StackSeq::CreateStack(){
    Ptrstack = (Stack)malloc(sizeof(struct SNode)); // 动态申请内存空间
    std::cout <<"the size of stack : "<< (sizeof(struct SNode)) << " byte" << std::endl;
    //  字节数 = MaxSize * sizeof(ElementType) + sizeof(int);
    Ptrstack->top = -1; // 空栈，栈顶指针赋值为-1
    return Ptrstack; // 返回指向这个栈存储结构的指针

}


// 入栈
// 参数： Ptrstack 栈地址， item 入栈元素
void StackSeq::Push(Stack Ptrstack, ElementType item){
    if (Ptrstack->top ==MaxSize-1)
    {
        std::cout << " stack id full" << std::endl;
    }
    else{
        Ptrstack->Data[++(Ptrstack->top)] = item;
        return;
    }


}


// 出栈
// 返回当前栈顶位置的元素

ElementType StackSeq::Pop(Stack Ptrstack){
    if (Ptrstack->top == -1)
    {
        std::cout << "stack is empty " << std::endl;
        return -1;
    }
    else{
        return Ptrstack->Data[(Ptrstack->top)--];
    }
}


// 栈满判断

bool StackSeq::isFull(Stack Ptrstack){
    if (Ptrstack->top == MaxSize -1)
    {
        return true;
    }
    else{
        return false;
    }
}

// 栈空判断
bool StackSeq::isEmpty(Stack Ptrstack){
    if (Ptrstack->top == -1)
    {
        return true;
    }
    else{
        return false;
    }
}

// 输出栈中所有元素

void StackSeq::PrintStack(Stack Ptrstack){
    if (isEmpty(Ptrstack))
    {
        std::cout << "stack is empty error " << std::endl;
        return ;
    }

    int temp = Ptrstack->top;
    while (temp != -1)
    {
        std::cout << Ptrstack->Data[temp] << std::endl;
        temp--;
    }

    std::cout << "print end " <<std::endl;

}

void  StackSeq::StackTest(){

    Ptrstack = CreateStack();
    std::cout << isEmpty(Ptrstack) << std::endl;
    Pop(Ptrstack);
    Push(Ptrstack,5);
    PrintStack(Ptrstack);
    std::cout << isFull(Ptrstack) << std::endl;
    Pop(Ptrstack);


}

