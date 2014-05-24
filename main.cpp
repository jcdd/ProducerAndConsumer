#include"producerconsumer.h"
#include<pthread.h>
#include <unistd.h>
#include<string>
#include<stdlib.h>
int main() {
  /*
  *web github haha
  */
 /*
  * @jcdd
  * 23:24
  */
  string item ="apple";
  ///缂傛挸鍟块崠鍝勩亣鐏忓繗顔曟稉锟�0閿涳拷娑擃亞鏁撴禍褑锟介敍锟芥稉顏呯Х鐠愮锟�
  ProducerConsumer<string>* procon = new ProducerConsumer<string>(150 ,3, 3);
  procon->Produce(item);
  procon->Consume();
  sleep(10000);  
  return 0;
}
