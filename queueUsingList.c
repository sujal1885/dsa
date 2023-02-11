/*
    queue using linked list
    By sujal Agrawal
    Date : 27/12/2022
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

typedef struct node list;

list* createNode()
{
    list *temp;
    temp = (list*)malloc(sizeof(list));
    return temp;
}

list* insert(list* First, list* Tail, int ele)
{
    list* temp;
    temp = createNode();
    if (temp == NULL)
    {
        printf("No memory available.\n");
        return NULL;
    }

    temp->data = ele;
    temp->link = NULL;

    

    return temp;
}

list* delete(list* First, list* Tail,int* del)
{
    if (First == NULL)
    {
        printf("queue is empty\n");
        *del=-9999;
        return NULL;
    }
    *del = First->data;
    list* temp = First;
    First = First->link;
    free(temp);

    if (First == NULL)
    {
        Tail = NULL;
    }

    return First;
}

void isEmpty(list *First)
{
    if (First == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue is not empty\n");
}

void frontVal(list *First)
{
    if (First == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("front value = %d\n", First->data);
}

void rearVal(list *Tail)
{
    if (Tail == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("Rear value = %d\n", Tail->data);
}

void display(list* First)
{
    if (First == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue contents are\n");
    list* temp = First;
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    list* First;
    list* Tail;
    int del,ele;
    First = Tail = NULL;
    while (1)
    {
        printf("Enter 1 to Insert\nEnter 2 to delete\nEnter 3 for Isempty\nEnter 4 for FrontValue\nEnter 5 for RearVal\nEnter 6 for display\nEnter 7 to exit\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 7)
            break;
        switch (ch)
        {
        case 1:
            printf("Enter element : \n");
            scanf("%d", &ele);
            if(Tail==NULL)
                Tail=insert(First, Tail, ele);
            else{
                Tail->link=insert(First,Tail,ele);
                Tail=Tail->link;
            }
            if(First==NULL) First=Tail;
            break;
        case 2:
            First = delete (First, Tail,&del);
            if(First==NULL) Tail=NULL;
            if (del != -9999)
            {
                printf("deleted element : %d\n", del);
            }
            break;
        case 3:
            isEmpty(First);
            break;
        case 4:
            frontVal(First);
            break;
        case 5:
            rearVal(Tail);
            break;
        case 6:
            display(First);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}