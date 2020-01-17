#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node doubleLinked;
doubleLinked *insertAtFirst(doubleLinked *head, int key){  //Listenin başına ekleme
    if(head==NULL){
        head=(doubleLinked*)malloc(sizeof(doubleLinked));
        head->data=key;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        doubleLinked *temp=(doubleLinked *)malloc(sizeof(doubleLinked));
        temp->data=key;
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
    }
    return head;
}
doubleLinked *insertAtEnd(doubleLinked *head,int key){  //Listenin sonuna ekleme
    if(head==NULL){
        head=(doubleLinked*)malloc(sizeof(doubleLinked));
        head->data=key;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        doubleLinked *temp=head;
        doubleLinked *temp2=(doubleLinked *)malloc(sizeof(doubleLinked));
        while(temp->next!=NULL)
            temp=temp->next;
        temp2->data=key;
        temp2->prev=temp;
        temp2->next=NULL;
        temp->next=temp2;
    }
    return head;
}
void printList(doubleLinked *head){     //Listeyi yazdırma
    if(head==NULL){
        printf("List is empty..");
        return;
    }
    doubleLinked *temp=head;
    while(temp!=NULL){
        printf("%d =>",temp->data);
        temp=temp->next;
    }
}
int main()
{
    doubleLinked *m=(doubleLinked *)malloc(sizeof(doubleLinked));
    m->data=14;
    m->next=NULL;
    m->prev=NULL;
    m=insertAtFirst(m,32);
    m=insertAtFirst(m,35);
    m=insertAtEnd(m,39);
    m=insertAtEnd(m,38);
    m=insertAtFirst(m,31);
    printList(m);
    return 0;
}
