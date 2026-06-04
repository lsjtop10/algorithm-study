#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

#define MAX(a, b) (a > b ? a : b)

typedef int TElement;

typedef struct TreeNode {
    TElement data;

    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* makeNode(TElement key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    node->data = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // 무작적 더하면 안 되고 왼쪽과 오른쪽의 최댓값을 더해야 함.
    return 1 + MAX(getHeight(root->left), getHeight(root->right));
}

int caculateBalance(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

TreeNode* rotateLeft(TreeNode* root) {

    TreeNode* rChild = root->right;

    root->right = rChild->left;
    rChild->left = root;

    return rChild;
}

TreeNode* rotateRight(TreeNode* root) {

    TreeNode* lChild = root->left;

    root->left = lChild->right;
    lChild->right = root;

    return lChild;
}

// 루트가 NULL노드(단말노드)이면 그 자리에 key가 NULL인 노드 삽입
// 루트가 NULL이 아니면 키의 값에 따라 왼쪽 서브트리, 오른쪽 서브트리에 노드
// 삽입.
TreeNode* insertNode(TreeNode* root, TElement key) {
    if (root == NULL) {
        return makeNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }

    int balance = caculateBalance(root);

    // LL Type -> root node의 왼쪽 노드의 왼쪽 서브트리에 key가 삽입
    // 직계 자식 노드의 방향 -> 균형인자, 직계 자식의 서브트리 -> key값 비교. 
    if(balance > 1 && key < root->left->data){
        // 루트가 오른쪽으로 내려가는 rR 연산 필요
        printf("-- LL -- ");
        return rotateRight(root);
    }

    // LR type -> root node의 왼쪽 노드의 오른쪽 서브트리에 key가 삽입
    if(balance > 1 && key > root->left->data){
        printf("-- LR -- ");
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL type
    if(balance < -1 && key < root->right->data){
        printf("-- RL --");
        
        //이 회전 연산을 거치면 문제가 되는 노드의 key가 오른쪽 자식보다 커짐.
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // RR type
    if(balance < -1 && key > root->right->data){
        printf("-- RR -- ");
        return rotateLeft(root);
    }

    return root;
}

// BST의 최솟값 노드는 가장 왼쪽의 단말노드임.
TreeNode* minValueNode(TreeNode* root) {
    TreeNode* cur = root;

    while (cur->left != NULL) {
        cur = cur->left;
    }

    return cur;
}

TreeNode* maxValueNode(TreeNode* root) {
    TreeNode* cur = root;

    while (cur->right != NULL) {
        cur = cur->right;
    }

    return cur;
}

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("[%2d] ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 삭제
TreeNode* deleteNode(TreeNode* root, TElement key) {
    if (root != NULL) {
        return NULL;
    }

    if (key < root->data) {
        // root의 왼쪽 서브트리는 왼쪽 서브트리에서 key인 노드를 제거한
        // 서브트리이다.
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {

        // 왼쪽 자식은 없는데 오른쪽 자식은 있는지 없는지 모름
        if (root->left == NULL) {
            // 왜 하필 right? -> BST의 성질 때문인데 한 번 봐야 할 듯
            // 어차피 오른쪽 자식 노드는 자신의 값보다 더 크기 때문에 부모의
            // 오른쪽에 와도 이상무
            TreeNode* tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right ==
                   NULL) { // 왼쪽 자식이 있는데 오른쪽 자식은 없는 경우 ->
                           // 명백히 왼쪽 자식만 있음

            //
            TreeNode* tmp = root->left;
            free(root);
            return tmp;
        } else {

            // root보다 큰 값 중 최솟값을 찾는다.
            TreeNode* tmp = minValueNode(root->right);
            // 키값 복사
            root->data = tmp->data;
            // 계승자 삭제
            root->right = deleteNode(root->right, tmp->data);
        }

        
    }
    
    return root;
}

// 노드 개수 세기
// 노드 높이 세기

void display(TreeNode* root, TElement key) {
    printf("[Insert %d]: ", key);
    preorder(root);
    printf("\n");
}

int main() {

    TreeNode* root = NULL;
    TElement data[] = {7, 8, 9, 2, 1, 5, 3, 6, 4};

    for (int i = 0; i < 9; i++) {
        root = insertNode(root, data[i]);
        display(root, data[i]);
    }


}