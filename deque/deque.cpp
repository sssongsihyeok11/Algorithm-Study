#include <iostream>
#define MAXN 100005
using namespace std;

int deque[2*MAXN + 1];
int head = MAXN;
int tail = MAXN;

bool empty(){
    return (head == tail);
}
int size(){
    return tail - head;
}
int front(){
    if(empty()) return -1;
    return deque[head];
}
int back(){
    if(empty()) return -1;
    return deque[tail - 1];
}
void push_front(int num){
    deque[--head] = num;
}
void push_back(int num){
    deque[tail++] = num;
}

int pop_front(){
    if(empty()) return -1;
    int ans = front();
    head ++;
    return ans;
}
int pop_back(){
    if(empty()) return -1;
    int ans = back();
    tail --;
    return ans;
}