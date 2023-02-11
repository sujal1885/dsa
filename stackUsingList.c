/*
    stack implementation using linked list
    By sujal Agrawal
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

typedef struct node list;

list* createNode(){
    list* temp;
    temp=(list*)malloc(sizeof(list));
    return temp;
}

list* push(int ele,list* First){
    list* temp=createNode();
    if(temp==NULL){
        printf("Memory unavailable\n");
        return NULL;
    }

    temp->data=ele;
    temp->link=First;

    return temp;
}

list* pop(list* First){
    if(First==NULL){
        printf("Stack is empty\n\n");
        return NULL;
    }

    list* temp;
    temp=First;
    First=First->link;
    free(temp);

    return First;
}

int peek(list* First){
    if(First==NULL){
        printf("Stack is empty\n\n");
        return -9999;
    }

    return First->data;
}

void display(list* First){
    if(First==NULL){
        printf("Stack is empty\n\n");
        return;
    }
    
    list* temp=First;
    printf("The stack contents are \n");
    
    while(temp){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("\n");
    
    return;
}

int main(){
    int ele,p;
    list* First;
    First=NULL;
    while(1){
        printf("Enter 1 for push.\nEnter 2 for pop.\nEnter 3 for peek.\nEnter 4 for display.\nEnter 5 to exit.\n\n");
        int ch;
        scanf("%d",&ch);
        if(ch==5){
             break;
        }
        switch(ch){
            case 1: 
                    printf("Enter element to push\n");
                    scanf("%d",&ele);
                    First=push(ele,First);
                    break;
           case 2: 
                   First=pop(First);
                   break;   
           case 3: 
                   p=peek(First);
                   if(p!=-9999)
                      printf("The top element is %d\n\n",p);
                   break;
           case 4: display(First);
                   break;
           default : printf("Please enter valid key.\n\n");                               
        }
    }

    return 0;
}