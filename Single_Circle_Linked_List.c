#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node circleLinked;
circleLinked * insertAtFront(circleLinked *head, int key) { //Listenin başına ekleme
    if(head == NULL) {
    head = (circleLinked *)malloc(sizeof(circleLinked));
    head -> data = key;
    head -> next = head;
    }
    else {
    circleLinked *temp = (circleLinked *)malloc(sizeof(circleLinked));
    circleLinked *last = head;
    temp -> data = key;
    while(last -> next != head)
        last = last -> next;
    temp -> next = head;
    last -> next = temp;
    head = temp;
    }
    return head;
}
circleLinked * insertAtLast(circleLinked *head, int key) { //Listenin sonuna ekleme
    if(head == NULL) {
    head = (circleLinked *)malloc(sizeof(circleLinked));
    head -> data = key;
    head -> next = head;
    }
    else {
    circleLinked *last = head;
    while(last -> next != head)
        last = last -> next;
    last -> next = (circleLinked *)malloc(sizeof(circleLinked));
    last -> next -> next = head;
    last -> next -> data = key;
    }
    return head;
}
void printList(circleLinked *head){  //Listeyi yazdırma
    if(head==NULL){
        printf("List is empty..\n");
        return;
    }
    circleLinked *temp=head;
    printf("%d =>",temp->data);
    temp=temp->next;
    while(temp!=head){
        printf("%d =>",temp->data);
        temp=temp->next;
    }
}
int main()
{
    circleLinked *m=(circleLinked *)malloc(sizeof(circleLinked));
    m->data=10;
    m->next=m;
    m=insertAtFront(m,5);
    m=insertAtFront(m,9);
    m=insertAtLast(m,17);
    m=insertAtLast(m,28);
    m=insertAtFront(m,15);
    m=insertAtFront(m,12);
    m=insertAtLast(m,29);
    m=insertAtLast(m,21);
    printList(m);
    return 0;
}
