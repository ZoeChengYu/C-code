#include <stdio.h>
#include <string.h>

#define MAX 41

int A[MAX], B[MAX], alen = 0, blen = 0;
char a_c[MAX], b_c[MAX];

void transtype(char *input, int *output, int *size) {
    *size = strlen(input);
    for (int i = 0; i < *size; i++) {
        output[*size - i - 1] = input[i] - '0';
    }
}

int compare(int *A, int alen, int *B, int blen) {
    if (alen != blen)
        return alen > blen;
    for (int i = alen - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return 1; // 相等也算 A >= B
}

void subtract(int *A, int *alen, int *B, int blen) {
    for (int i = 0; i < *alen; i++) {
        A[i] -= (i < blen ? B[i] : 0);
        if (A[i] < 0) {
            A[i] += 10;
            A[i + 1]--;
        }
    }
    while (*alen > 0 && A[*alen - 1] == 0) (*alen)--;
}

void multiply_digit(int *B, int blen, int digit, int *result, int *rlen) {
    int carry = 0;
    for (int i = 0; i < blen; i++) {
        int tmp = B[i] * digit + carry;
        result[i] = tmp % 10;
        carry = tmp / 10;
    }
    *rlen = blen;
    if (carry) result[(*rlen)++] = carry;
}

void divide(int *A, int alen, int *B, int blen) {
    int quotient[MAX] = {0}, qlen = 0;
    int remainder[MAX] = {0}, rlen = 0;

    for (int i = alen - 1; i >= 0; i--) {
        for (int j = rlen; j > 0; j--) remainder[j] = remainder[j - 1];
        remainder[0] = A[i];
        if (rlen == 0 || remainder[rlen] != 0) rlen++;

        int digit = 0;
        int tmp[MAX], tmplen;
        while (1) {
            multiply_digit(B, blen, digit + 1, tmp, &tmplen);
            if (!compare(remainder, rlen, tmp, tmplen)) break;
            digit++;
        }

        if (digit > 0) {
            multiply_digit(B, blen, digit, tmp, &tmplen);
            subtract(remainder, &rlen, tmp, tmplen);
        }

        quotient[qlen++] = digit;
    }

    // 去除前導 0
    int start = 0;
    while (start < qlen - 1 && quotient[start] == 0) start++;

    for (int i = start; i < qlen; i++) printf("%d", quotient[i]);
    printf("\n");

    if (rlen == 0) printf("0\n");
    else {
        for (int i = rlen - 1; i >= 0; i--) {
            printf("%d", remainder[i]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%s", a_c);
    scanf("%s", b_c);
    transtype(a_c, A, &alen);
    transtype(b_c, B, &blen);
    divide(A, alen, B, blen);
    return 0;
}
