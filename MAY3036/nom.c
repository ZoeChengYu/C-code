#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105

typedef struct Node {
    int duration;          // 完成這個節點所需天數
    int in_degree;         // 入度：有多少前置節點
    int out_degree;        // 出度數
    int out_nodes[MAXN];   // 出邊：可開發哪些節點
} Node;

Node nodes[MAXN];
int earliest[MAXN];  // 每個節點的最早完成時間
int queue[MAXN];     // 拓撲排序的 queue

int max(int a, int b) {
    return a > b ? a : b;
}

void solve_project(int M) {
    int i;
    memset(earliest, 0, sizeof(earliest));

    int front = 0, rear = 0;

    // 將所有 in_degree 為 0 的節點加入 queue
    for (i = 1; i <= M; i++) {
        if (nodes[i].in_degree == 0) {
            earliest[i] = nodes[i].duration;
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        for (i = 0; i < nodes[u].out_degree; i++) {
            int v = nodes[u].out_nodes[i];
            if (earliest[v] < earliest[u] + nodes[v].duration) {
                earliest[v] = earliest[u] + nodes[v].duration;
            }
            // 減少入度，若為 0 則加入 queue
            nodes[v].in_degree--;
            if (nodes[v].in_degree == 0) {
                queue[rear++] = v;
            }
        }
    }

    // 計算最長完成時間
    int total_time = 0;
    for (i = 1; i <= M; i++) {
        if (earliest[i] > total_time) {
            total_time = earliest[i];
        }
    }

    printf("%d\n", total_time);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);
        // 初始化
        for (int i = 1; i <= M; i++) {
            nodes[i].in_degree = 0;
            nodes[i].out_degree = 0;
        }

        for (int i = 1; i <= M; i++) {
            int dur, K;
            scanf("%d %d", &dur, &K);
            nodes[i].duration = dur;

            for (int j = 0; j < K; j++) {
                int target;
                scanf("%d", &target);
                nodes[i].out_nodes[nodes[i].out_degree++] = target;
                nodes[target].in_degree++;
            }
        }

        solve_project(M);
    }

    return 0;
}
