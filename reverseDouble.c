/*
   Reversal of doubly linked list
   By sujal Agrawal
   Date : 11/01/2023
   Mentor : Rina Ma'am
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int len = 0;

typedef struct node dnode;

dnode* createNode(){
    dnode* temp;
    temp = (dnode*)malloc(sizeof(dnode));
    return temp;
}


dnode* insert(dnode* Rear,int id){
    len++;
    dnode* new;
    new = createNode();
    new->data = id;
    new->left = NULL;
    new->right = NULL;

    if(Rear==NULL) return new;
    new->left = Rear;
    Rear->right = new;
    return new;
}


dnode* delete(dnode* First,int *del){
    if(First==NULL){
        *del = -9999;
        return NULL;
    }
    dnode* temp ;
    temp = First;
    *del = temp->data;
    First = First->right;
    if(First != NULL) First->left = NULL;
    free(temp);
    len--;
    return First;
}


void display(dnode* First){
    if(First == NULL){
        printf("No passengers\n");
        return;
    }
    printf("The id's of passengers are\n");
    dnode* temp=First;
    while(temp){
        printf("%d  ",temp->data);
        temp = temp->right;
    }
    printf("\n");
}

dnode* reverse(dnode* First){
    if(First == NULL || First->right == NULL){
        return First;
    }
    dnode* rev = First;
    dnode* ptr1 = First->right;
    dnode* ptr2 = First->right->right;
    rev->right = NULL;
    rev->left = ptr1;
    ptr1->right = rev;
    ptr1->left = ptr2;
    while(ptr2){
        rev = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->right;
        ptr1->right = rev;
        ptr1->left = ptr2;
    }
    return ptr1;
}

int TotalPassengers(){
    return len;
}

int main(){
    dnode* First = NULL;
    dnode* Rear = NULL;
    int id,del;

    printf("Welcome to the bus\n\n");
    while(1){
        printf("Enter 1 to insert \nEnter 2 for deleting \nEnter 3 to display passenger's id\nEnter 4 to get the total number of passengers\nEnter 5 to reverse list\nEnter 6 to exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==6) break;
        switch(ch){

            case 1 : printf("Enter the id of the passenger\n");
                     scanf("%d",&id);
                     Rear=insert(Rear,id);
                     if(First==NULL) First=Rear;
                     break;


             case 2 : First=delete(First,&del);
                     if(First==NULL) Rear=NULL;
                     if(del==-9999){
                        printf("No more passengers on left\n");
                     }
                     else{
                        printf("Deleted passenger's id : %d\n",del);
                     }
                     break;

            case 3 : display(First);
                     break;

            case 4 : printf("Total passengers : %d\n",TotalPassengers());
                     break;

            case 5 : First = reverse(First);
                     break;

            default: printf("Invalid key\n");
                     break;
        }
    }

    return 0;
}