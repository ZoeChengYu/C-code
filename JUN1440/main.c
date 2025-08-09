#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s *right, *left;
} tree_t;
typedef tree_t * btree;

#define MAX 21

btree build_pre_in(const char *pre, const char *in, int len) {
    if (len <= 0) return NULL;
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = pre[0];
    root->left = root->right = NULL;

    int idx;
    for (idx = 0; idx < len; ++idx) {
        if (in[idx] == pre[0]) break;
    }

    root->left = build_pre_in(pre + 1, in, idx);
    root->right = build_pre_in(pre + 1 + idx, in + idx + 1, len - idx - 1);
    return root;
}

btree build_post_in(const char *post, const char *in, int len) {
    if (len <= 0) return NULL;
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = post[len - 1];
    root->left = root->right = NULL;

    int idx;
    for (idx = 0; idx < len; ++idx) {
        if (in[idx] == post[len - 1]) break;
    }

    root->left = build_post_in(post, in, idx);
    root->right = build_post_in(post + idx, in + idx + 1, len - idx - 1);
    return root;
}

// Queue for BFS
btree queue[MAX];
int front = 0, rear = 0;
void enqueue(btree node) {
    queue[rear++] = node;
}
btree dequeue() {
    return queue[front++];
}
int is_empty() {
    return front == rear;
}

void level_order(btree root) {
    if (!root) return;
    enqueue(root);
    while (!is_empty()) {
        btree cur = dequeue();
        printf("%c", cur->data);
        if (cur->left) enqueue(cur->left);
        if (cur->right) enqueue(cur->right);
    }
}

int main() {
    char type1, type2;
    char seq1[MAX], seq2[MAX];
    scanf(" %c", &type1);
    scanf("%s", seq1);
    scanf(" %c", &type2);
    scanf("%s", seq2);

    int len = strlen(seq1);
    btree root = NULL;

    if ((type1 == 'P' && type2 == 'I')) {
        root = build_pre_in(seq1, seq2, len);
    } else if ((type1 == 'I' && type2 == 'P')) {
        root = build_pre_in(seq2, seq1, len);
    } else if ((type1 == 'O' && type2 == 'I')) {
        root = build_post_in(seq1, seq2, len);
    } else if ((type1 == 'I' && type2 == 'O')) {
        root = build_post_in(seq2, seq1, len);
    }

    level_order(root);
    printf("\n");
    return 0;
}
