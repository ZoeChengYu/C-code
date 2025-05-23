#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 20
#define INF 1000000000

int N;
int dist[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
int parent[1 << MAXN][MAXN];

int tsp(int start, int *final_node) {
    for (int mask = 0; mask < (1 << N); mask++)
        for (int i = 0; i < N; i++) {
            dp[mask][i] = INF;
            parent[mask][i] = -1;
        }

    dp[1 << start][start] = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int u = 0; u < N; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < N; v++) {
                if ((mask & (1 << v)) || dist[u][v] == -1) continue;
                int next = mask | (1 << v);
                if (dp[mask][u] + dist[u][v] < dp[next][v]) {
                    dp[next][v] = dp[mask][u] + dist[u][v];
                    parent[next][v] = u;
                }
            }
        }
    }

    int res = INF;
    int last = -1;
    for (int u = 0; u < N; u++) {
        if (u != start && dist[u][start] != -1 && dp[(1 << N) - 1][u] != INF) {
            int total = dp[(1 << N) - 1][u] + dist[u][start];
            if (total < res) {
                res = total;
                last = u;
            }
        }
    }

    *final_node = last;
    return res == INF ? -1 : res;
}

void print_tsp_path(int start, int end) {
    int path[MAXN + 1];
    int mask = (1 << N) - 1;
    int idx = 0;
    int curr = end;

    while (curr != -1) {
        path[idx++] = curr;
        int prev = parent[mask][curr];
        mask ^= (1 << curr);
        curr = prev;
    }

    printf("TSP path: ");
    for (int i = idx - 1; i >= 0; i--) {
        printf("%d ", path[i] + 1);
    }
}

void tsp_path(int start, int end,int *sdata) {
    int path[MAXN + 1];
    int mask = (1 << N) - 1;
    int idx = 0;
    int curr = end;

    while (curr != -1) {
        path[idx++] = curr;
        int prev = parent[mask][curr];
        mask ^= (1 << curr);
        curr = prev;
    }

    int d=0;
    for (int i = idx - 1; i >= 0; i--) {
        sdata[d]=path[i] + 1;
        d++;
    }
}

void printMatrix() {
    printf("Updated distance matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int start) {
    int minDist[MAXN];
    bool visited[MAXN] = {false};

    for (int i = 0; i < N; i++) minDist[i] = INF;
    minDist[start] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && minDist[i] <= min) {
                min = minDist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && dist[u][v] != -1 && minDist[u] + dist[u][v] < minDist[v]) {
                minDist[v] = minDist[u] + dist[u][v];
            }
        }
    }

    printf("Dijkstra results (distances from 1):\n");
    for (int i = 0; i < N; i++) {
        if (minDist[i] == INF)
            printf("City 1 -> %d, distance: unreachable\n", i + 1);
        else
            printf("City 1 -> %d, distance: %d\n", i + 1, minDist[i]);
    }
}

int main() {
    scanf(" %d", &N);

    // 讀取 NxN 距離矩陣
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf(" %d", &dist[i][j]);

    // 讀取欲刪除邊數量 M
    int M;
    scanf(" %d", &M);
    int mount[N];

    int half_node;
    int resulta = tsp(0, &half_node);
    if (resulta == -1) {
        printf("(1)No complete TSP tour possible.\n");
    } else {
        printf("(1)Shortest total TSP distance: %d\n", resulta);
        tsp_path(0, half_node,mount);
    }
    //printf("%d,%d\n",mount[M-1],mount[M]);
    dist[mount[M]-1][mount[M-1]-1]=-1;
    dist[mount[M-1]-1][mount[M]-1]=-1;

    int u, v;
    scanf(" %d %d", &u, &v);
    dist[u - 1][v - 1] = -1;
    dist[v - 1][u - 1] = -1;

    printMatrix();
    //dijkstra(0);

    int end_node;
    int result = tsp(0, &end_node);
    if (result == -1) {
        printf("No complete TSP tour possible.\n");
    } else {
        printf("Shortest total TSP distance: %d\n", result);
        print_tsp_path(0, end_node);
    }

    return 0;
}
