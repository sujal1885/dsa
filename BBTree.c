/*
    Builiding binary trees
    By sujal Agrawal,
    Mentor : Prof. D. A. Borikar sir
    Date : 06 / 02 / 2023
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000000   // maximum value

struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode Tree;

Tree* createTreeNode(){
    Tree* ptr=NULL;
    ptr = (Tree*)malloc(sizeof(Tree));
    ptr->left = NULL;
    ptr->right = NULL;
}

int max(int a,int b){
    if(a<b) return b;
    return a;
}

int len(int* arr){   // returns the length of array
    int index = 0;
    while(arr[index]!=MAX_VAL){
        index++;
    }
    return index;
}

int getLeftChild(int* arr,int len,int index){
    if(2*index+1>=len){
        return len;
    }
    return 2*index+1;
}

int getRightChild(int* arr,int len,int index){
    if(2*index+2>=len){
        return len;
    }
    return 2*index+2;
}

Tree* buildBinaryTree(int* arr,int len,int index){
    Tree* T = NULL;
    if(arr[index]==MAX_VAL) return T; // if the index is out of bounds return null
    if(arr[index]!=-1){
        T = createTreeNode();
        T->left = buildBinaryTree(arr,len,getLeftChild(arr,len,index));
        T->data = arr[index];
        T->right = buildBinaryTree(arr,len,getRightChild(arr,len,index));
    }
    return T;
}

void PreOrder(Tree* root){
    if(!root){
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void Inorder(Tree* root){
    if(!root){
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void PostOrder(Tree* root){
    if(!root){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

int heightBinTree(Tree* root){  // calculates height of tree
    if(!root){
        return -1; // if no node is present , no height , hence -1
    }
    if(root->left == NULL && root->right==NULL){
        return 0; // single node has a height of zero
    }
    return max(heightBinTree(root->left),heightBinTree(root->right))+1; // height is maximum calcaluted
}

int parents(Tree* root){ // counts number of parent node and prints them
    if(!root || (root->left==NULL && root->right==NULL)){
        return 0; // no nodes or leaf nodes
    }
    printf("%d ",root->data); // else it is a parent node
    return parents(root->left)+parents(root->right)+1;
}

int allNodes(Tree* root){ // counts and print all the elements of the tree
    if(!root){
        return 0; // no nodes
    }
    printf("%d ",root->data);
    return 1+allNodes(root->left)+allNodes(root->right);
}

void emptyTree(Tree* root){
    if(root!=NULL){
        emptyTree(root->left);
        emptyTree(root->right);
        printf("Deleted Node with value %d\n",root->data);
        free(root);
    }
}

int main(){
    Tree* root = NULL;
    int* arr = NULL;
    int n;
    printf("Please enter the size of the array\n");
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*(n+1));
    printf("Enter the elements of the array , enter -1 if node is not present\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arr[n] = MAX_VAL;
    int length = len(arr);
    root = buildBinaryTree(arr,length,0);
    PreOrder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    printf("The height of the binary tree is %d\n",heightBinTree(root));
    printf("The parents node are \n");
    int par = parents(root);
    printf("The total number of parents node is %d\n",par);
    printf("All nodes are\n");
    int cnt = allNodes(root);
    printf("The total number of nodes in tree is %d\n",cnt);
    emptyTree(root);
    // Inorder(root);
    return 0;
}