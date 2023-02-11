/*
    passengers problem
    Doubly linked list
    Date : 04/01/2023
    By sujal Agrawal
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


dnode* insertRight(dnode* Rear2,int id){
    if(len==3){
        printf("Sorry , limit exceeded\n");
        return Rear2;
    }
    len++;
    dnode* new;
    new = createNode();
    new->data = id;
    new->left = NULL;
    new->right = NULL;

    if(Rear2==NULL) return new;
    new->left = Rear2;
    Rear2->right = new;
    return new;
}


dnode* deleteRight(dnode* First2,int *del){
    if(First2==NULL){
        *del = -9999;
        return NULL;
    }
    dnode* temp ;
    temp = First2;
    *del = temp->data;
    First2 = First2->right;
    if(First2 != NULL) First2->left = NULL;
    free(temp);
    len--;
    return First2;
}


void displayRight(dnode* First2){
    if(First2 == NULL){
        printf("No passengers\n");
        return;
    }
    printf("The id's of passengers on right are\n");
    dnode* temp=First2;
    while(temp){
        printf("%d  ",temp->data);
        temp = temp->right;
    }
    printf("\n");
}

int TotalPassengers(){
    return len;
}

int main(){
    dnode* First2 = NULL;
    dnode* Rear2 = NULL;
    int id,del;

    printf("Welcome to the bus\n\n");
    while(1){
        printf("Enter 1 to insert \nEnter 2 for deleting from right\nEnter 3 to display right passenger's id\nEnter 4 to get the total number of passengers\nEnter 5 to exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==5) break;
        switch(ch){

            case 1 : printf("Enter the id of the passenger\n");
                     scanf("%d",&id);
                     Rear2=insertRight(Rear2,id);
                     if(First2==NULL) First2=Rear2;
                     break;


             case 2 : First2=deleteRight(First2,&del);
                     if(First2==NULL) Rear2=NULL;
                     if(del==-9999){
                        printf("No more passengers on left\n");
                     }
                     else{
                        printf("Deleted passenger's id : %d\n",del);
                     }
                     break;

            case 3 : displayRight(First2);
                     break;

            case 4 : printf("Total passengers : %d\n",TotalPassengers());
                     break;

            default: printf("Invalid key\n");
                     break;
        }
    }

    return 0;
}