#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4
typedef struct{
    struct node *top;
    int counter;
}stack;
struct node{
    int data;
    struct node *next;
};
typedef enum{false,true}boolean;
boolean isEmpty(stack *stk){    //Stack boş mu kontrolü
    return (stk->counter==0);
}
boolean isFull(stack *stk){     //Stack dolu mu kontrolü
    return (stk->counter==STACK_SIZE);
}
void push(stack *stk, int x){   //Stack'e ekleme
    if(!isFull(stk)){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=stk->top;
        stk->top=temp;
        stk->counter++;
    }
    else
        printf("stack is full..\n");
}
int pop(stack *stk){    //Stack'tan silme
    if(!isEmpty(stk)){
        struct node *temp=stk->top;
        stk->top=stk->top->next;
        int x =temp->data;
        free(temp);
        stk->counter--;
        return x;
    }
}
void printList(stack *stk){    //Stack'i yazdırma
    printf("Elements \n");
    while(!isEmpty(stk)){
        struct node *temp=stk->top;
        printf("-> %d \n",temp->data);
        stk->top=stk->top->next;
        free(temp);
        stk->counter--;
    }
}
void initialize(stack *stk){    //Stack'e default (başlangıç) değeri atama
    stk->top=NULL;
    stk->counter=0;
}
int main()
{
    int x;
    stack m;
    initialize(&m);
    push(&m,16);
    push(&m,15);
    push(&m,18);
    push(&m,13);
    push(&m,12);
    x=pop(&m);
    printf("%d deleted \n",x);
    x=pop(&m);
    printf("%d deleted \n",x);
    printList(&m);
    return 0;
}
