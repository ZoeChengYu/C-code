#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transtype(char *input, int *output, int *size) {
    *size = strlen(input);
    for (int i = 0; i < *size; i++) {
        output[*size - i - 1] = input[i] - '0';
    }
}



int main() {
    int A[41], B[41], alen = 0, blen = 0;
    char a_c[41], b_c[41];
    scanf("%s %s", a_c, b_c);
    transtype(a_c, A, &alen);
    transtype(b_c, B, &blen);

}