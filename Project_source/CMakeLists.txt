cmake_minimum_required(VERSION 3.23)
project(Project_source)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project_source main.cpp stack/stack.cpp stack/stack.h stack/stackLink.cpp stack/stackLink.h example/stack_use_example.cpp queue/queue.cpp queue/queue.h queue/cirqueue.cpp queue/cirqueue.h queue/anyqueue.cpp queue/anyqueue.h queue/queueClass.cpp queue/queueClass.h queue/linkQueue.cpp queue/linkqueue.h example/p24_demo.cpp Pipe/pipe_communication.cpp)
