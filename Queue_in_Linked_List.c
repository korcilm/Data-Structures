#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10
typedef struct{
    int cnt;
    struct node *front;
    struct node *rear;
}queue;
struct node{
    int data;
    struct node *next;
};
typedef enum{false,true}boolean;
boolean isEmpty(queue *q){  //Queue boş mu kontrolü
    return (q->cnt==0);
}
boolean isFull(queue *q){   //Queue dolu mu kontrolü
    return (q->cnt==QUEUE_SIZE);
}
void initialize(queue *q){   //Queue default (başlangıç) değer atama
    q->cnt=0;
    q->front=NULL;
    q->rear=NULL;
}
void enqueue(queue *q, int x){  //Queue ekleme
    if(!isFull(q)){
       struct node *temp=(struct node *)malloc(sizeof(struct node));
       temp->next=NULL;
       temp->data=x;
       if(isEmpty(q)){
            q->front=temp;
            q->rear=temp;
       }
       else{
            q->rear->next=temp;
            q->rear=temp;
       }
       q->cnt++;
    }
}
int dequeue(queue *q){  //Queue silme
    if(!isEmpty(q)){
        struct node *temp=q->front;
        int x=temp->data;
        q->front=temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}
void printQueue(queue *q){  //Queue yazdırma
    while(q->cnt!=0){
        struct node *temp=q->front;
        printf("%d =>",temp->data);
        q->front=temp->next;
        free(temp);
        q->cnt--;
    }
}
int main()
{
    int x;
    queue m;
    initialize(&m);
    enqueue(&m,5);
    enqueue(&m,2);
    enqueue(&m,9);
    enqueue(&m,7);
    x=dequeue(&m);
    printf("%d deleted\n",x);
    printQueue(&m);
    return 0;
}
