#include <bits/stdc++.h>

using namespace std;

int foldingHash(int key, int tableSize) {
    int sum = 0;
    while (key != 0){
        sum += key % 10;
        key = key / 10;
    }
    
    return sum % tableSize;
}

int main(){
    int tableSize = 10;
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++)
        hashTable[i] = -1;
    int keys[] = {123, 456, 789, 1011, 1213, 1415, 1617, 1819, 2021, 2223};
    for (int i = 0; i < 10; i++) {
        int hashValue = foldingHash(keys[i], tableSize);
        while (hashTable[hashValue] != -1) {
            hashValue = (hashValue + 1) % tableSize;
        }
        hashTable[hashValue] = keys[i];
    }
    for (int i = 0; i < tableSize; i++) {
        printf(" %d : %d \n", i, hashTable[i]);
    }
    return 0;
}