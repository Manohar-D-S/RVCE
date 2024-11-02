// .h No. 2

/*Header file accessing functions of the CIRCULAR QUEUE (Array Implementation)*/

#include "queue.c"
#include "arrayQueue.h"
#include "stdbool.h"
#define IHEAD ((q.head + 1) % SIZE)                 //increment head/tail
#define ITAIL ((q.tail + 1) % SIZE)


void enQ(int data){
    if(q.tail == SIZE - 1)
        printf("QUEUE FULL\n");
    else{
        if(q.head == -1)
            q.head++;
        q.list[  ((q.head + 1) % SIZE)  ] = data;
        printf("%d enqueued successfully\n");
    }
}

void deQ(){
    if(q.head == -1)                           //if the queue is empty
        printf("QUEUE EMPTY\n");
    else{
        printf("%d dequeued\n", q.list[q.head]);
        (q.head == q.tail) ? (q.head = q.tail = -1) : (q.head = (q.tail + 1) % SIZE) ;   //if  both head and tail are pointing to the same element
    }
}

// bool isEmpty(QUEUE q){
//     return (((q.head == -1 && q.tail == -1) ? true : false));
// }

// bool isEmpty(QUEUE q){
//     return (((q.tail = SIZE - 1) ? true : false));
// }

// int size(QUEUE q){
//     return (q.tail - q.head + 1);
// }

// int queueFront(QUEUE q){            //returns the tail refernce of the queue
//     return q.list[q.tail];
// }

// int queueEnd(QUEUE q){              //returns the head refernce of the queue
//     return q.list[q.head];
// }
//

//the above functions are in the first .h itself

void printQueue(){
    if(isEmpty(*q)){
        printf("Queue Empty\n");
        return;
    } else {
        int i = q.tail;
        while (true)
        {
            printf("%d\t", q.list[i]);
            if(i == q.tail)
                break;
            i = ( ++i ) % SIZE;
        }
        
    }
}



