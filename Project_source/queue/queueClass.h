//
// Created by jc on 2022/12/4.
//

#ifndef PROJECT_SOURCE_QUEUECLASS_H
#define PROJECT_SOURCE_QUEUECLASS_H

#include "iostream"
using namespace std;

template <typename T>

//自己实现queue类
class queueClass {
private:
    int front;   //头元素下标
    int rear;    //尾元素下标
    int maxSize; //队列总空间大小
    T *array;

public:
    queueClass(int size = 10) //构造函数
    {
        front = 1;
        rear = 0;
        maxSize = size + 1;
        array = new T[maxSize];
    }

    T back()
    {
        if (empty())
        {
            cout << "队列为空" << endl;
            return NULL;
        }
        return array[rear];
    }

    bool empty()
    {
        if (size() == 0)
            return true;
        return false;
    }

    T frontValue()
    {
        if (empty())
        {
            cout << "队列为空" << endl;
            return NULL;
        }
        else
        {
            return array[front];
        }
    }

    void pop()
    {
        if (empty())
            cout << "队列已经为空" << endl;
        else
            front = (front + 1) % maxSize;
    }

    void push(T value)
    {
        if (size() == maxSize - 1)
        {
            cout << "队列已满，无法继续添加元素" << endl;
        }
        else
        {
            rear = (rear + 1) % maxSize;
            array[rear] = value;
        }
    }

    int size()
    {
        return (rear + maxSize - front + 1) % maxSize;
    }

};


#endif //PROJECT_SOURCE_QUEUECLASS_H
