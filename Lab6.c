#include <stdio.h>
#include <stdlib.h>

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


int* mergeArr(int* a,int* b,int n1,int n2){
    int* c = (int*)malloc(sizeof(int)*(n1+n2));
    MergeSort(a,0,n1-1);
    MergeSort(b,0,n2-1);
    int i=0,j=0;
    int k=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=b[j++];
        }
    }
    while(i<n1){
        c[k++]=a[i++];
    }
    while(j<n2){
        c[k++]=b[j++];
    }
    return c;
}

int main(){
   int* a=NULL;
   int* b=NULL;

   int n1,n2;

   printf("Enter the size of the array a\n");
   scanf("%d",&n1);
   a=(int*)malloc(sizeof(int)*n1);
   printf("Enter the stream of integers for a\n");
   for(int i=0;i<n1;i++){
      scanf("%d",&a[i]);
   }


   printf("Enter the size of the array b\n");
   scanf("%d",&n2);
   b=(int*)malloc(sizeof(int)*n2);
   printf("Enter the stream of integers for b\n");
   for(int i=0;i<n2;i++){
      scanf("%d",&b[i]);
   } 

    int* c = mergeArr(a,b,n1,n2);
    printf("The sorted array is\n");
    for(int i=0;i<n1+n2;i++){
        printf("%d  ",c[i]);
    }
    printf("\n");

   return 0;
}