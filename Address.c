#include <stdio.h>
int main(){
   int arr[2][3];
   int a[6];
   printf("Enter six digits : \n");
   for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
        scanf("%d",&arr[0][0]+(i+j*2));
    }
   }
   for(int i=0;i<6;i++){
        printf("%d ",*(&arr[0][0]+i));
   }
   printf("\n");
   for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
   }
   return 0;
}