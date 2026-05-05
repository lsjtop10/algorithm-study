#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


# define MAX_STACK_SIZE 10


typedef char element_tree;
typedef struct TreeNode{
    element_tree data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef TreeNode* element_stack;
#define STACK_ELEMENT_ZERO NULL
typedef struct StackType{
    element_stack data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* s){
    s->top = -1;
}

bool isFull(StackType* s){
    return s->top == MAX_STACK_SIZE - 1;
}

bool isEmpty(StackType* s){
    return s->top == -1;
}

void push(StackType* s, element_stack e){
    if(isFull(s)){
        printf("OVERFLOW STACK!!!");
        return;
    }

    s->top++;
    s->data[s->top] = e;
}

element_stack pop(StackType* s){
    if(isEmpty(s)){
        printf("STAVK IS EMPTY");
        return STACK_ELEMENT_ZERO;
    }

    element_stack e = s->data[s->top];
    s->top--;
    return e;
}



TreeNode* makeNode(element_tree e, TreeNode* left, TreeNode* right ){
    TreeNode* node = malloc(sizeof(TreeNode));
    
    node->data = e;
    node->left = left;
    node->right = right;
}

void preOrder_iter(TreeNode* root){

    if(root == NULL){
        return;
    }

    StackType s;
    init_stack(&s);

    while (root != NULL||!isEmpty(&s)){
        
        //자식 노드가 없을 때까지
        while (root != NULL){
            //먼저 출력하고
            printf("[%c]", root->data);
            
            //오른쪽 노드를 나중에 탐색해야 하니까 stack에 넣고
            if(root->right != NULL){
                push(&s, root->right);
            }

            // 왼쪽을 일단 탐색함
            root = root->left;
        }
        // 루트 노드를 거쳐서 왼쪽 노드를 탐색했으므로 C-L은 완료

        //그러다가 왼쪽으로 더 이상 탐색할 수 없으면 오른쪽 탐색할 차례
        if(!isEmpty(&s)){
            //나중에 탐색하기로 했던 오른쪽 노드 탐색
            root = pop(&s);
        }
    }
    
}

void inOrder_iter(TreeNode* root) {
    StackType s;
    init(&s);

    while (root != NULL || !isEmpty(&s)) {
        // 1. 왼쪽 끝까지 내려가며 경로를 스택에 저장 (출력 안 함!)
        while (root != NULL) {
            push(&s, root); 
            root = root->left;
        }

        // 2. 더 이상 왼쪽으로 갈 수 없을 때 (root == NULL)
        if (!isEmpty(&s)) {
            root = pop(&s);    // 드디어 부모(혹은 왼쪽 끝)로 복귀
            printf("[%c] ", root->data); // ★ 이 시점이 출력을 위한 골든 타임! ★

            // 3. 이제 오른쪽 서브트리로 이동
            // 만약 오른쪽 서브트리가 없다면 rott == null이 돼 이 if문이 한 번 더 실행됨.
            root = root->right;
        }
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

    preOrder_iter(nodes[1]);

}
