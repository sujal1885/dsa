#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct queue*front;
    struct queue*rear;
};

struct queue *q;

void creation (struct queue *);
struct queue *insert(struct queue *);
struct queue *deletee(struct queue *);
struct queue *display(struct queue *);

int main()
{
    int option;
    creation(q);
    do
    {
        printf("\n 1.insert\n");
        printf("2.delete \n");
        printf("3.display\n");
        printf("4.Exit \n");
        printf("Enter your option \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: q=insert(q);
                    break;
            case 2:q=deletee(q);
                    break;
            case 3:q=display(q);
                    break;
        }
    }while(option!=4);
    return 0;
}

void creation (struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

struct queue*insert(struct queue *q)
{
    struct node *new_node,*ptr;
    int val;
    printf("Enter the value to be inserted :\n");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    if(q->front==NULL && q->rear==NULL)
    {
        q->front=new_node;
        q->rear=new_node;
        q->front->next=NULL;
        q->rear->next=NULL;
    }
    else
    {
        q->rear=ptr;
        q->rear->next=NULL;
    }
    return q;
}

struct queue *deletee(struct queue *q)
{
    struct node *ptr;
    ptr=q->front;
    if(q->front==NULL)
    {
        printf("queue underflow \n");
    }
    else
    {
        q->front=q->front->next;
        printf("The value being deleted is %d", ptr->data);
        free(ptr);
    }
    return q;
}

struct queue *display(struct queue *q)
{
    struct node *ptr;
    ptr=q;
    if(q->front==NULL && q->rear==q->front)
    {
        printf("queue empty \n");
    }
    else
    {
        while(ptr->front!=q->rear)
        {
            printf("%d \t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    return q;
}