#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3
typedef struct{
    int top;
    int data[STACK_SIZE];
}stack;
void push(stack *stk, int x){   //Stack'e ekleme
    if(stk->top==STACK_SIZE-1)
        printf("stack is full..\n");
    else{
        stk->top++;
        stk->data[stk->top]=x;
    }
}
int pop(stack *stk){    //Stack'e silme
    if(stk->top== -1)
        printf("stack is empty..\n");
    else{
        int x=stk->top--;
        return x;
    }
}
void printList(stack *stk){    //Stack'i yazdırma
    if(stk->top== -1)
        printf("stack is empty..\n");
    else{
        printf("Elements\n");
        while(stk->top!= -1){
            printf("->%d \n",stk->data[stk->top]);
            stk->top--;
        }
    }
}
void reset(stack *stk){   //Stack'i sıfırlama
    stk->top= -1;
}
int main()
{
    int x;
    stack m;
    reset(&m);
    printList(&m);
    push(&m,7);
    push(&m,9);
    push(&m,1);
    x=pop(&m);
    printf("%d.index deleted\n",x);
    x=pop(&m);
    printf("%d.index deleted\n",x);
    push(&m,8);
    push(&m,6);
    printList(&m);
    return 0;
}
