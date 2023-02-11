#include <stdio.h>
#include <stdlib.h>

struct node{
    int constant;
    int power;
    struct node* next;
};


typedef struct node list;

list* createNode(){
    list* temp = (list*)malloc(sizeof(list));
    temp->next = NULL;
    return temp;
}

list* insertEnd(list* FIRST,int c,int p){
    list* new = createNode();
    new->constant = c;
    new->power = p;
    new->next = NULL;
    if(FIRST == NULL) return new;
    list* temp = FIRST;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
    return FIRST;
}

list* add(list* A,list* B){
    list* C = NULL;
    list* temp1 = A;
    list* temp2 = B;
    while(temp1 && temp2){
        if(temp1->power > temp2->power){
            C = insertEnd(C,temp1->constant,temp1->power);
            temp1 = temp1->next;
        }
        else if(temp1->power < temp2->power){
            C = insertEnd(C,temp2->constant,temp2->power);
            temp2 = temp2->next;
        }
        else{
            C = insertEnd(C,temp1->constant+temp2->constant,temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    
    while(temp1){
        C = insertEnd(C,temp1->constant,temp1->power);
        temp1 = temp1->next;
    }
    
    while(temp2){
        C = insertEnd(C,temp2->constant,temp2->power);
        temp2 = temp2->next;
    }
    return C;
}

void display(list* P){
    if(P == NULL){
        printf("The list is empty\n");
        return;
    }
    list* temp = P;
    while(temp){
        printf("%d--%d   ",temp->constant,temp->power);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    list* A = NULL;
    list* B = NULL;
    int n1,n2;
    printf("Enter the number of terms in expression A\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        int c , p;
        printf("Enter the constant term\n");
        scanf("%d",&c);
        printf("Enter the power term\n");
        scanf("%d",&p);
        A = insertEnd(A,c,p);
    }
    
    
    printf("Enter the number of terms in expression B\n");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        int c , p;
        printf("Enter the constant term\n");
        scanf("%d",&c);
        printf("Enter the power term\n");
        scanf("%d",&p);
        B = insertEnd(B,c,p);
    }
    
    list* c = add(A,B);
    display(A);
    display(B);
    display(c);
    return 0;
}
