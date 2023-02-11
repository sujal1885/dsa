/*
    Merge sort code
    By sujal Agrawal
    Date: 25/12/2022
    After testing I came to the conclusion that mergeSort is the fastest sort.
*/

#include<stdio.h>
#include<stdlib.h>

void merge(int *ptr,int p,int q,int r){
    int N1=q-p+1;
    int N2=r-q;
    int *L,*R;
    L=(int*)malloc(sizeof(int)*(N1+1));
    R=(int*)malloc(sizeof(int)*(N2+1));
    for(int i=0;i<N1;i++) L[i]=ptr[p+i];
    for(int j=0;j<N2;j++) R[j]=ptr[q+j+1];
    L[N1]=1e9;
    R[N2]=1e9;
    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<R[j]){
            ptr[k]=L[i];
            i++;
        }
        else{
            ptr[k]=R[j];
            j++;
        }
    }
}

void MergeSort(int *ptr,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        MergeSort(ptr,p,q);
        MergeSort(ptr,q+1,r);
        merge(ptr,p,q,r);
    }
}

int main(){
    int n;
    int *ptr;
    printf("Enter size: ");
    scanf("%d",&n);
    ptr=(int*)malloc(sizeof(int)*n);
    printf("\nEnter stream of integers : ");
    for(int i=0;i<n;i++) scanf("%d",&ptr[i]);
    MergeSort(ptr,0,n-1);
    printf("\nThe sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d  ",ptr[i]);
    }
    printf("\n");
    return 0;
}