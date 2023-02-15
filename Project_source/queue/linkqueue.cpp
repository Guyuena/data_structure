//
// Created by jc on 2022/12/4.
//

#include "iostream"
#include "linkqueue.h"
using namespace linkQueue;

/*初始化队列*/
//void linkQueue::CreateQueue(LinkQueue *Q)
//{
//    Q->Front->next=NULL;
//    Q->Rear->next=NULL;
//}
//
//
///*判断是否队空*/
//bool linkQueue::IsEmpty(LinkQueue *Q)
//{
//    return(Q->Front->next==NULL && Q->Rear->next==NULL);
//}
//
///*入队：在对尾插入元素X*/
//void linkQueue::InsertQue(LinkQueue *Q,ElementType X)
//{
//    LinkNode *p;
//    p=new LinkNode;
//    p->data=X;
//    p->next=NULL;
//    if(IsEmpty(Q))
//        Q->Front->next=Q->Rear=p;
//    else{
//        Q->Rear->next=p;
//        Q->Rear=p;
//    }
//}
//
///*出队：返回队头元素*/
//ElementType linkQueue::DeleteQue(LinkQueue *Q)
//{
//    ElementType x;
//    LinkNode *p;
//    if(IsEmpty(Q)){
//        std::cout<<"queue is empty"<<std::endl;
//        return 0;
//    }
//    p=Q->Front->next;
//    x=p->data;
////    std::cout << x << std::endl;
//    Q->Front->next=p->next;
//    if(Q->Rear==p)
//        Q->Rear=Q->Front;
//    delete p;
//    return(x);
//
//}
//
//void linkQueue::linkQueueTest() {
//    std::cout << "here" <<std::endl;
//    LinkNode node;
//    LinkQueue * Q;
//    Q->Front=&node;
//    Q->Rear=&node;
//    CreateQueue(Q);
//    for(int i=1;i<11;i++)   //在队列中输入1~10这10个元素
//        InsertQue(Q,i);     //
//    int i=0;
//    while(!IsEmpty(Q))     //输出
//        std::cout<< i++<<' ';
//    std::cout << "here" <<std::endl;
//}


void linkQueue::initQueue(LQueue *q){
    q->front = q->rear = (Qnode *)malloc(sizeof(Qnode));
    q->front->next = NULL;
}

int linkQueue::empty(LQueue *t){
    return t->front->next == t->rear;
}

// 添加元素
void linkQueue::push(LQueue *t, int x){
    // 新建节点
    Qnode *s = (Qnode *)malloc(sizeof(Qnode));
    // 新节点数据准备
    s->data = x;
    s->next = NULL;

    // 连接到当前队列的链表中，插入到队尾中
    t->rear->next = s; // 源队列的队尾的元素的next指向这个新插入的元素
    t->rear = s; // 更新队尾指针
}

void linkQueue::pop(LQueue *t){
    if(empty(t)){
        std::cout << "LQueue is empty,can't pop.\n";
        return;
    }
    Qnode *q = t->front->next; // 取出需要出类的节点

    t->front->next = q->next; // 更新对头指针
    free(q); // 释放节点内存
    if(t->rear == NULL)
        t->rear = t->front;
}

////  获取队列的对头元素
int linkQueue::getFront(LQueue *t){
    return t->front->next->data;
}
////  获取队尾的对头元素
int linkQueue::getRear(LQueue *t){
    return t->rear->data;
}
////  当前队列长度
int linkQueue::getSize(LQueue *t){
    Qnode *q = t->front->next;
    int k = 0;
    while(q){
        k++;
        q = q->next;
    }
    return k;
}

void linkQueue::printQueue(LQueue *t){
    Qnode *q = t->front->next;
    while(q){
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << "\n";
}

// 链式存储的队列不限制队列的长度，插入一个元素就新开辟一个内存空间


void linkQueue::linkQueueTest(){
    LQueue L;
    initQueue(&L);
    std::cout << "Push data to Queue...\n";
    push(&L,2);
    push(&L,5);
    push(&L,4);
    push(&L,3);
    push(&L,6);
    push(&L,8);
    push(&L,10);
    push(&L,11);
    std::cout << "Push finished.\n";
    std::cout << "You have pushed such data:";
    printQueue(&L);
    std::cout << "current queue size is "<<getSize(&L) <<std::endl;
    std::cout << "Pop data out of Queue...\n";
    pop(&L);
    std::cout << "Pop finished.\n";
    std::cout << "Now the Queue have such data:";
    printQueue(&L);
    std::cout << "Get Queue's front data:" << getFront(&L) << std::endl;
    std::cout << "Get Queue's rear data:" << getRear(&L) << std::endl;
    std::cout << "Get Queue's size:" << getSize(&L) << std::endl;
    pop(&L);
    pop(&L);
    pop(&L);
    std::cout << "After poped 3 times:";
    printQueue(&L);
    std::cout << "Judge the Queue is null or not(0 means not null,others means null):" << empty(&L) << std::endl;
    pop(&L);
    pop(&L);
    pop(&L);
    pop(&L);
    std::cout << "After poped 4 times:";
    printQueue(&L);
    std::cout << "Judge the Queue is null or not(0 means not null,others means null):" << empty(&L) << std::endl;

}