//
// Created by jc on 2022/12/3.
//

#include "iostream"
#include "queue.h"



SqQueue diyQueue::createQueue(){
    SqQueue Q;
    return Q;

}

void diyQueue::initqueue(SqQueue &Q) {
    Q.rear=0;
    Q.front=0;

}

bool diyQueue::isEmpty(SqQueue  Q){
    if(Q.front == 0 && Q.rear == 0){
        std::cout << "Queue is empty " <<std::endl;
        return true;
    }else{
        return false;
    }
}

void diyQueue::addqueue(SqQueue &Q,ElementType item){
    if (Q.rear == Maxize-1){
        std::cout << "Queue is full " <<std::endl;
    }
}

ElementType diyQueue::deletequeue(SqQueue &Q){
    if(isEmpty(Q)){ //判断队列是否为空
        return 0;
    }
    int x = Q.Data[Q.front++]; //要出队的元素     //出队，长度-1
    return x;
}

void diyQueue2::initQueue(myqueue pQueue,int length)
{
//    std::cout << "sizeof(pQueue)" << std::endl;
    //分配内存  指针地址
    pQueue->pBase = (int *)malloc(sizeof(ElementType) * length);          //分配length个ElementType型所占的空间
    pQueue->front = 0;       //初始化时，front和rear值均为0
    pQueue->rear = 0;

    return;
}

void diyQueue2::diyQueue2Test() {
    MyQueue* myqueue;
    initQueue(myqueue,99);
//    std::cout << sizeof(struct MyQueue) << std::endl;

}