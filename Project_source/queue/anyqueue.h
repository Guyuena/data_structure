//
// Created by jc on 2022/12/4.
//

#ifndef PROJECT_SOURCE_ANYQUEUE_H
#define PROJECT_SOURCE_ANYQUEUE_H
typedef int ElementType;
typedef struct QUEUE* Queue;
struct QUEUE
{
    ElementType * pBase;    //用于动态分配内存,pBase保存数组的首地址
    int front;      //指向头结点
    int rear;       //指向最后一个元素的下一结点
} ;

namespace AnyQueue{

    void initQueue(Queue  pQueue);
    Queue CreateQueue(int length);
    void AnyQueueTest();
}

#endif //PROJECT_SOURCE_ANYQUEUE_H
