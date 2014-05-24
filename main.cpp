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
  */
  string item ="apple";
  ///缂撳啿鍖哄ぇ灏忚涓�50锛�涓敓浜ц�锛�涓秷璐硅�
  ProducerConsumer<string>* procon = new ProducerConsumer<string>(150 ,3, 3);
  procon->Produce(item);
  procon->Consume();
  sleep(10000);  
  return 0;
}
