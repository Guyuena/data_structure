//
// Created by jc on 2022/12/3.
//

#ifndef PROJECT_SOURCE_QUEUE_H
#define PROJECT_SOURCE_QUEUE_H

// 队列， 先进先出 FIFO
// 头front  尾rear

// 顺序储存实现队列，数组

#define Maxize 100
typedef int ElementType ;
//struct SqQueue{
//    ElementType Data[Maxize];
//    int rear;  // 尾
//    int front; //头
//};
struct SqQueue{
    ElementType Data[Maxize];
    int rear;  // 尾
    int front; //头
};
typedef struct SqQueue * queue;


typedef struct MyQueue * myqueue;
struct MyQueue
{
    int * pBase;    //用于动态分配内存,pBase保存数组的首地址
    int front;      //指向头结点
    int rear;       //指向最后一个元素的下一结点
};





namespace diyQueue{
    void initqueue(SqQueue &Q);
    bool isEmpty(SqQueue  Q);
    void addqueue(SqQueue &Q,ElementType item);
    ElementType deletequeue(SqQueue &Q);
    SqQueue createQueue();


}

namespace diyQueue2{
    void initQueue(myqueue pQueue,int length);
    void diyQueue2Test();
}




#endif //PROJECT_SOURCE_QUEUE_H
