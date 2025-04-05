#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

// 判斷子序列是否有重複數字
int has_unique_elements(int *subseq, int m) {
    int freq[10] = {0}; // 數字範圍 0-9
    for (int i = 0; i < m; i++) {
        if (freq[subseq[i]] > 0) {
            return 0; // 發現重複
        }
        freq[subseq[i]]++;
    }
    return 1; // 無重複
}

int main() {
    int m, a = 0;
    int sequence[MAX_LEN];
    int subsequences[MAX_LEN][MAX_LEN]; // 儲存符合條件的子序列
    int subseq_count = 0, total_count = 0;
    char buffer[100]; // 暫存輸入的整數序列

    // 讀取 m 值
    fgets(buffer, sizeof(buffer), stdin);
    m = atoi(buffer);

    // 讀取整數序列
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL && a < MAX_LEN) {
        sequence[a++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // 滑動視窗提取長度為 m 的子序列
    for (int i = 0; i <= a - m; i++) {
        int subseq[MAX_LEN];
        for (int j = 0; j < m; j++) {
            subseq[j] = sequence[i + j];
        }

        // 判斷子序列是否符合條件（無重複數字）
        if (has_unique_elements(subseq, m)) {
            total_count++;
            memcpy(subsequences[subseq_count], subseq, m * sizeof(int));
            subseq_count++;
        }
    }

    // **輸出結果**
    printf("%d\n", total_count);
    
    int unique_count = 0;
    int posad[MAX_LEN][MAX_LEN];

    // **去重**
    for (int i = 0; i < subseq_count; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (memcmp(subsequences[i], subsequences[j], m * sizeof(int)) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            memcpy(posad[unique_count], subsequences[i], m * sizeof(int));
            unique_count++;
        }
    }

    // **排序子序列（字典序）**
    for (int i = 0; i < unique_count - 1; i++) {
        for (int j = 0; j < unique_count - i - 1; j++) {
            int cmp = memcmp(posad[j], posad[j + 1], m * sizeof(int));
            if (cmp > 0) { // 若前者大於後者則交換
                int temp[MAX_LEN];
                memcpy(temp, posad[j], m * sizeof(int));
                memcpy(posad[j], posad[j + 1], m * sizeof(int));
                memcpy(posad[j + 1], temp, m * sizeof(int));
            }
        }
    }

    // **輸出**
    for (int i = 0; i < unique_count; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", posad[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
