#include <stdlib.h>
#include <stdio.h>

//아몰랑 메모리 제한 넉넉하니까 ㅋㅋㅋ
#define MAX 67108870

char tree[MAX];
int locations[30];

int get_left_idx(int idx){
    if(idx < 1){return 0;}

    return idx * 2;
}

int get_right_idx(int idx){
    if(idx < 1){return 0;}

    return idx * 2 + 1;
}

void preorder(int parent){

    // printf("visited: %c \n", (char)parent + 'A');

    if(tree[parent] == '\0'){
        // printf("Null node makes preorder return \n");
        return;
    }

    if(parent >= MAX){
        // printf("Range excced makes ppreorder return \n");
        return;
    }


    putchar(tree[parent]);
    preorder(get_left_idx(parent));
    preorder(get_right_idx(parent));
}


void inorder(int parent){
    if(tree[parent] == '\0'){
        return;
    }

    if(parent >= MAX){
        return;
    }

    inorder(get_left_idx(parent));
    putchar(tree[parent]);
    inorder(get_right_idx(parent));

}


void postorder(int parent){
    if(tree[parent] == '\0'){
        return;
    }

    if(parent >= MAX){
        return;
    }

    postorder(get_left_idx(parent));
    postorder(get_right_idx(parent));
    putchar(tree[parent]);
}

int main(){
    int num;
    scanf("%d", &num);

    locations[('A' - 'A') + 1] = 1;
    tree[1] = 'A';
    char pc, lc, rc;
    for(int i = 0; i < num; i++){
        scanf(" %c %c %c", &pc, &lc, &rc);
        
        if(lc != '.'){
            int perentIdx = locations[(pc - 'A') + 1];
            int left = get_left_idx(perentIdx);
            tree[left] = lc;
            locations[lc - 'A' + 1] = left;
        }
        if(rc != '.'){
            int perentIdx = locations[(pc - 'A') + 1];
            int rightIdx = get_right_idx(perentIdx);
            tree[rightIdx] = rc;
            locations[rc - 'A' + 1] = rightIdx;
        };
    }

    // for(int i = 0; i < num; i++){
    //     printf("%d: %c \n", i + 1, tree[i + 1]);
    // }
    
    preorder(1);
    putchar('\n');
    inorder(1);
    putchar('\n');
    postorder(1);

}