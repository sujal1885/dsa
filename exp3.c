/*
    Stacks 
    By Sujal Agrawal
*/
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int st[10];
    int top;
    int size;
};

int isfull(struct stack* sk){
    if(sk->top==sk->size-1)
        return 1;
    return 0;    
}

int isempty(struct stack* sk){
    if(sk->top==-1)
        return 1;
    return 0;    
}

void push(struct stack* sk){
    printf("Enter the value to push:\n");
    int val;
    scanf("%d",&val);
    sk->top++;
    sk->st[sk->top]=val;
}

int pop(struct stack* sk){
    int x=sk->st[sk->top];
    sk->top--;
    return x;
}

int peek(struct stack* sk){
    return sk->st[sk->top];
}

void display(struct stack* sk){
    printf("The stack elements are:\n");
    for(int i=sk->top;i>=0;i--){
        printf("%d\n",sk->st[i]);
    }
}



int main(){
    int n;
    printf("Enter the maximum size of the stack :\n");
    scanf("%d",&n);
    if(n>5){
        printf("Size is more than allowed. Please values upto 5.\n");
        exit(0);
    }
    struct stack sk;
    sk.top=-1;
    sk.size=n;
    while(1){
        printf("Enter 1 for push.\nEnter 2 for pop.\nEnter 3 for peek.\nEnter 4 for display.\nEnter 5 to exit.\n");
        int ch;
        scanf("%d",&ch);
        if(ch==5){
             break;
        }
        switch(ch){
            case 1: if(isfull(&sk)){
                       printf("The stack is full.Can't push the element.\n");
                    }
                    else 
                        push(&sk);
                    break;
           case 2: if(isempty(&sk)){
                       printf("The stack is empty.Can't pop.\n");
                   }
                   else{
                       int x=pop(&sk);
                       printf("The popped element is %d\n",x);
                    }
                   break;   
           case 3: 
                   if(isempty(&sk)){
                       printf("The stack is empty.Can't give the peek element.\n");
                   }
                   else{
                       int p=peek(&sk);
                       printf("The top element is %d\n",p);
                   }
                   break;
           case 4: display(&sk);
           default : printf("Please enter valid key.\n");                               
        }
    }
    return 0;
}

