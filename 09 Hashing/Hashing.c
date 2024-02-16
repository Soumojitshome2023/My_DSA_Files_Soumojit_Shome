#include <stdio.h>
#include <stdlib.h>

// ====================== Hash Table ======================
// Define the hash table structure.
struct HashTable
{
    int capacity;
    int size;
    struct Node **table;
};

// ====================== Node ======================
// Define the node structure.
struct Node
{
    int key;
    int value;
    struct Node *next;
};

// ====================== HashTable ======================
// Create a new hash table.
struct HashTable *createHashTable(int capacity)
{
    struct HashTable *table = malloc(sizeof(struct HashTable));
    table->capacity = capacity;
    table->size = 0;
    table->table = malloc(sizeof(struct Node *) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        table->table[i] = NULL;
    }
    return table;
}

// ====================== Hash ======================
// Get the hash code for a given key.
int hash(int key, int capacity)
{
    return key % capacity;
}

// ====================== Insert ======================
// Insert a new key-value pair into the hash table.
void insert(struct HashTable *table, int key, int value)
{
    int index = hash(key, table->capacity);
    struct Node *node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = table->table[index];
    table->table[index] = node;
    table->size++;
}

// ====================== Search ======================
// Search for a key in the hash table.
int search(struct HashTable *table, int key)
{
    int index = hash(key, table->capacity);
    struct Node *node = table->table[index];
    while (node != NULL)
    {
        if (node->key == key)
        {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

// ====================== Delete ======================
// Delete a key-value pair from the hash table.
void delete(struct HashTable *table, int key)
{
    int index = hash(key, table->capacity);
    struct Node *node = table->table[index];
    struct Node *prev = NULL;
    while (node != NULL)
    {
        if (node->key == key)
        {
            if (prev == NULL)
            {
                table->table[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node);
            table->size--;
            return;
        }
        prev = node;
        node = node->next;
    }
}

// ======================Print ======================
// Print the hash table.
void printHashTable(struct HashTable *table)
{
    for (int i = 0; i < table->capacity; i++)
    {
        struct Node *node = table->table[i];
        while (node != NULL)
        {
            printf("%d -> %d\n", node->key, node->value);
            node = node->next;
        }
    }
}

// ====================== Main ======================
int main()
{
    // Create a new hash table.
    struct HashTable *table = createHashTable(10);

    // Insert some key-value pairs into the hash table.
    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);
    insert(table, 4, 40);
    insert(table, 5, 50);

    // Print the hash table.
    printHashTable(table);

    // Search for a key in the hash table.
    int value = search(table, 3);
    printf("The value of key 3 is %d\n", value);

    // Delete a key-value pair from the hash table.
    delete (table, 2);

    // Print the hash table.
    printHashTable(table);

    return 0;
}
// ==================================================================