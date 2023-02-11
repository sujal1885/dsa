#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* countingSort(int *arr,int k,int n,int* sorted){
   int knt=0;
   int KOUNT[k+1];
   for(int i=0;i<=k;i++){
      KOUNT[i]=0;
   }
   for(int i=0;i<n;i++){
      KOUNT[arr[i]]=KOUNT[arr[i]]+1;
   }
   for(int i=1;i<=k;i++){
      KOUNT[i]=KOUNT[i]+KOUNT[i-1];
   }
   for(int i=n-1;i>=0;i--){
      sorted[KOUNT[arr[i]]-1]=arr[i];
      KOUNT[arr[i]]=KOUNT[arr[i]]-1;
   }
   return sorted;
}

int main(){
   int n;
   printf("Enter the number of elements in array : \n");
   scanf("%d",&n);
   int arr[n];
   int maxi=-1;
   int negative=-1;
   printf("Enter stream of numbers : \n");
   for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
      if(arr[i]>maxi)
          maxi=arr[i];
      if(arr[i]<0)
          negative=1;
   }
   if(negative==1){
      printf("Please enter only positive values. Program terminating.\n");
   }
   else{
      int ptr[n];
      countingSort(arr,maxi,n,ptr);
      for(int i=0;i<n;i++){
         printf("%d ",ptr[i]);
      }
      printf("\n");
   }
   
   return 0;
}