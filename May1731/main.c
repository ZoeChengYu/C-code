#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum scoreType_s { G, GPA, S } scoreType_t;
typedef enum G_s { Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X } G_t;
typedef enum GPA_s { b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0 } GPA_t;
typedef enum S_s { b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0 } S_t;

typedef union student_s {
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

typedef struct {
    int id;
    student_t scores[10];
    int avg;
} studentInfo_t;

int M, N;
scoreType_t courseTypes[10];

G_t getG(char *s) {
    if (!strcmp(s, "A+")) return Aplus;
    if (!strcmp(s, "A")) return A;
    if (!strcmp(s, "A-")) return Aduce;
    if (!strcmp(s, "B+")) return Bplus;
    if (!strcmp(s, "B")) return B;
    if (!strcmp(s, "B-")) return Bduce;
    if (!strcmp(s, "C+")) return Cplus;
    if (!strcmp(s, "C")) return C;
    if (!strcmp(s, "C-")) return Cduce;
    if (!strcmp(s, "F")) return F;
    return X;
}

GPA_t getGPA(char *s) {
    if (!strcmp(s, "4.3")) return b4dot3;
    if (!strcmp(s, "4.0")) return b4dot0;
    if (!strcmp(s, "3.7")) return b3dot7;
    if (!strcmp(s, "3.3")) return b3dot3;
    if (!strcmp(s, "3.0")) return b3dot0;
    if (!strcmp(s, "2.7")) return b2dot7;
    if (!strcmp(s, "2.3")) return b2dot3;
    if (!strcmp(s, "2.0")) return b2dot0;
    if (!strcmp(s, "1.7")) return b1dot7;
    if (!strcmp(s, "1") || !strcmp(s, "1.0")) return b1;
    return b0;
}

S_t getS(char *s) {
    if (!strcmp(s, "90-100")) return b90to100;
    if (!strcmp(s, "85-89")) return b85to89;
    if (!strcmp(s, "80-84")) return b80to84;
    if (!strcmp(s, "77-79")) return b77to79;
    if (!strcmp(s, "73-76")) return b73to76;
    if (!strcmp(s, "70-72")) return b70to72;
    if (!strcmp(s, "67-69")) return b67to69;
    if (!strcmp(s, "63-66")) return b63to66;
    if (!strcmp(s, "60-62")) return b60to62;
    if (!strcmp(s, "1-59")) return b1to59;
    return b0to0;
}

int convertToScore(scoreType_t type, student_t s) {
    switch (type) {
        case G:
            switch (s.G) {
                case Aplus: return 95;
                case A: return 87;
                case Aduce: return 82;
                case Bplus: return 78;
                case B: return 75;
                case Bduce: return 70;
                case Cplus: return 68;
                case C: return 65;
                case Cduce: return 60;
                case F: return 50;
                case X: return 0;
            }
        case GPA:
            switch (s.GPA) {
                case b4dot3: return 95;
                case b4dot0: return 87;
                case b3dot7: return 82;
                case b3dot3: return 78;
                case b3dot0: return 75;
                case b2dot7: return 70;
                case b2dot3: return 68;
                case b2dot0: return 65;
                case b1dot7: return 60;
                case b1: return 50;
                case b0: return 0;
            }
        case S:
            switch (s.S) {
                case b90to100: return 95;
                case b85to89: return 87;
                case b80to84: return 82;
                case b77to79: return 78;
                case b73to76: return 75;
                case b70to72: return 70;
                case b67to69: return 68;
                case b63to66: return 65;
                case b60to62: return 60;
                case b1to59: return 50;
                case b0to0: return 0;
            }
        default:
            fprintf(stderr, "Invalid score value\n");
            return 0;
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    studentInfo_t *s1 = (studentInfo_t *)a;
    studentInfo_t *s2 = (studentInfo_t *)b;
    if (s1->avg != s2->avg)
        return s1->avg - s2->avg;
    return s1->id - s2->id;
}

int main() {
    scanf("%d", &M);
    char buf[20];
    for (int i = 0; i < M; i++) {
        scanf("%s", buf);
        if (strcmp(buf, "G") == 0) courseTypes[i] = G;
        else if (strcmp(buf, "GPA") == 0) courseTypes[i] = GPA;
        else courseTypes[i] = S;
    }

    scanf("%d", &N);
    studentInfo_t students[10];

    for (int i = 0; i < N; i++) {
        scanf("%d", &students[i].id);
        int total = 0;
        for (int j = 0; j < M; j++) {
            scanf("%s", buf);
            switch (courseTypes[j]) {
                case G:
                    students[i].scores[j].G = getG(buf);
                    break;
                case GPA:
                    students[i].scores[j].GPA = getGPA(buf);
                    break;
                case S:
                    students[i].scores[j].S = getS(buf);
                    break;
            }
            total += convertToScore(courseTypes[j], students[i].scores[j]);
        }
        students[i].avg = total / M;
    }

    qsort(students, N, sizeof(studentInfo_t), cmp);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", students[i].id, students[i].avg);
    }

    return 0;
}