#include"condition.h"

inline void Condition::Wait(Mutex* mutex) {
  pthread_cond_wait(&condition_, &mutex_->pthread_mutex_);
}

inline void Condition::Signal(){
 pthread_cond_signal(&condition_); 
}

inline void Condition::BroadCast() {
 pthread_cond_broadcast(&condition_);
}
