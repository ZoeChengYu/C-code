#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 51

// 檢查是否符合 k 交錯規則
int longest_k_alternating(const char *s, int k) {
    int len = strlen(s);
    int group_len[MAX_LEN] = {0}; // 儲存每段長度
    int is_upper[MAX_LEN] = {0};  // 儲存每段是大寫(1)或小寫(0)
    int group_cnt = 0;

    // 將字串拆分為大寫/小寫群組
    int i = 0;
    while (i < len) {
        int j = i;
        int upper = isupper(s[i]);
        while (j < len && isupper(s[j]) == upper) {
            j++;
        }
        group_len[group_cnt] = j - i;
        is_upper[group_cnt] = upper;
        group_cnt++;
        i = j;
    }

    // 檢查最大交錯長度
    int max_len = 0;
    for (i = 0; i + 1 < group_cnt; i++) {
        int curr = 0;
        int flag = 1;
        int prev_type = is_upper[i];
        int j = i;
        while (j < group_cnt && group_len[j] >= k && is_upper[j] != prev_type) {
            curr += k;
            prev_type = is_upper[j];
            j++;
            flag ^= 1;
        }
        if (j < group_cnt && group_len[j] >= k && is_upper[j] != prev_type) {
            curr += k;
        }
        if (curr > max_len) max_len = curr;
    }
    return max_len;
}

int main() {
    int N;
    scanf("%d", &N);
    char str[MAX_LEN];
    int k;

    for (int i = 0; i < N; i++) {
        scanf("%s %d", str, &k);
        int result = longest_k_alternating(str, k);
        printf("%d\n", result);
    }
    return 0;
}
