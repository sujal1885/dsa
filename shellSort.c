#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shellSort(int* arr,int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap+1;i<n;i++){
            int key=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>key;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=key;
        }
    }
}

int main(){
   int arr[200000];
   for(int i=0;i<200000;i++){
      arr[i]=200000-i;
   }
   shellSort(arr,200000);
   for(int i=0;i<200000;i++){
      printf("%d ",arr[i]);
   }
   return 0;
}