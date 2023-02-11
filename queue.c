/*   
      Queue 
      By sujal Agrawal
*/

#include<stdio.h>
struct Queue{
    int arr[5];
    int front;
    int rear;
    int size;
};

void initialize(struct Queue *q){    // initialzes the queue
     q->front=-1;
     q->rear=-1;
     q->size=5;
}
void insert(struct Queue *q,int ele){   // inserts element to queue , if not full
    if(q->front==-1 && q->rear==-1)
        q->front=0;
    q->rear++;
    q->arr[q->rear]=ele;
}

void delete(struct Queue *q){   //deletes element from queue , if not empty
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else
        q->front++;
}

int isEmpty(struct Queue q){
    if(q.front==-1 && q.rear==-1)
        return 1;
    return 0;
}

int isFull(struct Queue q){
    if(q.rear==q.size-1)
        return 1;
    return 0;
}

int frontVal(struct Queue q){
    return q.arr[q.front];
}

int rearVal(struct Queue q){
    return q.arr[q.rear];
}

void display(struct Queue q){
    printf("The current status of the queue\n");
    for(int i=q.front;i<=q.rear;i++)
        printf("%d ",q.arr[i]);
    printf("\n");
}

int main(){
    struct Queue q;
    initialize(&q);
    while(1){
        printf("Enter 1 to Insert\nEnter 2 to delete\nEnter 3 for Isempty\nEnter 4 for Isfull\nEnter 5 for FrontValue\nEnter 6 for RearVal\nEnter 7 for display\nEnter 8 to exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==8) break;
        switch(ch){
            case 1:
                    if(isFull(q)){
                        printf("Queue overflow.can't insert.\n");
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
                         printf("Queue underflow.can't delete.\n");
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
                        printf("Stack is empty.\n");
                     }
                     else{
                         int ele=frontVal(q);
                         printf("%d\n",ele);
                     }
                     break;
            case 6:  
                     if(isEmpty(q)){
                        printf("Stack is empty.\n");
                     }
                     else{
                         int ele=rearVal(q);
                         printf("%d\n",ele);
                     }
                     break;
           case 7:
                     if(isEmpty(q)){
                        printf("Stack is empty.\n");
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
