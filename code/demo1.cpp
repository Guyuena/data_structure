#include <iostream>

#include <windows.h>
using namespace std;



void printN(int N){
    int i;
    
    DWORD time_start, time_end;
    time_start = GetTickCount(); //从操作系统启动经过的毫秒数
    for (int i = 0; i <= N; i++)
    {
        cout << "i= " << i <<endl;
    }
    
    time_end = GetTickCount();
    cout << "Time = " << (time_end - time_start) << "ms\n ";
}


// 递归    注意递归过多会导致栈溢出
void printN2(int N){

    if(N){
        printN2(N-1);
        cout << "N= " << N <<endl;    
        }


}

int  main(){



    DWORD time_start, time_end;
    time_start = GetTickCount(); //从操作系统启动经过的毫秒数
    printN(20000);
    // printN2(20000);
    time_end = GetTickCount();
    cout << "Time = " << (time_end - time_start) << "ms\n ";

    return 0;

}