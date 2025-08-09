#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t* nodep_t;

// Stack 操作
void stack_push(nodep_t *top, int data) {
    nodep_t new_node = (nodep_t)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

void stack_pop(nodep_t *top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", (*top)->data);
    nodep_t temp = *top;
    *top = (*top)->next;
    free(temp);
}

void stack_top(nodep_t top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", top->data);
}

void stack_empty(nodep_t *top, int silent) {
    if (*top == NULL) {
        if (!silent)
            printf("Stack is empty\n");
        return;
    }
    nodep_t temp;
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void stack_print(nodep_t top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

// Queue 操作
void queue_push(nodep_t *front, nodep_t *rear, int data) {
    nodep_t new_node = (nodep_t)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (*rear == NULL) {
        *front = *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void queue_pop(nodep_t *front, nodep_t *rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n", (*front)->data);
    nodep_t temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
}

void queue_front(nodep_t front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n", front->data);
}

void queue_empty(nodep_t *front, nodep_t *rear, int silent) {
    if (*front == NULL) {
        if (!silent)
            printf("Queue is empty\n");
        return;
    }
    nodep_t temp;
    while (*front != NULL) {
        temp = *front;
        *front = (*front)->next;
        free(temp);
    }
    *rear = NULL;
}

void queue_print(nodep_t front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (front != NULL) {
        printf("%d\n", front->data);
        front = front->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    nodep_t stack = NULL;
    nodep_t queue_front_ptr = NULL;
    nodep_t queue_rear_ptr = NULL;

    char type[10], op[10];
    int value;

    for (int i = 0; i < N; ++i) {
        scanf("%s %s", type, op);

        if (strcmp(type, "stack") == 0) {
            if (strcmp(op, "push") == 0) {
                scanf("%d", &value);
                stack_push(&stack, value);
            } else if (strcmp(op, "pop") == 0) {
                stack_pop(&stack);
            } else if (strcmp(op, "top") == 0) {
                stack_top(stack);
            } else if (strcmp(op, "empty") == 0) {
                stack_empty(&stack, 0);  // 顯示輸出
            } else if (strcmp(op, "print") == 0) {
                stack_print(stack);
            }
        } else if (strcmp(type, "queue") == 0) {
            if (strcmp(op, "push") == 0) {
                scanf("%d", &value);
                queue_push(&queue_front_ptr, &queue_rear_ptr, value);
            } else if (strcmp(op, "pop") == 0) {
                queue_pop(&queue_front_ptr, &queue_rear_ptr);
            } else if (strcmp(op, "front") == 0) {
                queue_front(queue_front_ptr);
            } else if (strcmp(op, "empty") == 0) {
                queue_empty(&queue_front_ptr, &queue_rear_ptr, 0);  // 顯示輸出
            } else if (strcmp(op, "print") == 0) {
                queue_print(queue_front_ptr);
            }
        }
    }

    // 清理剩餘節點，但不顯示多餘訊息
    stack_empty(&stack, 1);
    queue_empty(&queue_front_ptr, &queue_rear_ptr, 1);

    return 0;
}
