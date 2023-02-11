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
     if(binarySearch(A,num)==-1){
        printf("Number is not present in the array.\n");
     }
     else 
         printf("The entered number is present at location %d ",binarySearch(A,num));
   }
   return 0;
}