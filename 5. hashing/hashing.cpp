#include <iostream>

using namespace std;

struct HashNode {
  int key;
  int value;
  HashNode *next;
};

struct HashMap {
  HashNode **table;
  int capacity;
};

HashNode *createHashNode(int key, int value) {
  HashNode *newNode = new HashNode;
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void deleteHashNode(HashNode *node) { delete node; }

int hashFunction(int key, int capacity) { return key % capacity; }

HashMap *createHashMap(int size) {
  HashMap *hashMap = new HashMap;
  hashMap->capacity = size;
  hashMap->table = new HashNode *[size];

  for (int i = 0; i < size; i++) {
    hashMap->table[i] = NULL;
  }

  return hashMap;
}

void insertData(HashMap *hashMap, int key, int value) {
  int hashIndex = hashFunction(key, hashMap->capacity);
  HashNode *prev = NULL;
  HashNode *entry = hashMap->table[hashIndex];

  while (entry != NULL && entry->key != key) {
    prev = entry;
    entry = entry->next;
  }

  if (entry == NULL) {
    entry = createHashNode(key, value);

    if (prev == NULL) {
      hashMap->table[hashIndex] = entry;
      return;
    }

    prev->next = entry;
    return;
  }
  entry->value = value;
}

int searchData(HashMap *hashMap, int key) {
  int hashIndex = hashFunction(key, hashMap->capacity);
  HashNode *entry = hashMap->table[hashIndex];

  while (entry != NULL) {
    if (entry->key == key) {
      return entry->value;
    }

    entry = entry->next;
  }

  return -1;
}

void removeData(HashMap *hashMap, int key) {
  int hashIndex = hashFunction(key, hashMap->capacity);
  HashNode *entry = hashMap->table[hashIndex];
  HashNode *prev = NULL;

  while (entry != NULL && entry->key != key) {
    prev = entry;
    entry = entry->next;
  }

  if (entry == NULL) {
    cout << "Key not found" << endl;
    return;
  }

  if (prev == NULL) {
    hashMap->table[hashIndex] = entry->next;
    deleteHashNode(entry);
    return;
  }

  prev->next = entry->next;
  deleteHashNode(entry);
}

void deleteHashMap(HashMap *hashMap) {
  for (int i = 0; i < hashMap->capacity; i++) {
    HashNode *entry = hashMap->table[i];

    while (entry != NULL) {
      HashNode *prev = entry;
      entry = entry->next;
      delete prev;
    }
  }

  delete[] hashMap->table;
  delete hashMap;
}

int main() {
  HashMap *hashTable = createHashMap(10);

  insertData(hashTable, 1, 10);
  insertData(hashTable, 2, 20);
  insertData(hashTable, 3, 30);

  cout << "Value for key 1: " << searchData(hashTable, 1) << endl;
  cout << "Value for key 2: " << searchData(hashTable, 2) << endl;
  cout << "Value for key 3: " << searchData(hashTable, 3) << endl;

  removeData(hashTable, 2);
  cout << "Value for key 2 after removal: " << searchData(hashTable, 2) << endl;

  deleteHashMap(hashTable);

  return 0;
}