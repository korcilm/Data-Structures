#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

typedef struct node BinaryTree;

BinaryTree* newNode(int data){
    BinaryTree* p=(BinaryTree*)malloc(sizeof(BinaryTree));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
BinaryTree* insert(BinaryTree* root,int data){
    if(root!=NULL){
        if(data < root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    }
    else
        root=newNode(data);
    return root;
}

int minValue(BinaryTree* root){
    if(root==NULL)
        return 0;
    while (root->left!=NULL)
        root=root->left;
    return (root->data);
}

int maxValue(BinaryTree* root){
    if(root==NULL)
        return 0;
    while(root->right!=NULL)
        root=root->right;
    return (root->data);
}

void preorder(BinaryTree* root){//ilk olarak root(kök), sonra left (sol alt aðaç) ve ardýndan right (sað alt aðaç) dolaþýlýr.
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(BinaryTree* root){//önce left (sol alt aðaç), sonra root (kök) ve right(sað alt aðaç) dolaþýlýr.
    if(root!=NULL){
 		inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
	}

}
void postorder(BinaryTree* root){//önce left (sol alt aðaç), sonra right (saðalt aðaç) ve root (kök) dolaþýlýr.
    if(root!=NULL){

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int size(BinaryTree* root){
    if(root==NULL)
        return 0;
    else
        return size(root->left)+1+size(root->right);
}
int main(int argc, char *argv[]) {

    int i;
    i=0;
    BinaryTree* MyTree=NULL;
    printf("Agaca Sayi Ekleyin:");
    scanf("%d ",&i);
    while(i != -1){
        MyTree=insert(MyTree,i);
        printf("Agaca Sayi Ekleyin:");
        scanf("%d ",&i);
    }
    printf("En Buyuk Deger: %d\n",maxValue(MyTree));
    printf("En Kucuk Deger: %d\n",minValue(MyTree));
    printf("Agacin Boyutu:%d\n",size(MyTree));
    printf(" preorder: ");
    preorder(MyTree);
    printf("\n inorder: ");
    inorder(MyTree);
    printf("\n postorder: ");
    postorder(MyTree);
    return 0;
}
