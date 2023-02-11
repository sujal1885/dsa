#include <stdio.h>
#include <stdlib.h>

int partition(int *arr,int p,int r){
    int i=p-1;
    int j=p;
    int pivot=arr[r];
    for(j=p;j<r;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=pivot;
    arr[r]=temp;
    return i+1;
}

void quickSort(int*arr,int p,int r){
    if(p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}
int main(){
   int arr[200000];
   for(int i=0;i<200000;i++){
      arr[i]=200000-i;
   }
   quickSort(arr,0,199999);
   for(int i=0;i<200000;i++){
      printf("%d ",arr[i]);
   }
   return 0;
}