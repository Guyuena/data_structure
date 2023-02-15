////
//// Created by jc on 2023/2/14.
////
//#include "iostream"
//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int fd[2];
//    int ret = pipe(fd);
//    if (ret == -1)
//    {
//        perror("pipe error\n");
//        return 1;
//    }
//    pid_t id = fork();
//    if (id == 0)
//    {//child
//        int i = 0;
//        close(fd[0]);
//        char *child = “I am  child!”;
//        while (i<5)
//        {
//            write(fd[1], child, strlen(child) + 1);
//            sleep(2);
//            i++;
//        }
//    }
//    else if (id>0)
//    {//father
//        close(fd[1]);
//        char msg[100];
//        int j = 0;
//        while (j<5)
//        {
//            memset(msg,’\0’,sizeof(msg));
//            ssize_t s = read(fd[0], msg, sizeof(msg));
//            if (s>0)
//            {
//                msg[s - 1] = ’\0’;
//            }
//            printf(”%s\n”, msg);
//            j++;
//        }
//    }
//    else
//    {//error
//        perror(”fork error\n”);
//        return 2;
//    }
//    return  0;
//}



#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "pipe.h"
int main(int argc,char* argv[])
{
    pid_t pid;

    int fd[2];//定义管道的读、写端文件描述符
    int ret;

    char* str = "hello pipe\n";//指定写数据
    char buf[1024];//定义接收缓冲区

    ret = pipe(fd);//调用pipe()函数就已将管道打开

    if(ret == -1)
    {
        perror("pipe error");
        exit(1);
    }

    pid = fork();

    if(pid > 0)//父进程
    {
        close(fd[0]);
        write(fd[1],str,strlen(str));//写到管道中
        close(fd[1]);
    }
    else if(pid == 0)//子进程
    {
        close(fd[1]);
        ret = read(fd[0],buf,sizeof(buf));//从管道中的读，返回读到的字节数
        write(STDOUT_FILENO,buf,ret);//写到标准输出
        close(fd[0]);
    }

    return 0;
}
