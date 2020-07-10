#ifndef _QUEUE_
#define _QUEUE_
#include <stdbool.h>

/*队列接口，规范ArrayQueue和LoopQueue
但是以下方法只能被定义一次，不能重复定义
而且即使导入ArrayQueue和LoopQueue其中一个
也不能避免报错*/
#define Q Queue_Q

typedef struct Q *Q;

extern int queue_getSize(Q *q);
extern bool queue_isEmpty(Q *q);
extern void enqueue(Q *q, Q e);
extern Q dequeue(Q *q);
extern Q queue_getFront(Q *q);

#endif