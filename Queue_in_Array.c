#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10
typedef struct{
    int front;
    int rear;
    int counter;
    int data[QUEUE_SIZE];
}queue;
void initialize(queue *q){   //Queue default (başlangıç) değer atama
    q->front=0;
    q->rear= -1;
    q->counter=0;
}
typedef enum{false,true}boolean;
boolean isEmpty(queue *q){  //Queue boş mu kontrolü
    return (q->counter==0);
}
boolean isFull(queue *q){   //Queue dolu mu kontrolü
    return (q->counter==QUEUE_SIZE);
}
void enqueue(queue *q, int x){  //Queue ekleme
    if(!isFull(q)){
        q->rear++;
        q->counter++;
        if(q->rear==QUEUE_SIZE)
            q->rear=0;
        q->data[q->rear]=x;
    }
}
int dequeue(queue *q){  //Queue silme
    if(!isEmpty(q)){
        int x=q->data[q->front];
        q->front++;
        q->counter--;
        if(q->front==QUEUE_SIZE)
            q->front=0;
        return x;
    }
}
void printQueue(queue *q){  //Queue yazdırma
    while(q->counter!=0){
        printf("%d =>",q->data[q->front]);
        q->front++;
        q->counter--;
        if(q->front==QUEUE_SIZE)
            q->front=0;
    }
}
int main()
{
    int x;
    queue m;
    initialize(&m);
    enqueue(&m,29);
    enqueue(&m,22);
    enqueue(&m,25);
    enqueue(&m,23);
    x=dequeue(&m);
    printf("%d deleted\n",x);
    printQueue(&m);
    return 0;
}
