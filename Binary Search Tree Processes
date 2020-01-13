#include <stdio.h>
#include <stdlib.h>
struct n{
    int data;
    struct n* right;
    struct n* left;
};
typedef struct n node;
struct node* add(node* tree,int x){
    if(tree==NULL){
        node* root= (node *)malloc(sizeof( node));
        root->right=NULL;
        root->left=NULL;
        root->data=x;
        return root;
    }
    if(tree->data < x){
        tree->right = add(tree->right,x);
        return tree;
    }
    tree->left = add(tree->left,x);
    return tree;
}
void inorder( node* tree){//küçükten büyüðe siralama
    if(tree==NULL)
        return;
    inorder(tree->left);
    printf("%d ",tree->data);
    inorder(tree->right);
}
void postorder( node* tree){//büyükten küçüðe siralama
    if(tree==NULL)
        return;
    postorder(tree->right);
    printf("%d ",tree->data);
    postorder(tree->left);
}
int findNode(node* tree,int wantedNode){//aranan düğüm var mı yok mu

    if(tree==NULL)
        return -1;
    if(tree->data==wantedNode)
        return 1;
    if(findNode(tree->right,wantedNode)==1)
        return 1;
    if(findNode(tree->left,wantedNode)==1)
        return 1;
    return -1;
}
int maxValue(node* tree){
    while(tree->right!=NULL)
        tree=tree->right;
    return tree->data;
}
int minValue(node* tree){
    while(tree->left!=NULL)
        tree=tree->left;
    return tree->data;
}
int treeSize(node* tree){
    if(tree==NULL)
        return 0;
    else
        return treeSize(tree->left)+1+treeSize(tree->right);
}

int main()
{
    struct node * tree=NULL;
    tree = add(tree,26);
    tree = add(tree,75);
    tree = add(tree,64);
    tree = add(tree,62);
    tree = add(tree,24);
    tree = add(tree,93);
    tree = add(tree,27);
    tree = add(tree,75);
    tree = add(tree,66);
    tree = add(tree,34);
    tree = add(tree,29);
    tree = add(tree,18);

    printf(" inorder :");
    inorder(tree);
    printf("\n postorder :");
    postorder(tree);
    printf("\n bulunan sonuc :%d \n",findNode(tree,100));
    printf(" bulunan sonuc :%d \n",findNode(tree,75));
    printf(" en buyuk deger :%d \n",maxValue(tree));
    printf(" en kucuk deger :%d \n",minValue(tree));
    printf(" agacin boyutu :%d",treeSize(tree));
    return 0;
}
