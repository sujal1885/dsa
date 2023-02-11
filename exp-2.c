// To study array ADT and matrix operations
//include display array in row major and column major form , finding transpose , matrix addition and matrix multiplication
// By sujal Agrawal
#include<stdio.h>
#include<stdlib.h>
struct array2DADT{
    int** arr;
    int rows;
    int cols;
};

void rowmajor(struct array2DADT *mat){
    printf("Enter stream of %d integers : \n",mat->rows*mat->cols);
    for(int i=0;i<mat->rows;i++){
        for(int j=0;j<mat->cols;j++){
          scanf("%d",&mat->arr[0][0]+(i*mat->cols+j));
          printf("%d\n%d",&mat->arr[0][0]+(i*mat->cols+j),&mat->arr[i][j]);
        }
    }
}

void colmajor(struct array2DADT *mat){
    printf("Enter stream of %d integers : \n",mat->rows*mat->cols);
    for(int i=0;i<mat->rows;i++){
        for(int j=0;j<mat->cols;j++){
           scanf("%d",&mat->arr[0][0]+(i+j*mat->rows));
        }
    }
}

void printCol(struct array2DADT mat){
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            printf("%d ",mat.arr[i][j]);
        }
        printf("\n");
    }
}

void print(struct array2DADT mat){
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
           printf("%d ",mat.arr[i][j]);
        }
        printf("\n");
    }
}

void transpose(struct array2DADT mat){
    for(int i=0;i<mat.cols;i++){
        for(int j=0;j<mat.rows;j++){
           printf("%d ",mat.arr[j][i]);
        }
        printf("\n");
    }
}

void additionMat(struct array2DADT mat1,struct array2DADT mat2){
    if(mat1.rows!=mat2.rows || mat2.cols!=mat2.cols){
        printf("Matrices can't be added.\n");
    }
    else{
        printf("The resultant matrix is:\n");
        for(int i=0;i<mat1.rows;i++){
        for(int j=0;j<mat1.cols;j++){
           printf("%d ",mat1.arr[i][j]+mat2.arr[i][j]);
        }
        printf("\n");
    }
    }
}

void mulMat(struct array2DADT mat1,struct array2DADT mat2){
    if(mat1.cols != mat2.rows){
        printf("Matrix can't be multiplied:\n");
    }
    else{
        for(int i=0;i<mat1.rows;i++){
            for(int j=0;j<mat1.cols;j++){
                int ans=0;
                for(int k=0;k<mat1.cols;k++){
                    ans+=mat1.arr[i][k]*mat2.arr[k][j];
                }
                printf("%d ",ans);
            }
            printf("\n");
        }
    }
}



int main(){
    struct array2DADT mat1;
    struct array2DADT mat2;
    printf("For matrix 1 : \n");
    printf("Enter number of rows : \n");
    scanf("%d",&mat1.rows);
    printf("Enter number of cols : \n");
    scanf("%d",&mat1.cols);
    if(mat1.rows>=20 || mat1.cols>=20 || mat1.rows<=0 || mat1.cols<=0){
        printf("Dimensions out of bounds!\n");
        exit(0);
    }
    
    // mat1.arr = (int**)malloc(sizeof(int[mat1.rows][mat1.cols]));
    //  mat1.arr = (int**)malloc(mat1.rows * sizeof(int*));
    // for (int i = 0; i < mat1.rows; i++)
    //     mat1.arr[i] = (int*)malloc(mat1.cols * sizeof(int));
    int len = sizeof(int *) * mat1.rows + sizeof(int) * mat1.cols * mat1.rows;
    mat1.arr = (int **)malloc(len);
 
    // ptr is now pointing to the first element in of 2D array
    int* ptr = (int *)(mat1.arr + mat1.rows);
 
    // for loop to point rows pointer to appropriate location in 2D array
    for(int i = 0; i < mat1.rows; i++)
        mat1.arr[i] = (ptr + mat1.cols * i);
    rowmajor(&mat1);
    printf("The matrix in row major form is : \n");
    print(mat1);
    printf("The transpose of matrix 1 is : \n");
    transpose(mat1);
    
    printf("For matrix 2 : \n");
    printf("Enter number of rows : \n");
    scanf("%d",&mat2.rows);
    printf("Enter number of cols : \n");
    scanf("%d",&mat2.cols);
    if(mat2.rows>=20 || mat2.cols>=20 || mat2.rows<=0 || mat2.cols<=0){
        printf("Dimensions out of bounds!\n");
        exit(0);
    }
     len = sizeof(int *) * mat2.rows + sizeof(int) * mat2.cols * mat2.rows;
    mat2.arr = (int **)malloc(len);
 
    // ptr is now pointing to the first element in of 2D array
     ptr = (int *)(mat2.arr + mat2.rows);
 
    // for loop to point rows pointer to appropriate location in 2D array
    for(int i = 0; i < mat2.rows; i++)
        mat2.arr[i] = (ptr + mat2.cols * i);
    
        // mat2.arr = (int**)malloc(sizeof(int[mat2.rows][mat2.cols]));

    colmajor(&mat2);
    printf("The matrix in column major form is : \n");
    printCol(mat2);
    printf("The transpose of matrix 2 is : \n");
    transpose(mat2);
    
    printf("The addition of matrix one and two is :\n");
    additionMat(mat1,mat2);
    
    printf("The multiiplication of matrix 1 and 2 is :\n");
    mulMat(mat1,mat2);
    
    return 0;
}
