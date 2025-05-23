#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_s {
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].score);
    }
}

void getHigh(student_t s[], int n, char name[], int *highScore) {
    *highScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score > *highScore) {
            *highScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

void getLow(student_t s[], int n, char name[], int *lowScore) {
    *lowScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score < *lowScore) {
            *lowScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

int getAverage(student_t s[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i].score;
    }
    return sum / n;
}

int compareScores(const void *a, const void *b) {
    student_t *s1 = (student_t *)a;
    student_t *s2 = (student_t *)b;
    return s1->score - s2->score;
}

int getMedian(student_t s[], int n) {
    qsort(s, n, sizeof(student_t), compareScores);
    if (n % 2 == 1) {
        return s[n / 2].score;
    } else {
        return (s[n / 2 - 1].score + s[n / 2].score) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    student_t students[15];

    input(students, n);

    char highName[50], lowName[50];
    int highScore, lowScore;

    getHigh(students, n, highName, &highScore);
    getLow(students, n, lowName, &lowScore);

    printf("%s %d\n", highName, highScore);
    printf("%s %d\n", lowName, lowScore);
    printf("%d\n", getAverage(students, n));
    printf("%d\n", getMedian(students, n));

    return 0;
}
