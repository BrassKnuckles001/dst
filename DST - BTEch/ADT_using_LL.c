#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key[50];
    char value[50];
    struct Node* next;
} Node;

Node* createNode(const char* key, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, const char* key, const char* value) {
    Node* newNode = createNode(key, value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted: (%s, %s)\n", key, value);
}

void search(Node* head, const char* key) {
    Node* temp = head;
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            printf("Found: Key = %s, Value = %s\n", key, temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key %s not found\n", key);
}

void deleteKey(Node** head, const char* key) {
    Node *temp = *head, *prev = NULL;

    while (temp && strcmp(temp->key, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Key %s not found for deletion\n", key);
        return;
    }

    if (!prev)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Deleted key: %s\n", key);
}

void display(Node* head) {
    if (!head) {
        printf("Dictionary is empty\n");
        return;
    }

    printf("Dictionary contents:\n");
    Node* temp = head;
    while (temp) {
        printf("Key: %s, Value: %s\n", temp->key, temp->value);
        temp = temp->next;
    }
}

int main() {
    Node* dictionary = NULL;

    insert(&dictionary, "name", "Alice");
    insert(&dictionary, "age", "25");
    insert(&dictionary, "city", "Pune");

    display(dictionary);

    search(dictionary, "age");
    search(dictionary, "country");

    deleteKey(&dictionary, "city");
    deleteKey(&dictionary, "country");

    display(dictionary);

    return 0;
}
