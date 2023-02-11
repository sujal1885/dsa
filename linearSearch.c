#include <stdio.h>

struct arrayAdt {
    int arr[100];
    int n;
    int size;
};
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
     if(linearSearch(A,num)==-1){
        printf("Number is not present in the array.\n");
     }
     else 
         printf("The entered number is present at location %d ",linearSearch(A,num));
   }
   return 0;
}