#include <iostream>
#define MAXN 100005
using namespace std;

int queue[MAXN];
int head = 0;
int tail = 0;


void push(int num){
    queue[tail++] = num;
}

bool empty(){
    return (head == tail);
}

int front(){
    if(empty()) return -1;

    return queue[head];
}

int pop(){
    if(empty()) return -1;
    int ans = front();

    head ++;
    return ans;
}

int size(){
    return tail - head;
}