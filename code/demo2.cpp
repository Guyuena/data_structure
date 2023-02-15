




// 计算多项式

#include<iostream>
#include<math.h>
#include <windows.h>
using namespace std;


double fun1(int n,double a[],double x) // n:阶数  a[] ：系数列表  x:需要计算的点
{
    int i;
    double p=a[0];
    for (int i = 0; i < n; i++)
    {
        p +=(a[i] *pow(x,i));
    }
    return p;


}

double fun2(int n,double a[],double x) // n:阶数  a[] ：系数列表  x:需要计算的点
{
    int i;
    double p=a[n];
    for (int i = n; i >0; i--)
    {
        p = a[i-1] + x*p;
    }
    return p;


}

// 计算同一个多项式，第二种计算方法比第一种快了一个数量级

int main(){


    double a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = (double) i;
    }
    


    DWORD time_start, time_end;
    time_start = GetTickCount(); //从操作系统启动经过的毫秒数

//单个计算非常快，多个执行来平均求时间
    for (int i = 0; i < 1000000; i++)
    {
        fun1(10-1,a,1.1);
    }
    
    

    time_end = GetTickCount();
    cout << "Time = " << (time_end - time_start) << "ms\n ";



    return 0;
}