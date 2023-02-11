#include <stdio.h>
void insertion_sort(int *arr,int s){
    int key,j;
    for(int i=1;i<s;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}
int main(){
   int arr[200000];
   for(int i=0;i<200000;i++){
      arr[i]=200000-i;
   }
   insertion_sort(arr,200000);
   for(int i=0;i<200000;i++){
      printf("%d ",arr[i]);
   }
   return 0;
}