#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

#define MAX(a,b) ((a) > (b)?(a):(b))

typedef char Telement;

typedef struct TreeNode{
    Telement data;
    struct TreeNode* left;
    struct TreeNode* right;
    
}TreeNode;


TreeNode* makeNode(Telement data, TreeNode* left, TreeNode* right){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    
    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

void preOrder(TreeNode* root){
    if(root != NULL){
        printf("[%c] ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root){
    if(root != NULL){
        inOrder(root->left);
        printf("[%c] ", root->data);
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("[%c] ", root->data);
    }
}

bool isExternal(TreeNode* node){
    return (node->left == NULL) && (node->right == NULL);
}



int countNode(TreeNode* root){
    if(root == NULL){
        return 0;
    }else{
        return countNode(root->left) + countNode(root->right) + 1;
    }
}


int countleafNode(TreeNode* root){
    if(root == NULL){
        return 0;
    }else{
        if(isExternal(root)){
            return 1;
        }else{
            return countleafNode(root->left) + countleafNode(root->right);
        }
    }
}

int height(TreeNode* root){
    if (root == NULL){
        return 0;
    }else{
        return 1 + MAX(height(root->left), height(root->right));
    }
}

void treeReverse(TreeNode* root){
    if(root != NULL){
        TreeNode* tmp;
     
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
     
        treeReverse(root->left);
        treeReverse(root->right);
    }
}

int main(){

    TreeNode* nodes[7];

    nodes[6] = makeNode('F', NULL, NULL);
    nodes[5] = makeNode('E', nodes[6], NULL);
    nodes[4] = makeNode('D', NULL, NULL);
    nodes[3] = makeNode('C', NULL, NULL);
    nodes[2] = makeNode('B', nodes[4], nodes[5]);
    nodes[1] = makeNode('A', nodes[2], nodes[3]);

    TreeNode* root = nodes[1];

    printf("Pre: ");
    preOrder(nodes[1]);
    printf("\n");

    printf("In: ");
    inOrder(nodes[1]);
    printf("\n");

    printf("Post: ");
    postOrder(nodes[1]);
    printf("\n\n");
    
    printf("Node Count: %d\n", countNode(root));
    printf("leaf count: %d\n", countleafNode(root));
    printf("height: %d", height(root));

    treeReverse(root);

    printf("Pre: \n");
    preOrder(nodes[1]);
    printf("\n");


}