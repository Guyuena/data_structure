//
// Created by jc on 2022/12/4.
//


// 多项式加法运算

#include "iostream"

struct PolyNode{
    int coef; //系数
    int expon;// 指数
    struct PolyNode* link;// 指向下一个节点的指针
};



typedef struct PolyNode* Polynomial;
//Polynomial P1,P2;

int compare(int expon1, int expon2){
    if (expon1 > expon2)
    {
        return 1;
    }
    else if (expon1 < expon2) {
        return -1;
    } else{
        return 0;
    }
}
void Attach(int coef, int expon, Polynomial *pNode) {
    /* 由于在本函数中需要改变当前结果表达式尾项指针的值， */
/* 所以函数传递进来的是结点指针的地址，*pRear指向尾项*/
    Polynomial P;
    P = (Polynomial) malloc(sizeof(struct PolyNode));/* 申请新结点 */
    /* 对新结点赋值 */
    P->coef = coef;
    P->expon= coef;
    P->link = NULL;
    /* 将P指向的新结点插入到当前结果表达式尾项的后面 */
    (*pNode)->link = P;
    /* 修改pRear值 */
    *pNode = P;
}



Polynomial PolyAdd(Polynomial P1,Polynomial P2){
    Polynomial front,rear,temp; // 头-尾-临时节点
    int sum;
    rear = (Polynomial ) malloc(sizeof (struct PolyNode));
    front = rear;
//    P1 P2 就是两个多项式的系数链表
    while (P1 &&P2){
        switch (compare(P1->expon,P2->expon)) {
            case 1:
                Attach(P1->coef,P1->expon,&rear);
                P1=P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&rear);
                P2=P2->link;
                break;
            case 0:
                sum = P1->coef + P2->coef;
                if (sum){
                    Attach(sum,P1->expon,&rear);
                }
                //同时都往右移一位
                P1=P1->link;
                P2=P2->link;
                break;
        }
    }
    for ( ;  P1 ; P1=P1->link ){
        Attach(P1->coef,P1->expon,&rear);
    }
    for ( ;  P2 ; P2=P2->link ){
        Attach(P2->coef,P2->expon,&rear);
    }
    /* 将未处理完的另一个多项式的所有节点依次复制到结果多项式中去 */
    rear->link=NULL;
    temp=front;
    front = front->link;/*令front指向结果多项式第一个非零项 */
    free(temp);/* 释放临时空表头结点 */
    return  front;
}




