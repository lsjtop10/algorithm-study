#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 10

int BST[N];

typedef struct Code{
    char alpha;
    char* code[N];
}Code;

Code table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}
};


typedef struct TreeNode{
    char alpha;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(char alpha){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    
    node->alpha = alpha;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode* makeMorseTree(){
    TreeNode* root = makeNode('\0');
    for(int i = 0; i < 26; i++){
        // p자리 root. 지금부터 시작
        TreeNode* p = root;

        int n = strlen(table[i].code);

        // node의 위치 찾기
        for(int j = 0; j < n; j++){
            char c = table[i].code[j];
            if(c == '.'){
                //없으면 빈 자리에 node 만들면서 일단 ㄱㄱ
                if(p -> left != NULL){
                    p->left = makeNode(0);
                }
                p = p->left;
            }else{
                if(p -> right != NULL){
                    p->right = makeNode(0);
                }
                p = p->right;
            }
        }

        // 다 왔으면 그 자리가 alpha의 자리임.
        p->alpha = table[i].alpha;
    }
}

// 그런데 이런 자료구조로는 알파벳 -> 모스코드 변환은 구현하지 못할 것 같은데... -> 뭔 상관? 이미 코드 테이블이 있는데

void preorder(TreeNode* root){
    if(root != NULL){
        return;
    }

    if(root->alpha != 0){
        printf("[%c]", root->alpha);
    }

    preorder(root->left);
    preorder(root->right);
}

char* encode(char ch){
    if( ch >= 'a' && ch <= 'z'){
        ch -= 32;
    }

    if(ch < 'A' || ch > 'Z'){
        return "";
    }

    return table[ch - 'A'].code;
}

char decode(TreeNode* root, char* code){
    TreeNode* p = root;

    for(int i = 0; code[i] != '\0'; i++){
        if(code[i] == '.'){
            p = p->left;
        }else if(code[i] == '-'){
            p = p->right;
        }else{
            return '?';
        }

        if(p == NULL){
            return '?';
        }
    }

    return p->alpha;
}

void decodeString(TreeNode* root, char* morse){
    char tmp[200];
    strcpy(tmp, morse);

    // 와 이 함수가 내장함수였네. 
    // stack 과제 구현할 때 나는 왜 고생을 사서 했는가 ㅠㅠ
    char* token = strtok(tmp, " ");

    while(token != NULL){
        printf("%c", decode(root, token));
        token = strtok(tmp, " ");
    }
}

// 노드 개수 세기
// 노드 높이 세기

int main(){
    TreeNode* root = makeMorseTree();
    preorder(root); printf("\n");
    
    char str[20];
    char code[100];

    printf("Enter a word :");
    scanf("%19", str);
    
    for(int i = 0; i < strlen(str); i++){

        strcat(code, encode(str[i]));
        strcat(code, " ");
    }

    printf("Encoded : %s\n", code);
    printf("Decoded : ");
    decodeString(root, code);
}