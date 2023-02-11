#include<stdio.h>
int size=0;
void insertAtPos(int *arr,int num,int pos){
    for(int i=size;i>pos;i-- ){
        arr[i]=arr[i-1];
    }  
    arr[pos]=num;
    size++;
}
void insert(int *arr,int num){
    arr[size]=num;
    size++;
}
void delete(int *arr,int pos){
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
void search(int *arr,int num){
    for(int i=0;i<size;i++){
        if(num==arr[i])
            printf("The element %d is present at position %d\n",num,i);
    }
}
void selectionSort(int *arr){
   int min;
   for(int i=0;i<size-1;i++){
       min=i;
       for(int j=i;j<size;j++){
           if(arr[j]<arr[min])
               min=j;
       }
       int temp=arr[i];
       arr[i]=arr[min];
       arr[min]=temp;
   }
}
int main(){
    int arr[15];
    
    while(1){
    printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to search\nEnter 4 to sort\nEnter 5 to print\nEnter 6 to insert num at particular position\nEnter 7 to exit\n");
    int x;
    scanf("%d",&x);
    if(x==7) break;
    switch(x){
        case 1 :
            printf("Enter number to insert\n");
            int num;
            scanf("%d",&num);
            insert(arr,num);
            break;
       case 2 :
           printf("Enter the position of the element to be deleted\n");
           int pos;
           scanf("%d",&pos);
           delete(arr,pos);
           break;
       case 3 :
           printf("Enter the element to be searched\n");
           int elem;
           scanf("%d",&elem);
           search(arr,elem);
           break;
       case 4 :
           selectionSort(arr);
       case 5 : 
           for(int i=0;i<size;i++) printf("%d ",arr[i]);
           printf("\n");
           break;
       case 6 : 
           printf("Enter the element and the position to be inserted\n");
           int n,p;
           scanf("%d%d",&n,&p);
           insertAtPos(arr,n,p);
           break;    
       default : printf("Invalid input");                     
    }
    }
    return 0;
}
