#ifndef _THREAD_H_
#define _THREAD_H_
#include<iostream>
#include"threadbase.h"
#include"queue.h"
#include <unistd.h>

using namespace std;
template<class T> class Queue;
template<class T> class Thread;

template<class T>
class Thread : public ThreadBase<T> {
 public:
  Thread(){}
  Thread(Queue<T>* queue ,int flag ,T item ) {
    queue_ = queue;
    flag_= flag;
    item_=item;
  }
    
  void Run() {
    if(flag_ == 1)
      while(1){
        sleep(1);
	    queue_->Enqueue(item_);
      }
    else
      while(1){
        sleep(1);
	    queue_->Dequeue();
      } 
  }

 private:  
  Queue<T>* queue_;
  int flag_;
  T item_;
};
#endif
