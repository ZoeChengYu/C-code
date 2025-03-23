#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 檢查字串開頭與結尾是否符合規範
int isValid(char *str) {
    int len = strlen(str);
    if (len == 0) return 0; // 空字串直接不合法
    if (!(isalpha(str[0]) || str[0] == '_') || !(isalpha(str[len - 1]) || str[len - 1] == '_')) {
        return 0; // 開頭或結尾不符合
    }
    return 1;
}

// 反轉字串
void reverseString(char *str, char *reversed) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
}

// 去除空白字元
void removeSpaces(char *str, char *result) {
    while (*str) {
        if (*str != ' ') {
            *result = *str;
            result++;
        }
        str++;
    }
    *result = '\0';
}

int main() {
    char str1[101], str2[101];
    // 輸入兩個字串
    fgets(str1, 101, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // 移除換行符號
    fgets(str2, 101, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // 檢查字串是否合法
    if (!isValid(str1) || !isValid(str2)) {
        printf("Error\n");
        return 0;
    }

    // 反轉字串
    char reversed1[101], reversed2[101];
    reverseString(str1, reversed1);
    reverseString(str2, reversed2);
    printf("%s\n%s\n", reversed1, reversed2);

    // 移除空白並比較長度
    char noSpaces1[101], noSpaces2[101];
    removeSpaces(str1, noSpaces1);
    removeSpaces(str2, noSpaces2);

    if (strlen(noSpaces1) > strlen(noSpaces2)) {
        printf("%s\n", str1);
    } else if (strlen(noSpaces1) < strlen(noSpaces2)) {
        printf("%s\n", str2);
    } else {
        printf("%s\n", str1);
    }

    return 0;
}
