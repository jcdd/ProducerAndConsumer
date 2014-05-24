#include"mutex.h"

inline int Mutex::Lock() {
  return pthread_mutex_lock(&pthread_mutex_);
}

inline int Mutex::Unlock() {
  return pthread_mutex_unlock(&pthread_mutex_);
}
