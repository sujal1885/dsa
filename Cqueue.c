/*
    circular queue
    By sujal Agrawal
    Date : 04/02/2023
*/

#include<stdio.h>
#include<stdlib.h>

struct cqueue{
    int* arr;
    int front;
    int rear;
    int size;  // total capacity of the queue
    int currLen;  // current elements in the queue
};

typedef struct cqueue Cqueue;



void initialize(Cqueue* q){
    q->front = -1;
    q->rear = -1;
    int size;
    while(1){
        printf("Enter the maximum capacity of the queue\n");
        scanf("%d",&size);
        if(size<1){
            printf("Please enter valid size\n");
        }
        else{
            q->size = size;
            q->currLen = 0;
            q->arr = (int*)malloc(sizeof(int)*size);
            break;
        }
   }
}

void insert(Cqueue* q,int key){
    if(q->currLen>=q->size){
        printf("queue is full\n");
        return;
    }
    if(q->front==-1){
        q->front++;
        q->rear++;
        q->arr[q->rear] = key;
        q->currLen++;
    }
    else if(q->rear==q->size-1){  // if the queue is not full and rear has reached last index
        q->rear = 0;
        q->arr[q->rear] = key;
        q->currLen++;
    }
    else{
        q->rear++;
        q->arr[q->rear]=key;
        q->currLen++;
    }
}

void delete(Cqueue *q){   //deletes element from CQueue , if not empty
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
        q->currLen--;
    }
    else if(q->front==q->size-1){
        q->front=0;
        q->currLen--;
    }
    else{
        q->front++;
        q->currLen--;
    }
}

int isEmpty(Cqueue q){
    if(q.front==-1 && q.rear==-1)
        return 1;
    return 0;
}

int isFull(Cqueue q){
    if((q.rear==q.size-1 && q.front==0) || (q.rear==q.front-1))
        return 1;
    return 0;
}

int frontVal(Cqueue q){
    return q.arr[q.front];
}

int rearVal(Cqueue q){
    return q.arr[q.rear];
}

void display(Cqueue q){
    if(q.front==-1){
        printf("queue is empty\n");
        return;
    }
    printf("The current status of the CQueue\n");
    if(q.front>q.rear){
        for(int i=q.front;i<q.size;i++){
            printf("%d ",q.arr[i]);
        }
        for(int i=0;i<=q.rear;i++){
            printf("%d ",q.arr[i]);
        }
    }
    else
    for(int i=q.front;i<=q.rear;i++)
        printf("%d ",q.arr[i]);
    printf("\n");
}

int main(){
    Cqueue q;
    initialize(&q);
    while(1){
        printf("Enter 1 to Insert\nEnter 2 to delete\nEnter 3 for Isempty\nEnter 4 for Isfull\nEnter 5 for FrontValue\nEnter 6 for RearVal\nEnter 7 for display\nEnter 8 to exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==8) break;
        switch(ch){
            case 1:
                    if(isFull(q)){
                        printf("CQueue overflow.can't insert.\n");
                    }
                    else{
                        printf("Enter the value to be inserted\n");
                        int ele;
                        scanf("%d",&ele);
                        insert(&q,ele);
                    }
                    break;
            case 2:
                     if(isEmpty(q)){
                         printf("CQueue underflow.can't delete.\n");
                     }
                     else{
                         delete(&q);
                     }
                     break;
            case 3:
                     if(isEmpty(q))
                         printf("True\n");
                     else
                         printf("False\n");
                     break;
            case 4:
                     if(isFull(q))
                         printf("True\n");
                     else
                         printf("False\n");
                     break;
            case 5:
                     if(isEmpty(q)){
                        printf("queue is empty.\n");
                     }
                     else{
                         int ele=frontVal(q);
                         printf("%d\n",ele);
                     }
                     break;
            case 6:  
                     if(isEmpty(q)){
                        printf("queue is empty.\n");
                     }
                     else{
                         int ele=rearVal(q);
                         printf("%d\n",ele);
                     }
                     break;
           case 7:
                     if(isEmpty(q)){
                        printf("queue is empty.\n");
                     }
                     else{
                         display(q);
                     }
                     break;
           default:
                     printf("Invalid choice\n");
                    
        }
    }
    return 0;
}