/*  
    doubly linked list
    By sujal Agrawal
*/

#include<stdio.h>
#include<stdlib.h>

struct dnode{
    int data;
    struct dnode* left;
    struct dnode* right;
};

typedef struct dnode ddnode;

ddnode* createDnode(){
    ddnode* temp;
    temp=(ddnode*)malloc(sizeof(ddnode));
    return temp;
}

ddnode* insert(ddnode* First,int ele){
    ddnode* new = createDnode();
    new->data = ele;
    new->left = NULL;
    new->right = NULL;
    
    if(First==NULL) return new;
    ddnode* temp = First;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    temp->right=new;
    new->left=temp;
    return First;
}

ddnode* displayLeft(ddnode* First){
    printf("The contents of the list are \n");
    ddnode* temp = First;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->left;
    }
    printf("\n");
}

ddnode* displayRight(ddnode* First){
    printf("The contents of the list are \n");
    ddnode* temp = First;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->right;
    }
    printf("\n");
}

int main(){
    struct dnode* First=NULL;
    for(int i=0;i<4;i++){
        First = insert(First,i);
    }
    displayRight(First);
    
    
    return 0;
}
