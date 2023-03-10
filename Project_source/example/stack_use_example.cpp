//
// Created by jc on 2022/12/3.
//

#include "iostream"
#include "../stack/stack.h"
#include "../stack/stackLink.h"


////   栈的应用实例

// 将中缀运算表达式转换为后缀表达式，然后计算结果
// 用栈实现中缀表达式转后缀表达式以及后缀表达式的计算
// 2+9/3-5 ->  2 9 3 / + 5 -
/**
 * 1、运算数相对顺序不变
 * 2、运算符号顺序发生改变
 *      1）需要存储“等待中”的运算符号
 *      2）要将当前运算符号与“等待中”的最后一个运算符号比较
 * 3、有括号怎么处理？
 *
 * **/

// 栈的用途：  （1）函数调用及递归实现（2）深度优先搜索 （3）回溯算法

