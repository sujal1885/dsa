#include<stdio.h>
#include<stdlib.h>

int main(){
    int* ptr;
    ptr=(int*)malloc(sizeof(int)*5);
    printf("%d",sizeof(ptr)/sizeof(ptr[0]));
    return 0;
}