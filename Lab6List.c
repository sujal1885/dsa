#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node list;

list* createNode(){
    list* temp = (list*)malloc(sizeof(list));
    temp->next=NULL;
    return temp;
}

list* bubbleSort(list*a){
    if(a==NULL || a->next==NULL) return a;
    while(1){
        int b = -1;
        list* temp = a;
        while(temp->next!=NULL){
            if(temp->data > temp->next->data){
                b = 1;
                int tempo = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempo;
            }
            temp = temp->next;
        }
        if(b == -1) break;
    }
    return a;
}

list* sortList(list* a,list* b){
    a = bubbleSort(a);
    b = bubbleSort(b);

    list* c = NULL;
    list* tail = NULL;

    list* temp1 = a;
    list* temp2 = b;

    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            list* temp = createNode();
            temp -> data = temp1->data;
            if(c == NULL){
                c = temp;
                tail = temp;
            }
            else{
                tail -> next = temp;
                tail = tail->next;
            }
            temp1 = temp1->next;
        }
        else{
            list* temp = createNode();
            temp -> data = temp2->data;
            if(c == NULL){
                c = temp;
                tail = temp;
            }
            else{
                tail -> next = temp;
                tail = tail->next;
            }
            temp2 = temp2->next;
        }
    }
    while(temp1){
        list* temp = createNode();
        temp -> data = temp1->data;
        if(c == NULL){
                c = temp;
                tail = temp;
        }
        else{
                tail -> next = temp;
                tail = tail->next;
        }
        temp1 = temp1->next;
    }

    while(temp2){
        list* temp = createNode();
        temp -> data = temp2->data;
        if(c == NULL){
            c = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = tail->next;
        }
        temp2 = temp2->next;
    }
    return c;
}

void display(list* ptr){
    if(ptr==NULL){
        printf("The list is empty\n");
        return;
    }
    printf("The list contents are \n");
    list* temp = ptr;
    while(temp){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
}

int main(){
   list* a=NULL;
   list* b=NULL;
   int n1,n2;

   printf("Enter the number of elements in list a\n");
   scanf("%d",&n1);
   printf("Enter the stream of integers for list a\n");
   list* tail;
   for(int i=0;i<n1;i++){
      list* temp = createNode();
      scanf("%d",&temp->data);
      temp->next = NULL;
      if(i==0){
        a = temp;
        tail = a;
      }
      else{
        tail->next = temp;
        tail = tail->next;
      }
   }

   printf("Enter the number of elements in list b\n");
   scanf("%d",&n2);
   printf("Enter the stream of integers for list b\n");
   for(int i=0;i<n2;i++){
      list* temp = createNode();
      scanf("%d",&temp->data);
      temp->next = NULL;
      if(i==0){
        b = temp;
        tail = b;
      }
      else{
        tail->next = temp;
        tail = tail->next;
      }
   }

   list *c = sortList(a,b);
   printf("The sorted list is \n");
   display(c);

   return 0;
}