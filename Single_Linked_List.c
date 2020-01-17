#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node singleLinked;
singleLinked *new_node(singleLinked *head, int key){  //Liste oluşturma
    head->data=key;
    head->next=NULL;
    return head;
}
singleLinked *addHead(singleLinked *head, int key){   //Listenin başına ekleme
    singleLinked *temp=(singleLinked *)malloc(sizeof(singleLinked));
    temp->data=key;
    temp->next=head;
    head=temp;
    return temp;
}
singleLinked *addLast(singleLinked *head, int key){   //Listenin sonuna ekleme
    singleLinked *temp=(singleLinked *)malloc(sizeof(singleLinked));
    temp->data=key;
    temp->next=NULL;
    singleLinked *temp2=head;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    temp2->next=temp;
    return head;
}
singleLinked *addMiddle(singleLinked *head, int key, int x){  //Listenin ortasına ekleme
    singleLinked *temp=(singleLinked *)malloc(sizeof(singleLinked));
    temp->data=key;
    singleLinked *q=head;
    while(q->data!=x)
        q=q->next;
    temp->next=q->next;
    q->next=temp;
    return head;
}
void printList(singleLinked *head){  //Listeyi yazdırma
    if(head==NULL){
        printf("\nList is empty..");
        return;
    }
    singleLinked *temp2=head;
    while(temp2!=NULL){
        printf("%d =>",temp2->data);
        temp2=temp2->next;
    }
}
singleLinked *searchNode(singleLinked *head, int key){   //Listede düğüm arama
    singleLinked *locate=NULL;
    while(head!=NULL){
        if(head->data!=key)
        head=head->next;
        else{
            locate=head;
            printf("\n%d is exists",key);
            break;
        }
    }
    return(locate);
}
singleLinked *deleteList(singleLinked *head){  //Lİsteden düğümleri silme
    if(head==NULL)
        printf("List is empty..\n");
    singleLinked *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        int q=temp->data;
        free(temp);
        printf("\n%d -> deleted",q);
    }
    return head;
}
int main()
{
    singleLinked *m=(singleLinked *)malloc(sizeof(singleLinked));
    m=new_node(m,12);
    m=addHead(m,29);
    m=addLast(m,18);
    m=addLast(m,21);
    m=addHead(m,15);
    m=addLast(m,24);
    m=addMiddle(m,16,18);
    printList(m);
    searchNode(m,18);
    m=deleteList(m);
    printList(m);
    return 0;
}
