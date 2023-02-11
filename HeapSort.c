/*
    Heap Sort 
    By sujal Agrawal
    Date : 27/12/2022
    Feeling sick , but still can't stop to code 
    conclusion : It is very much faster , little slower than merge sort for big input size
*/

#include<stdio.h>
#include<stdlib.h>

int globalLength;

int Parent(int i){
    return (i-1)/2;
}

int Left(int i){
    return 2*i+1;
}

int Right(int i){
    return 2*i+2;
}

void heapify(int* arr,int i,int heapSize){
    int L=Left(i);
    int R=Right(i);
    int largest;

    if(L<heapSize && arr[L]>arr[i]){
        largest=L;
    }
    else{
        largest=i;
    }

    if(R<heapSize && arr[R]>arr[largest]){
        largest=R;
    }

    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,largest,heapSize);
    }
}

void buildHeap(int* arr,int* heapSize){
    *heapSize=globalLength;
    for(int i=*heapSize/2-1;i>=0;i--){
        heapify(arr,i,*heapSize);
    }
}

void heapSort(int *arr){
    int heapSize;
    buildHeap(arr,&heapSize);
    for(int i=globalLength-1;i>=1;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapSize--;
        heapify(arr,0,heapSize);
    }
}

int main(){
    int n;
    int *ptr;
    printf("Enter size: ");
    scanf("%d",&n);
    globalLength=n;
    ptr=(int*)malloc(sizeof(int)*n);
    printf("\nEnter stream of integers : ");
    for(int i=0;i<n;i++) scanf("%d",&ptr[i]);
    heapSort(ptr);
    printf("\nThe sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d  ",ptr[i]);
    }
    printf("\n");
    return 0;
}