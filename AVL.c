/*
    AVL Tree
    Sujal Agrawal
    Date : 10/02/2023
*/

#include<stdio.h>
#include<stdlib.h>

struct AVLNode{
    int data;
    struct AVLNode* lchild;
    struct AVLNode* rchild;
    int height;
};

typedef struct AVLNode AVL;

AVL* createAvlNode(int key){
    AVL* temp = (AVL*)malloc(sizeof(AVL));
    if(temp == NULL){
        printf("AVL underflow , creation failed\n");
        return NULL;
    }
    temp->data = key;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->height = 1;
    return temp;
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}

void PreOrder(AVL* root){
    if(!root){
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

void Inorder(AVL* root){
    if(!root){
        return;
    }
    Inorder(root->lchild);
    printf("%d ",root->data);
    Inorder(root->rchild);
}

void PostOrder(AVL* root){
    if(!root){
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%d ",root->data);
}


int heightAvlNode(AVL* root){
    if(!root){
        return 0;
    }
    return root->height;
}

AVL* rightRotate(AVL* root){
    AVL* l = root->lchild;
    AVL* ll = l->rchild;

    l->rchild = root;
    root->lchild = ll;

    root->height = max(heightAvlNode(root->lchild),heightAvlNode(root->rchild))+1;
    l->height = max(heightAvlNode(l->lchild),heightAvlNode(l->rchild))+1;
    return l;
}

AVL* leftRotate(AVL* root){
    AVL* r = root->rchild;
    AVL* rr = r->lchild;

    r->lchild = root;
    root->rchild = rr;

    root->height = max(heightAvlNode(root->lchild),heightAvlNode(root->rchild))+1;
    r->height = max(heightAvlNode(r->lchild),heightAvlNode(r->rchild))+1;
    return r;
}

int balanceFactor(AVL* root){
    if(root == NULL){
        return 0;
    }
    return heightAvlNode(root->lchild)-heightAvlNode(root->rchild);
}

AVL* inorderSuccessor(AVL* root){
    if(root->lchild == NULL){
        return root;
    }
    return inorderSuccessor(root->lchild);
}

AVL* deleteAvl(AVL* root,int* key){
    if(root == NULL){
        *key = -9999;
        return root;
    }
    if(*key < root->data){
        root->lchild = deleteAvl(root->lchild,key);
    }
    else if(*key > root->data){
        root->rchild = deleteAvl(root->rchild,key);
    }
    else{
        AVL* temp = NULL;
        if(root->lchild == NULL || root->rchild == NULL){
            if(root->lchild != NULL){
                temp = root->lchild;
            }
            else{
                temp = root->rchild;
            }
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
                root->height = temp->height;
                free(temp);
            }
        }
        else{
            temp = inorderSuccessor(root->rchild);
            root->data = temp->data;
            root->rchild = deleteAvl(root->rchild,&temp->data);
        }
    }
    if(root = NULL){
        return root;
    }

    root->height = max(heightAvlNode(root->lchild),heightAvlNode(root->rchild))+1;

    int bal = balanceFactor(root);
    int lbal = balanceFactor(root->lchild);
    int rbal = balanceFactor(root->rchild);

    if(bal>1 && lbal>=0){  // LL case
        return rightRotate(root);
    }

    if(bal>1 && lbal<0){ // LR case
        root->lchild = leftRotate(root->lchild);
        return rightRotate(root);
    }

    if(bal<-1 && rbal<=0){  // RR case
        return leftRotate(root);
    }

    if(bal<-1 && rbal>0){ // RL case
        root->rchild == rightRotate(root->rchild);
        return leftRotate(root);
    }
    return root;
}

AVL* insertAvl(AVL* root,int key){
    if(!root){
        return createAvlNode(key);
    }

    if(key < root->data){
        root->lchild = insertAvl(root->lchild,key);
    }
    if(key>root->data){
        root->rchild = insertAvl(root->rchild,key);
    }
    else{
        return root;
    }

    root->height = max(heightAvlNode(root->lchild),heightAvlNode(root->rchild))+1;

    int bal = balanceFactor(root);

    AVL* lc = root->lchild; // left child
    AVL* rc = root->rchild; // right child

    if(bal>1 && key<(lc)->data){ // LL case
        return rightRotate(root);
    }

    if(bal<-1 && key>(rc)->data){ // RR case
        return leftRotate(root);
    }

    if(bal>1 && key>lc->data){ // LR case
        root->lchild = leftRotate(root->lchild);
        return rightRotate(root);
    }

    if(bal<-1 && key<rc->data){ // RL case
        root->rchild = rightRotate(root->rchild);
        return leftRotate(root);
    }

    return root;

}

int main(){
    AVL* root = NULL;
    int key,ch,par,cnt;
    while(1){
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 for preorder\nEnter 4 for inorder\nEnter 5 for postorder\nEnter 6 to exit\n");
        scanf("%d",&ch);
        if(ch==6){
            break;
        }
        switch(ch){
            case 1 : printf("Enter the value to insert\n");
                     scanf("%d",&key);
                     root = insertAvl(root,key);
                     break;

            case 2 : printf("Enter the value to delete\n");
                     scanf("%d",&key);
                     root = deleteAvl(root,&key);
                     break;

            case 3 : PreOrder(root);
                     printf("\n");
                     break;

            case 4 : Inorder(root);
                     printf("\n");
                     break;

            case 5 : PostOrder(root);
                     printf("\n");
                     break;
            
            default : printf("Invalid choice\n");
                      break;
        }
    }
    return 0;
}

