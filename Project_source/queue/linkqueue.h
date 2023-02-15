//
// Created by jc on 2022/12/4.
//

#ifndef PROJECT_SOURCE_LINKQUEUE_H
#define PROJECT_SOURCE_LINKQUEUE_H

typedef int ElementType;   //ElemType 根据实际情况而定，这里假定为int型

//struct LinkNode{         //结点结构
//    ElementType data;
//    struct LinkNode *next;
//};
//
//struct LinkQueue {       //队列的链式结构
//    LinkNode *Front;
//    LinkNode *Rear;      //对头,对尾指针
//};
//
//
//namespace linkQueue{
//    void CreateQueue(LinkQueue *Q);
//    bool IsEmpty(LinkQueue *Q);
//    void InsertQue(LinkQueue *Q,ElementType X);
//    ElementType DeleteQue(LinkQueue *Q);
//    void linkQueueTest();
//}


typedef struct Qnode{
    int data;
    struct Qnode *next;
}Qnode;

typedef struct LQueue{
    Qnode *front;
    Qnode *rear;
}LQueue;

namespace linkQueue{
    void initQueue(LQueue *q);
    int empty(LQueue *t);
    void push(LQueue *t, int x);
    void pop(LQueue *t);
    int getFront(LQueue *t);
    int getRear(LQueue *t);
    int getSize(LQueue *t);
    void printQueue(LQueue *t);
    void linkQueueTest();
}


#endif //PROJECT_SOURCE_LINKQUEUE_H
