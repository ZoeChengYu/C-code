#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_punctuation(char ch) {
    return ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == ';' || ch == ':';
}

// 拆分單字為 base 和結尾標點符號（若有）
void split_word(const char* in, char* base, char* punct) {
    int len = strlen(in);
    if (len > 1 && is_valid_punctuation(in[len - 1])) {
        strcpy(punct, in + len - 1);
        strncpy(base, in, len - 1);
        base[len - 1] = '\0';
    } else {
        strcpy(base, in);
        punct[0] = '\0';
    }
}

// 判斷單字是否與目標詞相符
int is_word_match(const char *word, const char *target) {
    char base[100], punct[10];
    split_word(word, base, punct);
    for (int i = 0; base[i]; ++i) {
        if (base[i] == '\'' || base[i] == '`')
            return 0;
    }
    return strcmp(base, target) == 0;
}

// 替換單詞
void replaceWord(char word[][20], const char *P, const char *Q, int n) {
    for (int i = 0; i < n; i++) {
        if (is_word_match(word[i], P)) {
            char punct[10], tmp[100];
            char base[100];
            split_word(word[i], base, punct);
            sprintf(tmp, "%s%s", Q, punct);
            strcpy(word[i], tmp);
        }
    }
    for (int i = 0; i < n; i++) printf("%s%c", word[i], i == n - 1 ? '\n' : ' ');
}

// 單詞前插入
void insertBeforeWord(char word[][20], const char *P, const char *Q, int n) {
    char result[200][20];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (is_word_match(word[i], P)) {
            strcpy(result[idx++], Q);
        }
        strcpy(result[idx++], word[i]);
    }
    for (int i = 0; i < idx; i++) printf("%s%c", result[i], i == idx - 1 ? '\n' : ' ');
}

// 單詞後插入
void insertAfterWord(char word[][20], const char *P, const char *Q, int n) {
    char result[200][20];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        strcpy(result[idx++], word[i]);
        if (is_word_match(word[i], P)) {
            strcpy(result[idx++], Q);
        }
    }
    for (int i = 0; i < idx; i++) printf("%s%c", result[i], i == idx - 1 ? '\n' : ' ');
}

// 單詞刪除
void deleteWord(char word[][20], const char *P, int n) {
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (!is_word_match(word[i], P)) {
            if (!first) printf(" ");
            printf("%s", word[i]);
            first = 0;
        }
    }
    printf("\n");
}

// 單詞反轉
void reverseWord(char word[][20], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%s%c", word[i], i == 0 ? '\n' : ' ');
    }
}

int main() {
    char A[200], P[20], Q[20];
    fgets(A, sizeof(A), stdin);
    scanf(" %s", P);
    scanf(" %s", Q);

    int c = 0;
    char word[100][20];
    char original[100][20];
    char *ss = strtok(A, " \n");
    while (ss != NULL) {
        strcpy(word[c], ss);
        strcpy(original[c], ss); // 備份原始詞
        c++;
        ss = strtok(NULL, " \n");
    }

    memcpy(word, original, sizeof(word));
    replaceWord(word, P, Q, c);

    memcpy(word, original, sizeof(word));
    insertBeforeWord(word, P, Q, c);

    memcpy(word, original, sizeof(word));
    insertAfterWord(word, P, Q, c);

    memcpy(word, original, sizeof(word));
    deleteWord(word, P, c);

    memcpy(word, original, sizeof(word));
    reverseWord(word, c);

    return 0;
}
