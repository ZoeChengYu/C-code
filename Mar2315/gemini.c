#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gdb(int a, int b) {
    return b == 0 ? abs(a) : gdb(b, a % b);
}

void findmb(char *m, char *b, int x1, int y1, int x2, int y2) {
    int Md = y2 - y1;
    int Dd = x2 - x1;
    int Bd = x2 * y1 - x1 * y2;

    m[0] = '\0';
    b[0] = '\0';
    int g = gdb(Md, Dd);
    int s = gdb(Bd, Dd);

    if (Dd == 0) {
        strcpy(m, "undefined");
        if (Bd == 0) {
            sprintf(b, "0");
        } else {
            sprintf(b, "%d", Bd / Dd);
        }
    } else {
        if (Md % Dd == 0) {
            sprintf(m, "%d", Md / Dd);
        } else {
            sprintf(m, "%d/%d", Md / g, Dd / g);
        }

        if (Bd % Dd == 0) {
            sprintf(b, "%d", Bd / Dd);
        } else {
            sprintf(b, "%d/%d", Bd / s, Dd / s);
        }
    }
}

void prints(char *m, char *b) {
    if (strcmp(m, "0") == 0) {
        printf("y = %s", b);
    } else if (strcmp(m, "1") == 0) {
        int b_val = atoi(b);
        if (b_val > 0) {
            printf("y = x + %s", b);
        } else if (b_val < 0) {
            sprintf(b, "%d/%d", abs(atoi(b))/gdb(abs(atoi(b)),atoi(b+strlen(b)-strlen(strchr(b,'/'))+1)),atoi(b+strlen(b)-strlen(strchr(b,'/'))+1));
            printf("y = x - %s", b);
        } else {
            printf("y = x");
        }
    } else if (strcmp(m, "-1") == 0) {
        int b_val = atoi(b);
        if (b_val > 0) {
            printf("y = -x + %s", b);
        } else if (b_val < 0) {
            sprintf(b, "%d/%d", abs(atoi(b))/gdb(abs(atoi(b)),atoi(b+strlen(b)-strlen(strchr(b,'/'))+1)),atoi(b+strlen(b)-strlen(strchr(b,'/'))+1));
            printf("y = -x - %s", b);
        } else {
            printf("y = -x");
        }
    } else if (strcmp(m, "undefined") == 0) {
        printf("x = %s", b);
    } else {
        int b_val = atoi(b);
        if (b_val > 0) {
            printf("y = %sx + %s", m, b);
        } else if (b_val < 0) {
            sprintf(b, "%d/%d", abs(atoi(b))/gdb(abs(atoi(b)),atoi(b+strlen(b)-strlen(strchr(b,'/'))+1)),atoi(b+strlen(b)-strlen(strchr(b,'/'))+1));
            printf("y = %sx - %s", m, b);
        } else {
            printf("y = %sx", m);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        char m[46], b[46];
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        findmb(m, b, x1, y1, x2, y2);
        prints(m, b);
    }
    return 0;
}