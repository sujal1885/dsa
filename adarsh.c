#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct q
{
    struct node *rear;
    struct node *front;
};

struct q *qu;
void created(struct q *);
struct q *insert(struct q *,int);
struct q *deletee(struct q *);
struct q *display(struct q *);

void main()
{
    int val,opt;
    created(qu);
    do
    {
        printf("\nmainmenu\n");
        printf("1.Insert\n");
        printf("2.delete\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter you option \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:printf("Enter the value to be added \n");
            scanf("%d",&val);
            qu=insert(qu,val);
            break;
            case 2:qu=deletee(qu);
            break;
            case 3:qu=display(qu);
            break;
        }
    }while(opt!=4);
}

void created(struct q *qu)
{
    qu->rear=NULL;
    qu->front=NULL;
}

struct q *insert(struct q *qu,int val)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    if(qu->front==NULL)
    {
        qu->front=ptr;
        qu->rear=ptr;
        qu->front->next=qu->rear->next=NULL;
    }
    else
    {
        qu->rear->next=ptr;
        qu->rear=ptr;
        qu->rear->next=NULL;
    }
    return qu;
}

struct q *display(struct q *qu)
{
    struct node *ptr;
    ptr=qu->front;
    if(ptr==NULL)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("\n");
        while(ptr!=qu->rear)
        {
            printf("%d \t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d \t",ptr->data);
    }
    return qu;
}
struct q *deletee(struct q *qu)
{
    struct node *ptr;
    ptr=qu->front;
    if(qu->front==NULL)
    {
        printf("Underflow \n");
    }
    else
    {
        qu->front=qu->front->next;
        printf("the value being deleted is %d \n",ptr->data);
        free(ptr);
    }
    return qu;
}
