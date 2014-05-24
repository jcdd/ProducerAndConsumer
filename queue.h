#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<iostream>
#include<pthread.h>
#include"mutex.h"
#include"condition.h"
#include"mutex.cpp"
#include"condition.cpp"

class Mutex;
class Condition;
using namespace std;

template <class T>
class Queue {
 public: 
  Queue() {}
  Queue(int size , Mutex* m , Condition* c) {
    buff = new T[size];
    front_ = 0;
    tail_ = 0;
    number_ = 0;
    MaxSize_ = size;
    queue_mutex_ = m;
    queue_cond_=c;
  }

  ~Queue() {
    delete buff;
  }
   
 void Enqueue(T& item) {
   queue_mutex_->Lock();
   while(number_ == MaxSize_) {
  //   cout<<"queue is full "<<endl;
     queue_cond_->Wait(queue_mutex_);
   }
   buff[tail_] = item;
   ++tail_;
   ++number_;
   cout<< "producer thread: "<<pthread_self();
   cout<<"     enqueue......"<<item<<endl;
   queue_mutex_->Unlock();
   queue_cond_->Signal();  
 }

  void Dequeue() {
    queue_mutex_->Lock();
    while(number_ == 0){
//      cout<<"queue is empty  "<<endl;
      queue_cond_->Wait(queue_mutex_);   
  }
   T value = buff[front_];
   ++front_;
   --number_;
   cout<< "consumer thread: "<<pthread_self();
   cout<<"      dequeue......"<<value<<endl;
   queue_mutex_->Unlock();
   queue_cond_->Signal();
  }

  bool IsEmpty(){
    if(number_ == 0)
      return true;
    else
      return false;
  }

  bool IsFull(){
    if(number_ == MaxSize_)
      return true;
    else
      return false;
  }

  int Size(bool real) {
    return number_;
}
 
 private:
  int front_;
  int tail_;
  int number_;
  T* buff;
  int MaxSize_;
  Mutex* queue_mutex_;
  Condition* queue_cond_;
};   
#endif
