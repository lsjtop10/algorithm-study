#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUCKETS 13
#define NUM_SLOTS 1

typedef struct {
    int table[NUM_BUCKETS]

} HashTableType;

int caculateHash(int key) {
    // 제산함수 사용
    return key % NUM_BUCKETS;
}

int caculateHash2(int key) {
    // 제산함수 사용
    return 11 - (key % 11);
}

void init(HashTableType* ht) { memset(ht->table, 0, sizeof(int) * NUM_BUCKETS); }

void insertItem(HashTableType* ht, int data) {
    int hash = caculateHash(data);
    int hash2 = caculateHash2(data);

    for (int i = 0; i < NUM_BUCKETS; i++) {
        int b = (hash + i) % NUM_BUCKETS; //-> 선형조사법
        //  int b = (hash + i * i) % NUM_BUCKETS; -> 이차조사법 이차군집 발생 가능
        // int b = (hash + i * hash) % NUM_BUCKETS;
        if (ht->table[b] == 0 || ht->table[b] == -1) {
            ht->table[b] = data;
            return;
        }
    }
    

    printf("OVERFLOW!");
}

bool findItem(HashTableType* ht, int data) {
    int hash = caculateHash(data);
    int hash2 = caculateHash2(data);

    for (int i = 0; i < NUM_BUCKETS; i++) {
        int b = (hash + i) % NUM_BUCKETS; //-> 선형조사법
        //  int b = (hash + i * i) % NUM_BUCKETS; -> 이차조사법 이차군집 발생 가능
        // int b = (hash + i * hash) % NUM_BUCKETS;
        if (ht->table[b] == 0) {
            break;
        }
        
        if(ht->table[b] == data){
            return true;
        }

    }

    return false;

}


void deleteItem(HashTableType* ht, int data) {
    int hash = caculateHash(data);
    int hash2 = caculateHash2(data);

    for (int i = 0; i < NUM_BUCKETS; i++) {
        int b = (hash + i) % NUM_BUCKETS; //-> 선형조사법
        //  int b = (hash + i * i) % NUM_BUCKETS; -> 이차조사법 이차군집 발생 가능
        // int b = (hash + i * hash) % NUM_BUCKETS;
        if (ht->table[b] == 0) {
            break;
        }
        
        if(ht->table[b] == data){
            ht->table[b] = -1; // 이러면 값이 원래 없는 것인지 있다가 없는 것인지 구분이 안 된다.
            // 원래 없음 -> 탐색 종료
            // 뒤 값이 있는데 데이터 비어 있음 -> 탐색 계속
            break;
        }

    }


}

void print(HashTableType* ht) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        printf("(key: %2d, value: %2d) \n", caculateHash(i), ht->table[i]);
    }
}

void main() {
    HashTableType ht;
    init(&ht);

    int data[] = {45, 27, 88, 9, 71, 60, 46, 38, 24};

    printf("\n");
    printf("hash values of keyes\n");

    for (int i = 0; i < 9; i++) {
        printf("h(%2d) = %2d\n", data[i], caculateHash(data[i]));
        insertItem(&ht, data[i]);
        print(&ht);
    }
}
