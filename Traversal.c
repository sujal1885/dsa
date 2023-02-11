/* 
   Tree Traversal
   By sujal Agrawal
   Date : 09/02/2023
   Mentor : Rina Ma'am
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode Tree;

Tree* createTreeNode(){
    Tree* ptr=NULL;
    ptr = (Tree*)malloc(sizeof(Tree));
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int max(int a,int b){
    if(a<b) return b;
    return a;
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

Tree* insertBst(Tree* root,int key){
    if(!root){
        Tree* neww = createTreeNode();
        if(neww==NULL){
            printf("Memory unavailable\n"); // if stack is not having memory
            return NULL;
        }
        neww->data = key;
        neww->left = NULL;
        neww->right = NULL;
        return neww;
    }
    else if(key<root->data){
        root->left = insertBst(root->left,key);
    }
    else if(key>root->data){
        root->right = insertBst(root->right,key);
    }
    else{
        printf("Can't insert duplicate key\n");
    }
    return root;
}

Tree* minNode(Tree* root){
    if(root->left == NULL){
        return root;
    }
    return minNode(root->left);
}

Tree* deleteNode(Tree* root,int key){
    if(!root){
        printf("Delete failed , required node is not present\n");
        return NULL;
    }
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left!=NULL && root->right!=NULL){ // if node has both the children
            Tree* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,root->data);
        }
        else{  // if node has single children
            Tree* temp = root;
            if(root->left == NULL){
                root=root->right;
                free(temp);
            }
            else if(root->right == NULL){
                root=root->left;
                free(temp);
            }
            else{
                free(temp);
                return NULL;
            }
        }
    }
    return root;
}

int main(){
Tree* root = NULL;
    int key,ch,par,cnt;
    while(1){
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 for preorder\nEnter 4 for inorder\nEnter 5 for postorder\nEnter 6 to exit\n");
        scanf("%d",&ch);
        if(ch==6){
            break;
        }
        switch(ch){
            case 1 : printf("Enter the value to insert\n");
                     scanf("%d",&key);
                     root = insertBst(root,key);
                     break;

            case 2 : printf("Enter the value to delete\n");
                     scanf("%d",&key);
                     root = deleteNode(root,key);
                     break;

            case 3 : PreOrder(root);
                     printf("\n");
                     break;

            case 4 : Inorder(root);
                     printf("\n");
                     break;

            case 5 : PostOrder(root);
                     printf("\n");
                     break;
            
            default : printf("Invalid choice\n");
                      break;
        }
    }
    return 0;
}
