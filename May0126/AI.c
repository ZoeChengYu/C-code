#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 10
#define INF 1000000000

int N;
int dist[MAXN][MAXN];
int original[MAXN][MAXN];

int dp[1 << MAXN][MAXN];
int parent[1 << MAXN][MAXN];

// TSP 動態規劃
int tsp(int mask, int pos, int start) {
    if (mask == (1 << N) - 1) return 0;

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int min_cost = INF;
    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city)) && dist[pos][city] != -1) {
            int cost = dist[pos][city] + tsp(mask | (1 << city), city, start);
            if (cost < min_cost) {
                min_cost = cost;
                parent[mask][pos] = city;
            }
        }
    }
    return dp[mask][pos] = min_cost;
}

// 重建路徑
void reconstruct_path(int mask, int pos, int path[]) {
    int idx = 0;
    while (mask != (1 << N) - 1) {
        int next = parent[mask][pos];
        path[idx++] = next;
        mask |= (1 << next);
        pos = next;
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &dist[i][j]);
            original[i][j] = dist[i][j];
        }

    int C, u, v;
    scanf("%d", &C);
    scanf("%d %d", &u, &v);
    u--; v--; // 轉換為 0-based index

    // 第一次完整 TSP
    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));
    int full_path[MAXN], path_idx = 0;
    int total_cost = tsp(1 << 0, 0, 0); // 從城市0開始（即城市1）

    full_path[path_idx++] = 0;
    reconstruct_path(1 << 0, 0, &full_path[path_idx]);

    // 找走到第C個城市的總距離和狀態
    int visited_mask = 0;
    int partial_cost = 0;
    for (int i = 0; i < C; i++) {
        visited_mask |= (1 << full_path[i]);
        if (i > 0)
            partial_cost += original[full_path[i - 1]][full_path[i]];
    }

    int current_city = full_path[C - 1];

    // 移除壞掉的邊
    dist[u][v] = dist[v][u] = -1;

    // 剩餘城市重新 TSP
    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    int new_mask = visited_mask;
    int result_cost = tsp(new_mask, current_city, current_city);
    int new_path[MAXN];
    reconstruct_path(new_mask, current_city, new_path);

    // 輸出路徑
    for (int i = 0; i < C; i++)
        printf("%d ", full_path[i] + 1); // 原路徑保留
    int tmp = current_city;
    for (int i = 0; i < N - C; i++) {
        printf("%d ", new_path[i] + 1);
    }
    printf("\n");

    printf("%d\n", partial_cost + result_cost);
    return 0;
}
