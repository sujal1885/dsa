#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * create_node(int ele){
    struct node * p=(struct node *)malloc(sizeof(struct node));
    p->data=ele;
    p->next=NULL;
}
void traverse(struct node * head){
    struct node * p=head;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){

    struct node * head=create_node(12);
    struct node * second=create_node(13);
    struct node * third=create_node(14);
    struct node * head2=create_node(15);
    struct node * second2=create_node(16);
    struct node * third2=create_node(17);

    head->next=second;
    second->next=third;
    third->next=NULL;
    head2->next=second2;
    second2->next=third2;
    third2->next=NULL;
    printf("Linked list 1:\n");
    traverse(head);
    printf("Linked list 2:\n");
    traverse(head2);
    printf("Combined linked list.\n");
    third->next=head2;
    traverse(head);
    return 0;





}