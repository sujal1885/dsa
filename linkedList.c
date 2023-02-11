/*
    Linked List
    By sujal Agrawal
*/
#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int data;
    struct linkedList *link;
};

typedef struct linkedList node;

node *GenerateNode()
{ // returns a pointer to a generated node
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    return temp;
}

int LENGTH(node *FIRST)
{ // returns a the length of the list
    int len = 0;
    node *temp = FIRST;
    while (temp)
    {
        len++;
        temp = temp->link;
    }
    return len;
}

node *createList(node *FIRST)
{ // creates list
    int numberOfNodes;
    printf("Enter the number of nodes : \n");
    scanf("%d", &numberOfNodes);
    node *temp = FIRST;
    for (int i = 0; i < numberOfNodes; i++)
    {
        node *temp1 = GenerateNode();
        if (temp == NULL)
        {
            temp = temp1;
            FIRST = temp;
            int val;
            printf("Enter value : \n");
            scanf("%d", &val);
            temp->data = val;
        }
        else
        {
            temp->link = temp1;
            temp = temp->link;
            int val;
            printf("Enter value : \n");
            scanf("%d", &val);
            temp->data = val;
        }
    }
    return FIRST;
}

node *INSERTBEGIN(node *FIRST)
{
    node *temp = GenerateNode();
    int value;
    printf("Insert value\n");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;

    if (!FIRST)
        return temp;
    temp->link = FIRST;
    return temp;
}

node *INSERTATEND(node *FIRST)
{
    node *temp = GenerateNode();
    int value;
    printf("Insert value\n");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;

    if (!FIRST)
        return temp;
    node *temp1 = FIRST;
    while (temp1->link)
    {
        temp1 = temp1->link;
    }
    temp1->link = temp;
    return FIRST;
}

node *INSERTPOS(node *FIRST)
{
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        return INSERTBEGIN(FIRST);
    }

    if (pos > LENGTH(FIRST))
    {
        return INSERTATEND(FIRST);
    }
    node *temp = GenerateNode();
    int value;
    printf("Insert value\n");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;

    node *temp1 = FIRST;
    int ind = 0;
    while (ind < pos - 2)
    {
        ind++;
        temp1 = temp1->link;
    }

    temp->link = temp1->link;
    temp1->link = temp;
    return FIRST;
}

node *DELETEATBEGIN(node *FIRST)
{
    if (!FIRST || !FIRST->link)
        return NULL;
    node *temp = FIRST->link;
    free(FIRST);
    return temp;
}

node *DELETEATLAST(node *FIRST)
{
    if (!FIRST || !FIRST->link)
        return NULL;
    node *temp = FIRST;

    while (temp->link->link)
    {
        temp = temp->link;
    }

    node *temp1 = temp->link;
    temp->link = NULL;
    free(temp1);
    return FIRST;
}

void DISPLAY(node *FIRST)
{
    if (!FIRST)
    {
        printf("Empty list\n");
    }
    node *temp = FIRST;
    printf("The list is : \n");
    while (temp)
    {
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

node *DELETEATPOS(node *FIRST)
{
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        return DELETEATBEGIN(FIRST);
    }

    if (pos >= LENGTH(FIRST))
    {
        return DELETEATLAST(FIRST);
    }

    int ind = 0;
    node *temp = FIRST;
    while (ind < pos - 2)
    {
        ind++;
        temp = temp->link;
    }

    node *temp1 = temp->link;
    temp->link = temp->link->link;
    free(temp1);
    return FIRST;
}

node *UPDATE(node *FIRST)
{
    printf("Enter value to be updated.\n");
    int ch;
    scanf("%d", &ch);
    int val;
    printf("Enter the replaced value : \n");
    scanf("%d", &val);
    node *temp = FIRST;
    int done = 0;
    while (temp)
    {
        if (temp->data == ch)
        {
            temp->data = val;
            done = 1;
            break;
        }
        temp = temp->link;
    }
    if (!done)
    {
        printf("Unsuccessful\n");
    }
    else
    {
        printf("successfully updated list.\n");
    }
    return FIRST;
}

int main()
{

    node *FIRST; // By sujal Agrawal
    FIRST = NULL;
    int len;

    while (1)
    {
        printf("Enter 1 to create list\nEnter 2 to insert at begin\nEnter 3 to insert at any position\nEnter 4 to insert at last position\nEnter 5 to delete at first position\nEnter 6 to delete at any position\nEnter 7 to delete at last position\nEnter 8 to display the list\nEnter 9 to get the length of the list\nEnter 10 to update the list\nEnter 11 to exit\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 11)
            break;
        else
        {
            switch (ch)
            {
            case 1:
                FIRST = createList(FIRST);
                break;

            case 2:
                FIRST = INSERTBEGIN(FIRST);
                break;
            case 3:
                FIRST = INSERTPOS(FIRST);
                break;

            case 4:
                FIRST = INSERTATEND(FIRST);
                break;

            case 5:
                FIRST = DELETEATBEGIN(FIRST);
                break;

            case 6:
                FIRST = DELETEATPOS(FIRST);
                break;

            case 7:
                FIRST = DELETEATLAST(FIRST);
                break;

            case 8:
                DISPLAY(FIRST);
                break;

            case 9:                 
                len = LENGTH(FIRST);
                printf("Length=%d\n", len);
                break;

            case 10:
                FIRST = UPDATE(FIRST);
                break;

            case 11:
                printf("Invalid choice.\n");
            }
        }
    }
    return 0;
}
