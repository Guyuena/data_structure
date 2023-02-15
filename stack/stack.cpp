#include<iostream>

#define MaxSize 100

using namespace std;



// 栈stack的顺序储存结构实现

typedef struct SNode* Stack;

// struct SNode
// {
//     int *Data; // 存储元素的数组
//     int MaxSize; // 最大容量
//     int Top; // 栈顶指针
// };

typedef int ElementType;

struct SNode
{
    ElementType Data[MaxSize]; // 一个个元素就存在这个数组里面
    int top;
};

Stack Ptrstack;

// 新建栈空间
// 返回栈储存数据的数组的指针

Stack CreateStack(){
    Ptrstack = (Stack)malloc(sizeof(struct SNode)); // 动态申请内存空间
    std::cout <<"申请的内存字节大小为： "<< (sizeof(struct SNode)) << " byte" << std::endl;
    //  字节数 = MaxSize * sizeof(ElementType) + sizeof(int);
    Ptrstack->top = -1; // 空栈，栈顶指针赋值为-1
    return Ptrstack; // 返回指向这个栈存储结构的指针

}


// 入栈
// 参数： Ptrstack 栈地址， item 入栈元素
void Push(Stack Ptrstack, ElementType item){
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

ElementType Pop(Stack Ptrstack){
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

bool isFull(Stack Ptrstack){
    if (Ptrstack->top == MaxSize -1)
    {
        return true;
    }
    else{
        return false;
    }
}

// 栈空判断
bool isEmpty(Stack Ptrstack){
    if (Ptrstack->top == -1)
    {
        return true;
    }
    else{
        return false;
    }
}

// 输出栈中所有元素

void PrintStack(Stack Ptrstack){
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

int main(){

    Ptrstack = CreateStack();
    std::cout << isEmpty(Ptrstack) << std::endl;
    Pop(Ptrstack);
    Push(Ptrstack,5);
    PrintStack(Ptrstack);
    std::cout << isFull(Ptrstack) << std::endl;
    Pop(Ptrstack);

    
}

// #include <iostream>
// using namespace std;
// typedef int ElementType;
// /*定义链队结构类型*/
// struct QueNode
// {
//     ElementType data;
//     QueNode *next;
// };
// struct LinkQueue
// {
//     QueNode *Front;
//     QueNode *Rear;
// };
//     void CreateQueue(LinkQueue *Q);
//     bool IsEmpty(LinkQueue *Q);
//     void InsertQue(LinkQueue *Q,ElementType X);
//     ElementType DeleteQue(LinkQueue *Q);
// int main()
// {


//     QueNode node;
//     LinkQueue *Q;
//     Q->Front=&node;
//     Q->Rear=&node;
//     CreateQueue(Q);
//     for(int i=1;i<11;i++)   //在队列中输入1~10这10个元素
//         InsertQue(Q,i);     //求队长
//     while(!IsEmpty(Q))     //输出
//         cout<<DeleteQue(Q)<<' ';

//     return 0;
// }

// /*初始化队列*/
// void CreateQueue(LinkQueue *Q)
// {
//     Q->Front->next=NULL;
//     Q->Rear->next=NULL;
// }


// /*判断是否队空*/
// bool IsEmpty(LinkQueue *Q)
// {
//     return(Q->Front->next==NULL && Q->Rear->next==NULL);
// }

// /*入队：在对尾插入元素X*/
// void InsertQue(LinkQueue *Q,ElementType X)
// {
//     QueNode *p;
//     p=new QueNode;
//     p->data=X;
//     p->next=NULL;
//     if(IsEmpty(Q))
//         Q->Front->next=Q->Rear=p;
//     else{
//         Q->Rear->next=p;
//         Q->Rear=p;
//     }
// }

// /*出队：返回队头元素*/
// ElementType DeleteQue(LinkQueue *Q)
// {
//     ElementType x;
//     QueNode *p;
//     if(IsEmpty(Q)){
//         cout<<"队空"<<endl;
//         return 0;
//     }
//     p=Q->Front->next;
//     x=p->data;
//     Q->Front->next=p->next;
//     if(Q->Rear==p)
//         Q->Rear=Q->Front;
//     delete p;
//     return(x);

// }



// #include <iostream>
// using namespace std;
// #define Maxsize 100

// typedef  struct SqQueue{
//   int *base; //基地址
//   int front,rear; //头指针,尾指针
// }SqQueue;

// //循环队列的初始化
// bool InitQueue(SqQueue &Q)//注意使用引用参数，否则出了函数，其改变无效
// {
// 	Q.base=new int[Maxsize];//分配空间
// 	if(!Q.base) return false;
// 	Q.front=Q.rear=0; //头指针和尾指针置为零，队列为空
// 	return true;
// }

// //循环队列的入队
// bool EnQueue(SqQueue &Q,int e)//将元素e放入Q的队尾
// {
// 	if((Q.rear+1)%Maxsize==Q.front) //尾指针后移一位等于头指针，表明队满
// 		return false;
// 	Q.base[Q.rear]=e; //新元素插入队尾
// 	Q.rear=(Q.rear+1)%Maxsize; //队尾指针加1
// 	return true;
// }

// //循环队列的出队
// bool DeQueue(SqQueue &Q, int &e) //删除Q的队头元素，用e返回其值
// {
// 	if (Q.front==Q.rear)
// 		return false; //队空
// 	e=Q.base[Q.front]; //保存队头元素
// 	Q.front=(Q.front+1)%Maxsize; //队头指针加1
// 	return true;
// }

// //取循环队列的队头元素
// int GetHead(SqQueue Q)//返回Q的队头元素，不修改队头指针
// {
// 	if (Q.front!=Q.rear) //队列非空
// 		return Q.base[Q.front];
//     return -1;
// }
// //循环队列的长度
// int QueueLength(SqQueue Q)
// {
// 	return (Q.rear-Q.front+Maxsize)%Maxsize;
// }

// int main()
// {
// 	SqQueue Q;
// 	int n,x;
// 	InitQueue(Q);//初始化队列(一定要初始化，否则后面存储出错)
// 	cout <<"请输入元素个数n：" <<endl;
// 	cin>>n;
// 	cout <<"请依次输入n个整型数，依次入队：" <<endl;
//     while(n--)
//     {
//        	cin>>x;
// 		EnQueue(Q,x);//入队
//     }
//     cout<<endl;
//     cout <<"队列内元素个数，即长度："<<QueueLength(Q)<<endl;
//     cout <<"队头元素：" <<GetHead(Q)<<endl;
// 	cout <<"元素依次出队：" <<endl;
// 	while(true)//如果栈不空，则依次出栈
//     {
//         if(DeQueue(Q,x))
//             cout<<x<<"\t";//出队元素
//         else
//             break;
//     }
//     cout <<endl;
//     cout <<"队列内元素个数，即长度："<<QueueLength(Q)<<endl;
// 	return 0;
// }