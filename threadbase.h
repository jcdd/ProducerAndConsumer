#ifndef _THREADBASE_H_
#define _THREADBASE_H_

#include<pthread.h>

template<class T>
class ThreadBase {
 public:
  ThreadBase() {}
   
  int Start(pthread_t pthread , const pthread_attr_t* attr = NULL) {
    return pthread_create(&pthread, attr , &ThreadBase::DoStart , (void*)this);
  }
	
  static  void* DoStart(void* param) {
    ThreadBase* obj = (ThreadBase*)param;
	obj->Run();
	return NULL;
  }
 
  virtual  void Run() {}
   
 private:
  pthread_t thread_;
};
#endif
	
   
