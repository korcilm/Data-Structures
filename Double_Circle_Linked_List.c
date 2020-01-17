#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node doubleCircle;
doubleCircle *insertAtFirst(doubleCircle *head, int key){   //Listenin başına ekleme
    if(head==NULL){
        head=(doubleCircle*)malloc(sizeof(doubleCircle));
        head->data=key;
        head->prev=head;
        head->next=head;
    }
    else{
        doubleCircle *temp=(doubleCircle *)malloc(sizeof(doubleCircle));
        temp->data=key;
        doubleCircle *last=head->prev;
        temp->next=head;
        head->prev=temp;
        last->next=temp;
        temp->prev=last;
        head=temp;
    }
    return head;
}
doubleCircle *insertAtEnd(doubleCircle *head,int key){  //Listenin sonuna ekleme
    if(head==NULL){
        head=(doubleCircle*)malloc(sizeof(doubleCircle));
        head->data=key;
        head->prev=head;
        head->next=head;
    }
    else{
        doubleCircle *temp=(doubleCircle *)malloc(sizeof(doubleCircle));;
        doubleCircle *last=head->prev;
        temp->data=key;
        temp->prev=last;
        temp->next=head;
        head->prev=temp;
        last->next=temp;
        last=temp;
    }
    return head;
}
void printList(doubleCircle *head){   //Listeyi yazdırma
    if(head==NULL){
        printf("List is empty..\n");
        return;
    }
    doubleCircle *temp=head;
    printf("%d =>",temp->data);
    temp=temp->next;
    while(temp!=head){
        printf("%d =>",temp->data);
        temp=temp->next;
    }
}
int main()
{
    doubleCircle *m=(doubleCircle *)malloc(sizeof(doubleCircle));
    m->data=14;
    m->next=m;
    m->prev=m;
    m=insertAtFirst(m,12);
    m=insertAtFirst(m,15);
    m=insertAtEnd(m,19);
    m=insertAtEnd(m,18);
    m=insertAtFirst(m,11);
    printList(m);
    return 0;
}
