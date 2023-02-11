/*
    Graph Traversal
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

typedef struct node list;

list* createNode(){
    list* temp;
    temp=(list*)malloc(sizeof(list));
    return temp;
}

list* push(int ele,list* First){
    list* temp=createNode();
    if(temp==NULL){
        printf("Memory unavailable\n");
        return NULL;
    }

    temp->data=ele;
    temp->link=First;

    return temp;
}

list* pop(list* First){
    if(First==NULL){
        printf("Stack is empty\n\n");
        return NULL;
    }

    list* temp;
    temp=First;
    First=First->link;
    free(temp);

    return First;
}

int peek(list* First){
    if(First==NULL){
        printf("Stack is empty\n\n");
        return -9999;
    }

    return First->data;
}

struct node1
{
    int data;
    struct node1* link1;
};

typedef struct node1 list1;

list1* createqNode()
{
    list1 *temp;
    temp = (list1*)malloc(sizeof(list1));
    return temp;
}

list1* insert(list1* First, list1* Tail, int ele)
{
    list1* temp;
    temp = createqNode();
    if (temp == NULL)
    {
        printf("No memory available.\n");
        return NULL;
    }

    temp->data = ele;
    temp->link1 = NULL;

    

    return temp;
}

list1* delete(list1* First, list1* Tail,int* del)
{
    if (First == NULL)
    {
        printf("queue is empty\n");
        *del=-9999;
        return NULL;
    }
    *del = First->data;
    list1* temp = First;
    First = First->link1;
    free(temp);

    if (First == NULL)
    {
        Tail = NULL;
    }

    return First;
}

void isEmpty(list1 *First)
{
    if (First == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue is not empty\n");
}

int frontVal(list1 *First)
{
    if (First == NULL)
    {
      //  printf("queue is empty\n");
        return -1;
    }
    //printf("front value = %d\n", First->data);
    return First->data;
}

void rearVal(list1 *Tail)
{
    if (Tail == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    printf("Rear value = %d\n", Tail->data);
}

void dfs(int graph[][20],int visited[],list* stack,int source,int v){
    while(stack!=NULL){
        int top = peek(stack);
        if(visited[top]==1) {
            stack = pop(stack);
            continue;
        }
        printf("%d ",top);
        visited[top] = 1;
        stack = pop(stack);
        for(int i=0;i<v;i++){
		if(graph[top][i]==1 && visited[i]==0){
		    stack = push(i,stack);
		}
      }
    }
}

void bfs(int graph[][20],int visited[],int source,int v){
    int del;
    list1* First;
    list1* Tail;
    First = Tail = NULL;
    visited[source] = 1;
    if(Tail==NULL)
        Tail=insert(First, Tail, source);
    else{
        Tail->link1=insert(First,Tail,source);
        Tail=Tail->link1;
     }
     if(First==NULL) First=Tail;
     printf("%d ",source);
     while(First!=NULL){
         int f = frontVal(First);
         First = delete (First, Tail,&del);
         if(First==NULL) Tail=NULL;
         int vnt = 0;
         while(vnt<v){
             if(graph[f][vnt]==1 && visited[vnt]==0){
                 visited[vnt] = 1;
                 printf("%d ",vnt);
                 if(Tail==NULL)
		    Tail=insert(First, Tail, vnt);
		 else{
		    Tail->link1=insert(First,Tail,vnt);
		     Tail=Tail->link1;
		    }
		  if(First==NULL) First=Tail;
             }
             vnt++;
         }  
     }
     
}

int main(){
    int v;
    printf("Enter the number of nodes in the graph\n");
    scanf("%d",&v);
    int visited[v];
    list* stack = NULL;
    int graph[20][20];
    printf("Enter the adjacency matrix\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    while(1){
        printf("Enter 1 for dfs\nEnter 2 for bfs\nEnter 3 to exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==3) break;
        switch(ch){
            case 1: printf("DFS Traversal is\n");
                    for(int i=0;i<v;i++){
                    visited[i]=0;
                  }
                  stack=push(0,stack);
                  dfs(graph,visited,stack,0,v);
                  printf("\n");
                  break;

            case 2: printf("BFS Traversal is\n");
                    for(int i=0;i<v;i++){
                    visited[i]=0;
                  }
                  bfs(graph,visited,0,v);
                  printf("\n");
                  break;

            default: printf("Invalid key\n");
                    
        }
    }    
    return 0;
}
