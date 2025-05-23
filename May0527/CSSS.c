#include <stdio.h>
#include <string.h>
#include <ctype.h>

void split_word(const char* in, char* base, char* punct) {
    int len = strlen(in);
    if (len > 1 && ispunct(in[len - 1])) {
        strcpy(punct, in + len - 1);
        strncpy(base, in, len - 1);
        base[len - 1] = '\0';
    } else {
        strcpy(base, in);
        punct[0] = '\0';
    }
}

int is_word_match(const char *word, const char *target) {
    char base[20], punct[5];
    split_word(word, base, punct);
    return strcmp(base, target) == 0;
}

void replaceWord(char word[][20], const char *P, const char *Q, int count) {
    for (int i = 0; i < count; i++) {
        char base[20], punct[5];
        split_word(word[i], base, punct);
        if (strcmp(base, P) == 0) {
            sprintf(word[i], "%s%s", Q, punct);
        }printf("Before: %s | After: %s\n", word[i], Q);
    }
    
}

void insertBeforeWord(char word[][20], const char *P, const char *Q, int count) {
    char temp[100][20];
    int index = 0;
    for (int i = 0; i < count; i++) {
        char base[20], punct[5];
        split_word(word[i], base, punct);
        if (strcmp(base, P) == 0) {
            strcpy(temp[index++], Q);
        }
        strcpy(temp[index++], word[i]);
    }
    for (int i = 0; i < index; i++) {
        strcpy(word[i], temp[i]);printf("Insert Before: %s\n", word[i]);
    }
    
}

void insertAfterWord(char word[][20], const char *P, const char *Q, int count) {
    char temp[100][20];
    int index = 0;
    for (int i = 0; i < count; i++) {
        strcpy(temp[index++], word[i]);
        char base[20], punct[5];
        split_word(word[i], base, punct);
        if (strcmp(base, P) == 0) {
            strcpy(temp[index++], Q);
        }
    }
    for (int i = 0; i < index; i++) {
        strcpy(word[i], temp[i]);printf("Insert After: %s\n", word[i]);
    }
}

void deleteWord(char word[][20], const char *P, int count) {
    char temp[100][20];
    int index = 0;
    for (int i = 0; i < count; i++) {
        char base[20], punct[5];
        split_word(word[i], base, punct);
        if (strcmp(base, P) != 0) {
            strcpy(temp[index++], word[i]);
        }
    }
    for (int i = 0; i < index; i++) {
        strcpy(word[i], temp[i]);printf("Deleted: %s\n", word[i]);
    }
}

void reverseWord(char word[][20], int count) {
    for (int i = 0; i < count / 2; i++) {
        char temp[20];
        strcpy(temp, word[i]);
        strcpy(word[i], word[count - i - 1]);
        strcpy(word[count - i - 1], temp);printf("Reversed: %s\n", word[i]);
    }
}

int main() {
    char A[200], P[20], Q[20];

    fgets(A, sizeof(A), stdin);
    scanf(" %s", P);
    scanf(" %s", Q);

    int c = 0;
    char word[100][20];
    char *ss;

    ss = strtok(A, " \n");
    while (ss != NULL) {
        strcpy(word[c++], ss);
        ss = strtok(NULL, " \n");
    }

    replaceWord(word, P, Q, c);
    for (int i = 0; i < c; i++) printf("%s ", word[i]);
    printf("\n");

    insertBeforeWord(word, P, Q, c);
    for (int i = 0; i < c; i++) printf("%s ", word[i]);
    printf("\n");

    insertAfterWord(word, P, Q, c);
    for (int i = 0; i < c; i++) printf("%s ", word[i]);
    printf("\n");

    deleteWord(word, P, c);
    for (int i = 0; i < c; i++) printf("%s ", word[i]);
    printf("\n");

    reverseWord(word, c);
    for (int i = 0; i < c; i++) printf("%s ", word[i]);
    printf("\n");

    return 0;
}