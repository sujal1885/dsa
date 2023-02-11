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

dnode* insertLeft(dnode* Rear1,int id){
    if(len==3){
        printf("Sorry , limit exceeded\n");
        return Rear1;
    }
    len++;
    dnode* new;
    new = createNode();
    new->data = id;
    new->left = NULL;
    new->right = NULL;

    if(Rear1==NULL) return new;
    new->right = Rear1;
    Rear1->left = new;
    return new;
}


dnode* deleteLeft(dnode* First1,int* del){
    if(First1==NULL){
        *del = -9999;
        return NULL;
    }
    dnode* temp ;
    temp = First1;
    *del = temp->data;
    First1 = First1->left;
    if(First1 != NULL) First1->right = NULL;
    free(temp);
    len--;
    return First1;
}



void displayLeft(dnode* First1){
    if(First1 == NULL){
        printf("No passengers on left\n");
        return;
    }
    printf("The id's of passengers on left are\n");
    dnode* temp=First1;
    while(temp){
        printf("%d  ",temp->data);
        temp = temp->left;
    }
    printf("\n");
}



int TotalPassengers(){
    return len;
}

int main(){
    dnode* First1 = NULL;
    dnode* Rear1= NULL;
    int id,del;

    printf("Welcome to the bus\n\n");
    while(1){
        printf("Enter 1 to insert\nEnter 2 for deleting\nEnter 3 to display  passenger's id\nEnter 4 to get the total number of passengers\nEnter 5 to exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==5) break;
        switch(ch){
            case 1 : printf("Enter the id of the passenger\n");
                     scanf("%d",&id);
                     Rear1=insertLeft(Rear1,id);
                     if(First1==NULL) First1=Rear1;
                     break;


            case 2 : First1=deleteLeft(First1,&del);
                     if(First1==NULL) Rear1=NULL;
                     if(del==-9999){
                        printf("No more passengers\n");
                     }
                     else{
                        printf("Deleted passenger's id : %d\n",del);
                     }
                     break;


            case 3 : displayLeft(First1);
                     break;

            case 4 : printf("Total passengers : %d\n",TotalPassengers());
                     break;

            default: printf("Invalid key\n");
                     break;
        }
    }

    return 0;
}