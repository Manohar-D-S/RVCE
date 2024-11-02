/*Header file accessing functions of the LINEAR QUEUE (Array Implementation)*/

#include "stdbool.h"
#define SIZE 10

struct queue{
    int list[SIZE];
    int head, tail;
} typedef QUEUE;

QUEUE q;    //for circular queue

void enqueue(QUEUE  *q, int data){
    if(q->tail + 1 == SIZE)                 //to check overflow condition; (q->tail == size - 1)
        printf("Queue Full\n");
    else{
        (q->head == -1) ? (++q->head) : 1;  //if the queue is empty
        q->list[++q->tail] = data;
    }
}

void dequeue(QUEUE  *q){
    if(q->head == -1)                           //if the queue is empty
        printf("Queue Empty\n");
    else{
        printf("%d dequeued\n", q->list[q->head]);
        (q->head == q->tail) ? (q->head = q->tail = -1) : q->head++ ;   //if  both head and tail are pointing to the same element
    }
}

bool isEmpty(QUEUE  *q){
    return (((q->head == -1 && q->tail == -1) ? true : false));
}

bool isFull(QUEUE  *q){
    return (((q->tail == SIZE - 1) ? true : false));
}

int size(QUEUE  *q){
    return (q->tail - q->head + 1);
}

int queueFront(QUEUE  *q){            //returns the tail refernce of the queue
    return q->list[q->tail];
}

int queueEnd(QUEUE  *q){              //returns the head refernce of the queue
    return q->list[q->head];
}

void printQueue(QUEUE  *q){
    for(int i = q->tail; i > q->head+1; i--){
        printf("%d  ", q->list[i]);
    }
    printf("\n");
}




