#include <iostream>
#include "./stack/stack.h"
#include "./stack/stackLink.h"
#include "./queue/queue.h"
#include "./queue/anyqueue.h"
#include "./queue/linkqueue.h"
using namespace std;
using namespace StackSeq; // 顺序栈
using namespace StackLink; // 链式栈
using namespace diyQueue;
using namespace diyQueue2;
using namespace AnyQueue;
using namespace linkQueue; // 链式队列

int main() {
    std::cout << "Hello, World!" << std::endl;
//    StackSeq::StackTest();
//    StackLink::StackTest();
//    SqQueue Q = diyQueue::createQueue();
//    cout << sizeof (Q) <<endl;
//    diyQueue2::diyQueue2Test();
//    AnyQueue::AnyQueueTest();
//    linkQueue::linkQueueTest();
    linkQueue::linkQueueTest();

}
