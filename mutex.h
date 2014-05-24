#ifndef _MUTEX_H_
#define _MUTEX_H_

#include<pthread.h>
#include"condition.h"

class Mutex {
 public:
  friend class Condition;
  Mutex() {
    pthread_mutex_init(&pthread_mutex_, NULL);
 }
  ~Mutex() {
    pthread_mutex_destroy(&pthread_mutex_);
 }
  
  int Lock();
  int Unlock();
 
 private:
  pthread_mutex_t pthread_mutex_;
};
#endif

  
