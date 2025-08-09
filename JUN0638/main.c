#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
    int data;
    struct dnode_s *front;
    struct dnode_s *back;
} node_t;
typedef node_t* nodep_t;

nodep_t head = NULL;
nodep_t tail = NULL;

// 計算節點長度
int getLength() {
    int count = 0;
    nodep_t curr = head;
    while (curr) {
        count++;
        curr = curr->back;
    }
    return count;
}

void addFront(int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->front = NULL;
    newNode->back = head;
    if (head)
        head->front = newNode;
    head = newNode;
    if (!tail)
        tail = newNode;
}

void addBack(int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->back = NULL;
    newNode->front = tail;
    if (tail)
        tail->back = newNode;
    tail = newNode;
    if (!head)
        head = newNode;
}

void removeFront() {
    if (!head) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t temp = head;
    head = head->back;
    if (head)
        head->front = NULL;
    else
        tail = NULL;
    free(temp);
}

void removeBack() {
    if (!tail) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t temp = tail;
    tail = tail->front;
    if (tail)
        tail->back = NULL;
    else
        head = NULL;
    free(temp);
}

void emptyList() {
    if (!head) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t curr = head;
    while (curr) {
        nodep_t temp = curr;
        curr = curr->back;
        free(temp);
    }
    head = NULL;
    tail = NULL;
}

void insert(int n, int data) {
    int len = getLength();
    if (n > len) {
        printf("Invalid command\n");
        return;
    }
    nodep_t curr = head;
    for (int i = 1; i < n; i++) {
        curr = curr->back;
    }
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->front = curr;
    newNode->back = curr->back;
    if (curr->back)
        curr->back->front = newNode;
    else
        tail = newNode;
    curr->back = newNode;
}

void removeAt(int n) {
    int len = getLength();
    if (n > len) {
        printf("Invalid command\n");
        return;
    }
    nodep_t curr = head;
    for (int i = 1; i < n; i++) {
        curr = curr->back;
    }
    if (curr->front)
        curr->front->back = curr->back;
    else
        head = curr->back;
    if (curr->back)
        curr->back->front = curr->front;
    else
        tail = curr->front;
    free(curr);
}

void printList() {
    if (!head) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t curr = head;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->back;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char command[20];
    for (int i = 0; i < N; i++) {
        scanf("%s", command);
        if (strcmp(command, "addFront") == 0) {
            int val;
            scanf("%d", &val);
            addFront(val);
        } else if (strcmp(command, "addBack") == 0) {
            int val;
            scanf("%d", &val);
            addBack(val);
        } else if (strcmp(command, "removeFront") == 0) {
            removeFront();
        } else if (strcmp(command, "removeBack") == 0) {
            removeBack();
        } else if (strcmp(command, "empty") == 0) {
            emptyList();
        } else if (strcmp(command, "insert") == 0) {
            int pos, val;
            scanf("%d %d", &pos, &val);
            insert(pos, val);
        } else if (strcmp(command, "remove") == 0) {
            int pos;
            scanf("%d", &pos);
            removeAt(pos);
        } else if (strcmp(command, "print") == 0) {
            printList();
        }
    }
    return 0;
}
