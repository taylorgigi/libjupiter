//
// Created by taylor on 2020/8/22.
//

#include <iostream>
#include <memory>
#include <string>
#include "../CircularQueue.h"

class Student
{
public:
    Student() { std::cout << "Student()\n"; }
    Student(const std::string& name): name_(name) { std::cout << "Student(string)\n"; }
    ~Student() { std::cout << "~Student()\n"; }
    const char* name() { return name_.c_str(); }
private:
    std::string name_;
};

int main(int argc, char *argv[])
{
    jupiter::CircularQueue<int> circular_que(5);
    if(circular_que.empty())
        std::cout << "empty" << std::endl;
    circular_que.enqueue(1);
    circular_que.enqueue(2);
    circular_que.enqueue(3);
    circular_que.enqueue(4);
    std::cout << "queue size: " << circular_que.size() << std::endl;
    if(circular_que.full())
        std::cout << "full" << std::endl;
    circular_que.enqueue(5);
    circular_que.enqueue(6);
    std::cout << "queue size: " << circular_que.size() << std::endl;
    while(!circular_que.empty()) {
        int v;
        circular_que.dequeue(v);
        std::cout << "pop " << v << std::endl;
    }

    jupiter::CircularQueue<std::unique_ptr<int>> cq(5);
    cq.enqueue(std::make_unique<int>(10));
    cq.enqueue(std::make_unique<int>(11));
    cq.enqueue(std::make_unique<int>(12));
    cq.enqueue(std::make_unique<int>(13));
    cq.enqueue(std::make_unique<int>(14));
    cq.enqueue(std::make_unique<int>(15));
    while(!cq.empty()) {
        std::unique_ptr<int> ptr;
        cq.dequeue(ptr);
        std::cout << "pop " << *ptr << std::endl;
    }

    jupiter::CircularQueue<Student> students(5);
    Student xiao_ming("xiao ming");
    students.enqueue(xiao_ming);
    Student xiao_gang("xiao gang");
    students.enqueue(xiao_gang);
    while(!students.empty()) {
        Student st;
        students.dequeue(st);
        std::cout << "pop " << st.name() << std::endl;
    }

    return 0;
}
