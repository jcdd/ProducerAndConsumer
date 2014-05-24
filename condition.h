#ifndef _CONDITION_H_
#define _CONDITION_H_

#include <stdint.h>
#include<pthread.h>
#include"mutex.h"
class Mutex;

/*
 *
 */
class Condition {
 public:
  Condition(){}
  Condition(Mutex* mutex){
    pthread_cond_init(&condition_, NULL);
    is_signaled_ = 0;
    mutex_= mutex;
  }

  ~Condition(){
    pthread_cond_destroy(&condition_);
  }
   
  void Wait(Mutex* mutex);
  void Signal();
  void BroadCast();
   
 protected:
  pthread_cond_t condition_;
  int32_t is_signaled_;
   
 private:
  Mutex* mutex_;
};
#endif
   
