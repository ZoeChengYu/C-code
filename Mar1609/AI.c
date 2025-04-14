#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isInteger(char *s) {
    int len = strlen(s);
    if (len < 1 || len > 50) return 0;

    int start = 0;
    if (s[0] == '-') {
        if (len == 2 && s[1] == '0') return 0; // ❌ -0 不合法
        if (len == 1) return 0; // 只有 '-' 也不合法
        start = 1;
    }

    if (s[start] == '0' && len - start > 1) return 0; // 多位數不能以0開頭，除了0本身

    for (int i = start; i < len; i++) {
        if (!isdigit(s[i])) return 0;
    }
    return 1;
}


int isFloat(char *s) {
    int len = strlen(s);
    if (len < 3 || len > 50) return 0;

    int start = 0, dotCount = 0;
    if (s[0] == '-') {
        if (len == 1) return 0;
        start = 1;
    }

    if (s[start] == '.' || s[len - 1] == '.') return 0;

    for (int i = start; i < len; i++) {
        if (s[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0;
        } else if (!isdigit(s[i])) {
            return 0;
        }
    }

    if (s[start] == '0' && s[start + 1] != '.') {
        if (len - start > 1) return 0;
    }

    return dotCount == 1;
}

int isVariable(char *s) {
    int len = strlen(s);
    if (len < 1 || len > 10) return 0;

    if (!(isalpha(s[0]) || s[0] == '_')) return 0;

    for (int i = 1; i < len; i++) {
        if (!(isalnum(s[i]) || s[i] == '_')) return 0;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    char input[55]; // 最多 50 個字元，加上結尾符號

    for (int i = 0; i < n; i++) {
        scanf("%s", input);

        if (isInteger(input)) {
            printf("integer\n");
        } else if (isFloat(input)) {
            printf("float\n");
        } else if (isVariable(input)) {
            printf("variable\n");
        } else {
            printf("string\n");
        }
    }
    return 0;
}
