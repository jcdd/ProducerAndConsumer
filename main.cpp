#include"producerconsumer.h"
#include<pthread.h>
#include <unistd.h>
#include<string>
#include<stdlib.h>
int main() {
  /*
  *web github haha
  */
  string item ="apple";
  ///缓冲区大小设为150，3个生产者，3个消费者
  ProducerConsumer<string>* procon = new ProducerConsumer<string>(150 ,3, 3);
  procon->Produce(item);
  procon->Consume();
  sleep(10000);  
  return 0;
}
