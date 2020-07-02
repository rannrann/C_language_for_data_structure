#ifndef _QUEUE_
#define _QUEUE_

#define Q Queue_Q

typedef struct Q *Q;

extern int queue_getSize(Q *q);
extern bool queue_isEmpty(Q *q);
extern void enqueue(Q *q, Q e);
extern Q dequeue(Q *q);
extern Q queue_getFront(Q *q);

#endif