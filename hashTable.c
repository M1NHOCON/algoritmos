#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hashTableSize 100

int hash(long int timestamp, int tamanho){
    return timestamp % tamanho;
}

typedef struct {
    long int timestamp;
    int cliente;
} Log;

typedef struct {
    Log *timestamp;
    int tamanho_log;
} Node;

void realocarLog(Node *hashTable, int log){
    int novo_tamanho = hashTable[log].tamanho_log +1;
    Log *novo_log = (Log *)malloc(novo_tamanho * sizeof(Log));
    for(int i = 0; i < hashTable[log].tamanho_log; i++){
        novo_log[i] = hashTable[log].timestamp[i];
    }
    free(hashTable[log].timestamp);
    hashTable[log].timestamp = novo_log;
    hashTable[log].tamanho_log = novo_tamanho; 
}
