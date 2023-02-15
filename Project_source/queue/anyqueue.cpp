//
// Created by jc on 2022/12/4.
//

#include "iostream"
#include "anyqueue.h"


//Queue myQueue;


Queue AnyQueue::CreateQueue(int length) {
    Queue myQueue;
    //    申请任意长度空间
    myQueue->pBase =( ElementType*) malloc(sizeof (ElementType)*length);
    myQueue->front=0;
    myQueue->rear=0;
    return myQueue;

}
void AnyQueue::AnyQueueTest() {
    Queue myQueue;
    myQueue = CreateQueue( 100);

}