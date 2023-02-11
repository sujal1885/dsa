#include <stdio.h>

struct arrayAdt {
    int arr[100];
    int n;
    int size;
};
void sort(struct arrayAdt* A){
    for(int i=0;i<A->n-1;i++){
        for(int j=0;j<A->n-i-1;j++){
            if(A->arr[j]>A->arr[j+1]){
                int temp=A->arr[j];
                A->arr[j]=A->arr[j+1];
                A->arr[j+1]=temp;
            }
        }
    }
}
int binarySearch(struct arrayAdt A,int num){
    sort(&A);
    int l=0,r=A.n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(num<A.arr[mid]){
            r=mid-1;
        }
        else if(num>A.arr[mid]){
            l=mid+1;
        }
        else
            return mid;
    }
    return -1;
}
int linearSearch(struct arrayAdt A,int num){
    int i;
    for(i=0;i<A.n;i++){
        if(A.arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
   struct arrayAdt A;
   A.size=100;
   printf("Enter the number of elements present in the array : \n");
   scanf("%d",&A.n);
   if(A.n>A.size){
    printf("The size entered is too high.");
   }
   else{
     printf("start Entering the numbers : \n");
     for(int i=0;i<A.n;i++){
        scanf("%d",&A.arr[i]);
     }
     printf("\nEnter the element to be searched : \n");
     int num;
     scanf("%d",&num);
     int choice;
     printf("Enter 1 for linear search and 2 for binary search.\n");
     scanf("%d",&choice);
     if(choice==1){
            if(linearSearch(A,num)==-1){
                printf("Number is not present in the array.\n");
            }
            else 
            printf("The entered number is present at location %d ",linearSearch(A,num));
     }
     else if(choice==2){
        if(binarySearch(A,num)==-1){
                printf("Number is not present in the array.\n");
            }
            else 
            printf("The entered number is present at location %d ",binarySearch(A,num));
     }
     else{
        printf("Invalid choice\n");
     }
     
   }
   return 0;
}