#ifndef _PRODUCER_H_
#define _PRODUCER_H_
#include"queue.h"
#include"thread.h"
#include"mutex.h"
#include"condition.h"
#include<iostream>
#include<unistd.h>

#include<pthread.h>
using namespace std;

template<class T>
class ProducerConsumer {
 public:
  ProducerConsumer(int buff_size ,int producer_number , int consumer_number){
    number_producer_= producer_number;
    number_consumer_= consumer_number;
    mutex_= new Mutex;
    cond_= new Condition(mutex_);
    queue_= new Queue<T>(buff_size , mutex_ ,cond_);
    p1 = new pthread_t[number_producer_];
    p2 = new pthread_t[number_consumer_];
  }

  void Produce(T& item){
    Thread<T>* thread1[number_producer_];
    for(int i =0 ;i < number_producer_ ;++i){
      thread1[i]=new Thread<T>(queue_ ,1 ,item);
      thread1[i]->Start(p1[i]);
	}
  }
	
  void Consume() {
    Thread<T>* thread2[number_consumer_];
    for(int i =0 ;i < number_consumer_ ;++i){
      thread2[i]= new Thread<T>(queue_ ,2 ,arg);
      thread2[i]->Start(p2[i]);
    }
  }
   /*
  void join(){
    for(int i =0 ;i < number_producer_ ;++i)
      pthread_join(p1[i] ,NULL);
    for(int i =0 ;i < number_consumer_ ;++i)
       pthread_join(p2[i] ,NULL);
  }
*/
 private:
  T arg;
  int number_producer_;
  int number_consumer_;
  
  Mutex* mutex_;
  Condition* cond_;
  Queue<T>* queue_;
  pthread_t* p1;
  pthread_t* p2;  
};
#endif
     
