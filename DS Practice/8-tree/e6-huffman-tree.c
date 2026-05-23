#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Mut(x) x
#define Move(x) x
#define Out(x) x

typedef struct HuffmanTreeNode {
    uint64_t freq;
    char value;

    struct HuffmanTreeNode* left;
    struct HuffmanTreeNode* right;
} HuffmanTreeNode;

typedef struct HuffmanTreeType {
    HuffmanTreeNode* root;
} HuffmanTreeType;

#define MAX_HEAP_SIZE 50
typedef HuffmanTreeNode* HeapElement;
typedef struct HeapType {
    HeapElement data[MAX_HEAP_SIZE];
    int size;
} HeapType;

typedef uint16_t HuffmanCode;
#define MAX_HUFMAN_CODE_SIZE 16
#define MAX_CHAR_SIZE 256

typedef struct HuffmanCodeTable {
    HuffmanCode code[MAX_CHAR_SIZE];
    size_t length[MAX_CHAR_SIZE];
} HuffmanCodeTable;

typedef struct FreqTable {
    uint64_t freq[MAX_CHAR_SIZE];
} FreqTable;

HuffmanTreeNode* make_HuffmanTreeNode(int freq, char value);

void init_Heap(HeapType* h);
void __upHeap_Heap(HeapType* h);
void __downHeap_Heap(HeapType* h);
bool __isFull_Heap(HeapType* h);
bool __isEmpty_Heap(HeapType* h);
void insert_Heap(HeapType* h, HeapElement node);
HeapElement delete_Heap(HeapType* h);

HuffmanTreeNode* build_HuffmanTree(FreqTable* t);

void init_HuffmanCodeTable(HuffmanCodeTable* t);
uint16_t lookupCode_HuffmanCodeTable(HuffmanCodeTable* t, char c);
uint16_t lookupCodeLength_HuffmanCodeTable(HuffmanCodeTable* t, char c);
void setCode(HuffmanCodeTable* t, char c, uint16_t code, size_t length);
void buildTable_HuffmanCodeTable(HuffmanCodeTable* t, HuffmanTreeNode* hTreeRoot, uint16_t code, size_t codeLength);

void init_FreqTable(FreqTable* t);
void count_FreqTable(FreqTable* t, char* str, size_t strSize);
void __increseFreq_FreqTable(FreqTable* t, char c);
int lookupFreq_FreqTable(FreqTable* t, char c);

Move(uint8_t*) encodeHuffmanCode(HuffmanCodeTable* ct, char* str, int strSize, Out(int*) encodedSize);

bool getBit(uint16_t code, int at);
void setBit(uint16_t* code, int at, bool v);

bool getBit(uint16_t code, int at) { return (code & (1 << MAX_HUFMAN_CODE_SIZE - at - 1)) != 0; }

void setBit(uint16_t* code, int at, bool v) {
    if (v) {
        *code = *code | (1 << (MAX_HUFMAN_CODE_SIZE - at - 1));
    } else {
        *code = *code & ~(1 << (MAX_HUFMAN_CODE_SIZE - at - 1));
    }
}

HuffmanTreeNode* make_HuffmanTreeNode(int freq, char value) {
    HuffmanTreeNode* n = (HuffmanTreeNode*)malloc(sizeof(HuffmanTreeNode));

    n->freq = freq;
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void init_HuffmanCodeTable(HuffmanCodeTable* t) {
    memset(t->code, 0, sizeof(uint16_t) * MAX_CHAR_SIZE);
    memset(t->length, 0, sizeof(size_t) * MAX_CHAR_SIZE);
}

uint16_t lookupCode_HuffmanCodeTable(HuffmanCodeTable* t, char c) { return t->code[(int)c]; }

uint16_t lookupCodeLength_HuffmanCodeTable(HuffmanCodeTable* t, char c) { return t->length[(int)c]; }

void setCode(HuffmanCodeTable* t, char c, uint16_t code, size_t length) {
    t->code[(int)c] = code;
    t->length[(int)c] = length;
}

void buildTable_HuffmanCodeTable(HuffmanCodeTable* t, HuffmanTreeNode* hTreeRoot, uint16_t code, size_t codeLength) {
    if (hTreeRoot == NULL) {
        return;
    }

    if (hTreeRoot->left == NULL && hTreeRoot->right == NULL) {
        t->code[hTreeRoot->value] = code;
        t->length[hTreeRoot->value] = codeLength;
        return; // 코드를 저장했으므로 더 이상 아래로 내려가지 않고 종료합니다.
    }

    // setbit가 포인터 넘기므로 값을 복사해 줘야 한다.
    uint16_t codeL = code;
    setBit(&codeL, codeLength, false);
    uint16_t codeR = code;
    setBit(&codeR, codeLength, true);

    if (hTreeRoot->left != NULL) {
        buildTable_HuffmanCodeTable(t, hTreeRoot->left, codeL, codeLength + 1);
    }

    if (hTreeRoot->right != NULL) {
        buildTable_HuffmanCodeTable(t, hTreeRoot->right, codeR, codeLength + 1);
    }
}

// 리스트로 구현? 좋은 생각은 아닌 듯 탐색할 때마다 O(n)만큼의 비용이 발생할
// 텐데 잠만 어차피 탐색이 필요하네. 탐색하려면 해시 테이블 쓰는 것이 좋긴 한데
// 길이가 쉽게 예측이 안 되면 그냥 BST 쓰는 편이 나을 수도 있음 ㅇㅇ.
// AVL Tree? ㅅㅂㅋㅋ
// 일단 아스키 코드만 처리한다고 가정하자.

void init_Heap(HeapType* h) {
    for (int i = 0; i < MAX_HEAP_SIZE; i++) {
        h->data[i] = NULL;
    }

    h->size = 0;
}

bool __isFull_Heap(HeapType* h) { return h->size == MAX_HEAP_SIZE; }

bool __isEmpty_Heap(HeapType* h) { return h->size == 0; }

void __upHeap_Heap(HeapType* h) {
    int idx = h->size;
    HeapElement tmp = h->data[idx];

    while ((idx != 1) && (tmp->freq < h->data[idx / 2]->freq)) {
        h->data[idx] = h->data[idx / 2];
        idx = idx / 2;
    }

    h->data[idx] = tmp;
}

void insert_Heap(HeapType* h, HeapElement node) {
    if (__isFull_Heap(h)) {
        printf("Heap Overflow");
        return;
    }

    h->size++;
    h->data[h->size] = node;
    __upHeap_Heap(h);
}

void __downHeap_Heap(HeapType* h) {
    int parent = 1;
    int minChild = 2;
    HeapElement tmp = h->data[parent];

    // Paerent기반이 아니라 child 기반으로 범위 검사해야 함.ㅠㅠ
    while ((minChild <= h->size)) {
        if ((minChild < h->size) && (h->data[minChild + 1]->freq < h->data[minChild]->freq)) {
            minChild = minChild + 1;
        }

        if (tmp->freq <= h->data[minChild]->freq) {
            break;
        }

        h->data[parent] = h->data[minChild];

        parent = minChild;
        minChild = parent * 2;
    }

    h->data[parent] = tmp;
}

HeapElement delete_Heap(HeapType* h) {
    if (__isEmpty_Heap(h)) {
        printf("heap is empty");
        return NULL;
    }

    HeapElement root = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;

    __downHeap_Heap(h);
    return root;
}

void print__Heap(HeapType* h) {
    for (int i = 1; i <= h->size; i++) {
        HeapElement cur = h->data[i];
        printf("[%d, %c] \n", cur->freq, cur->value);
    }
    printf("\n");
}

HuffmanTreeNode* build_HuffmanTree(FreqTable* t) {
    HeapType h;
    init_Heap(&h);

    for (int i = 0; i < MAX_CHAR_SIZE; i++) {
        int freq = lookupFreq_FreqTable(t, (char)i);

        if (freq != 0) {
            insert_Heap(&h, make_HuffmanTreeNode(freq, (char)i));
        }
    }

    while (h.size != 1) {
        HuffmanTreeNode* n1 = delete_Heap(&h);
        HuffmanTreeNode* n2 = delete_Heap(&h);

        HuffmanTreeNode* new = make_HuffmanTreeNode(n1->freq + n2->freq, '\0');
        new->left = n1;
        new->right = n2;

        insert_Heap(&h, new);
    }

    return h.data[1];
}

void preOrder_HuffmanTree(HuffmanTreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("[freq:%d char:%c] \n", root->freq, root->value == '\0' ? '.' : root->value);
    preOrder_HuffmanTree(root->left);
    preOrder_HuffmanTree(root->right);
}

void init_FreqTable(FreqTable* t) { memset(t->freq, 0, sizeof(uint64_t) * MAX_CHAR_SIZE); }

void count_FreqTable(FreqTable* t, char* str, size_t strSize) {
    for (int i = 0; i < strSize; i++) {
        __increseFreq_FreqTable(t, str[i]);
    }
}

// TODO: 정수 오버플로우 방지용 연산 필요
// 자료형을 UINT_64로 매우 크게 잡았지만
// 트리 빌드 과정에서 합산되기 때문에 오버플로우 발생할 가능성 있음.
void __increseFreq_FreqTable(FreqTable* t, char c) { t->freq[(int)c]++; }
int lookupFreq_FreqTable(FreqTable* t, char c) { return t->freq[(int)c]; }

Move(uint8_t*) encodeHuffmanCode(HuffmanCodeTable* ct, char* str, int strSize, Out(int*) encodedSize) {
    int capasity = strSize;
    int idx = 0;
    int innerPtr = 0;

    uint8_t* encodedBinery = (uint8_t*)malloc(sizeof(uint8_t) * capasity);
    if (encodedBinery == NULL) {
        return NULL;
    }
    memset(encodedBinery, 0, sizeof(uint8_t) * capasity * 2);

    for (int i = 0; i < strSize; i++) {
        char c = str[i];
        HuffmanCode code = lookupCode_HuffmanCodeTable(ct, c);
        size_t length = lookupCodeLength_HuffmanCodeTable(ct, c);

        // innerPtr부터 length-1까지 bit set
        // 만약 innerPtr + length값이 7보다 커진다면 특수한 처리가 필요할 듯.
        for (int j = 0; j < length; j++) {
            if (innerPtr >= (sizeof(uint8_t) * 8 - 1)) {
                innerPtr = 0;
                idx++;

                // realoc
                if (idx > capasity) {
                    size_t newCapasity = capasity * 2;
                    encodedBinery = realloc(encodedBinery, newCapasity);
                    if (encodedBinery == NULL) {
                        printf("Err: OOM");
                        return NULL;
                    }

                    memset(encodedBinery + capasity, 0, newCapasity - capasity);
                }
            }

            uint8_t cur = 1;

            // 앞에서부터 j번째 bit 1로 set;
            cur = cur << 8 - innerPtr - 1;
            if (getBit(code, j) == true) {
                encodedBinery[idx] |= cur;
            } else {
                encodedBinery[idx] &= ~cur;
            }

            innerPtr++;
        }
    }

    *encodedSize = idx;
    return encodedBinery;
}

int main() {
    // 빈도수 구하기
    HeapType h;
    FreqTable ft;
    HuffmanCodeTable ct;

    char* str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    init_Heap(&h);
    init_FreqTable(&ft);
    init_HuffmanCodeTable(&ct);

    // 널문자까지 포함.
    count_FreqTable(&ft, str, strlen(str) + 1);

    // 허프만 트리 만들기
    HuffmanTreeNode* treeRoot = build_HuffmanTree(&ft);
    preOrder_HuffmanTree(treeRoot);

    uint16_t codeSample;

    buildTable_HuffmanCodeTable(&ct, treeRoot, 0, 0);
    for (int i = 0; i < strlen(str); i++) {
        // 한 글자씩 인코딩
        printf("char:%c \t code:0x%04X \t length:%zu\n", str[i], lookupCode_HuffmanCodeTable(&ct, str[i]), lookupCodeLength_HuffmanCodeTable(&ct, str[i]));
    }

}
