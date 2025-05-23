#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<locale.h>

#define MAX_N 10
#define INF 0x3f3f3f3f

int path[MAX_N], path_idx = 0;  // 儲存行進路徑

// 計算最小值
int min(int a, int b) { return (a < b) ? a : b; }

// TSP 遞迴函式（記錄路徑）
int tsp(int dp[][1 << MAX_N], int dist[][MAX_N], int pre[][MAX_N], int cur, int mask, int N) {
    if (dp[cur][mask] >= 0) return dp[cur][mask];
    if (mask == (1 << N) - 1) return 0; // 已訪問所有城市

    int min_cost = INF, next_city = -1;
    for (int next = 0; next < N; next++) {
        if (!(mask & (1 << next)) && dist[cur][next] != INF) {  // 若未訪問且路徑可行
            int cost = dist[cur][next] + tsp(dp, dist, pre, next, mask | (1 << next), N);
            if (cost < min_cost) {
                min_cost = cost;
                next_city = next;
            }
        }
    }
    pre[cur][mask] = next_city;  // 記錄下一個城市
    return dp[cur][mask] = min_cost;
}

// 構建路徑
void build_path(int pre[][MAX_N], int start, int N) {
    int mask = 1, cur = start;
    path_idx = 0;

    while (cur != -1) {
        path[path_idx++] = cur + 1;  // 存入路徑（+1 使符合城市編號）
        cur = pre[cur][mask];
        mask |= (1 << (cur - 1));
    }
}

// 計算最短路徑並輸出完整行進路徑
void calculateRoute(int N, int dist[MAX_N][MAX_N], int C, int u, int v) {
    int dp[MAX_N][1 << MAX_N], pre[MAX_N][1 << MAX_N];

    // 初始化 DP 陣列
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < (1 << MAX_N); j++)
            dp[i][j] = -1, pre[i][j] = -1;

    // **步驟 1：求解初始 TSP**
    int start = 0; // 從城市 1 出發
    int min_cost = tsp(dp, dist, pre, start, 1, N);

    // 構建並輸出初始路徑
    build_path(pre, start, N);
    printf("初始路徑: ");
    for (int i = 0; i < path_idx; i++) printf("%d ", path[i]);
    printf("\n初始最短路徑距離: %d\n", min_cost);

    // **步驟 2：道路封閉，更新距離矩陣**
    dist[u-1][v-1] = dist[v-1][u-1] = INF;

    // **步驟 3：重新計算 TSP**
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < (1 << MAX_N); j++)
            dp[i][j] = -1, pre[i][j] = -1;  // 重置 DP 陣列

    min_cost = tsp(dp, dist, pre, C-1, (1 << (C-1)), N);

    // 構建並輸出修正後的路徑
    build_path(pre, C-1, N);
    printf("修正後路徑: ");
    for (int i = 0; i < path_idx; i++) printf("%d ", path[i]);
    printf("\n修正後最短路徑距離: %d\n", min_cost);
}

int main() {
    setlocale(LC_ALL, ".UTF8");
    int N, C, u, v;
    printf("輸入城市數量（N <= 10）: ");
    scanf("%d", &N);

    int dist[MAX_N][MAX_N];
    printf("輸入距離矩陣:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == -1) dist[i][j] = INF; // 轉換為不可行路徑
        }

    printf("輸入道路封閉信息: \n");
    scanf("%d %d %d", &C, &u, &v);

    calculateRoute(N, dist, C, u, v);

    return 0;
}