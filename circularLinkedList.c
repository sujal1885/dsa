/*
    circular linked list
    By sujal Agrawal
    Date : 29/12/2022
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node cnode;

cnode* createCnode(){
    cnode* temp;
    temp = (cnode*)malloc(sizeof(cnode));
    temp->next = NULL;
    return temp;
}

int lenList(cnode* head){
    cnode* temp = head;
    int len=0;
    if(temp==NULL) return 0;
    while(temp->next!=head){
        len++;
        temp=temp->next;
    }
    return len+1;
}

cnode* insertAtBegin(cnode* head,cnode** tail,int key){
    cnode* neww;
    neww = createCnode();
    if(neww == NULL){
        printf("Memory Unavailable\n");
        return head;
    } 
    neww->data = key;
    if(head == NULL){
        neww->next = neww;
        (*tail) = neww;
        return neww;
    }
    neww->next = head;
    (*tail)->next = neww;
    return neww;
}

cnode* insertAtEnd(cnode* head,cnode** tail,int key){
    cnode* neww;
    neww = createCnode();
    if(neww == NULL){
        printf("Memory Unavailable\n");
        return head;
    } 
    neww->data = key;
    if(head == NULL){
        neww->next = neww;
        (*tail) = neww;
        return neww;
    }
    (*tail)->next = neww;
    (*tail) = neww;
    neww->next = head;
    return head;
}

cnode* insertAtPos(cnode* head,cnode** tail,int key,int pos){
    int len = lenList(head);
    if(pos<1 || pos>len+1){
        printf("Invalid position\n");
        return head;
    }
    if(pos==1){
        return insertAtBegin(head,tail,key);
    }
    if(pos==len+1){
        return insertAtEnd(head,tail,key);
    }
    cnode* neww;
    neww = createCnode();
    if(neww == NULL){
        printf("Memory Unavailable\n");
        return head;
    } 
    neww->data = key;
    int index = 0;
    cnode* temp = head;
    while(index<pos-2){
        temp=temp->next;
        index++;
    }
    neww->next = temp->next;
    temp->next = neww;
    return head;
}

cnode* deleteAtBegin(cnode* head,cnode** tail,int* key){
    if(head==NULL){
        printf("List is empty\n");
        *key = -9999;
        return head;
    }
    if(head->next == head){
        *key = head->data;
        (*tail) = NULL;
        return NULL;
    }
    cnode* temp = NULL;
    temp = head;
    *key = head->data;
    (*tail)->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

cnode* deleteAtEnd(cnode* head,cnode** tail,int* key){
    if(head==NULL){
        printf("List is empty\n");
        *key = -9999;
        return head;
    }
    if(head->next == head){
        *key = head->data;
        (*tail) = NULL;
        free(head);
        return NULL;
    }
    cnode* temp1 = head;
    while(temp1->next->next!=head){
        temp1=temp1->next;
    }
    cnode* temp = (*tail);
    *key = temp->data;
    temp1->next = head;
    (*tail) = temp1;
    free(temp);
    return head;
}

cnode* deleteAtPos(cnode* head,cnode** tail,int* key,int pos){
    int len = lenList(head);
    if(pos<1 || pos>len){
        printf("Invalid position\n");
        *key = -9999;
        return head;
    }
    if(pos==1){
        return deleteAtBegin(head,tail,key);
    }
    if(pos==len){
        return deleteAtEnd(head,tail,key);
    }
    int index = 0;
    cnode* temp = head;
    while(index<pos-2){
        temp=temp->next;
        index++;
    }
    cnode* temp1 = temp->next;
    *key = temp1->data;
    temp->next = temp->next->next;
    free(temp1);
    return head;
}

void display(cnode* head){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    cnode* temp = head;
    printf("List content's are : \n");
    while(temp->next!=head){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

cnode* reverseCList(cnode* head,cnode** tail){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next == head){  // list having a single node
        return head;
    }

    cnode* rev = head;
    cnode* ptr1 = head->next;
    cnode* ptr2 = head->next->next;

    if(rev == ptr2){
        (*tail) = rev;
        return ptr1;
    }

    while(ptr2->next != head){
        ptr1->next = rev;
        rev = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }
    ptr1->next = rev;
    ptr2->next = ptr1;
    head->next = ptr2;
    (*tail) = head;
    return ptr2;
}

int main(){
    cnode* head = NULL;
    cnode* tail = NULL;
    int del,ch,key,pos;
    while(1){
        printf("Enter 1 to insert at beginning\nEnter 2 to insert at end\nEnter 3 to insert at pos\nEnter 4 to delete from begin\nEnter 5 to delete from end\nEnter 6 to delete from pos\nEnter 7 to display\nEnter 8 to reverse the list\nEnter 9 to exit\n\n");
        scanf("%d",&ch);
        if(ch==9){
            break;
        }
        switch(ch){
            case 1 : printf("Enter value to insert\n");
                     scanf("%d",&key);
                     head = insertAtBegin(head,&tail,key);
                     break;

            case 2 : printf("Enter value to insert\n");
                     scanf("%d",&key);
                     head = insertAtEnd(head,&tail,key);
                     break;

            case 3 : printf("Enter value to insert\n");
                     scanf("%d",&key);
                     printf("Enter position to insert\n");
                     scanf("%d",&pos);
                     head = insertAtPos(head,&tail,key,pos);
                     break;

            case 4  : head = deleteAtBegin(head,&tail,&del);
                      if(del!=-9999){
                        printf("Deleted key is %d\n",del);
                      }
                      break;

            case 5  : head = deleteAtEnd(head,&tail,&del);
                      if(del!=-9999){
                        printf("Deleted key is %d\n",del);
                      }
                      break;

            case 6 : printf("Enter position to delete\n");
                     scanf("%d",&pos);
                     head = deleteAtPos(head,&tail,&del,pos);
                     if(del!=-9999){
                        printf("Deleted key is %d\n",del);
                     }
                     break;

            case 7 : display(head);
                     break;

            case 8 : head = reverseCList(head,&tail);
                     break;

            default : printf("Invalid choice\n");
        }
    }
    return 0;
}