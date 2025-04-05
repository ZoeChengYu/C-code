#include <stdio.h>
#include <string.h>

void transtype(const char *input, int *output, int *size, int *isNegative) {
    *size = strlen(input);
    *isNegative = (input[0] == '-') ? 1 : 0;
    for (int i = *isNegative; i < *size; i++) {
        output[*size - i - 1] = input[i] - '0';
    }
    if (*isNegative) (*size)--; // 排除負號影響
}

void addition(int *a, int alen, int *b, int blen, int *result, int *rlen) {
    int carry = 0;
    *rlen = 0;
    for (int i = 0; i < alen || i < blen || carry; i++) {
        int sum = carry;
        if (i < alen) sum += a[i];
        if (i < blen) sum += b[i];
        result[(*rlen)++] = sum % 10;
        carry = sum / 10;
    }
}

void subtraction(int *a, int alen, int *b, int blen, int *result, int *rlen, int *isNegative) {
    *isNegative = 0;

    // 逐位比較，確保較大數減較小數
    if (alen < blen) {
        *isNegative = 1;
    } else if (alen == blen) {
        for (int i = alen - 1; i >= 0; i--) {
            if (a[i] < b[i]) {
                *isNegative = 1;
                break;
            } else if (a[i] > b[i]) {
                break;
            }
        }
    }

    // 若 A < B，交換 A 和 B
    if (*isNegative) {
        int *temp = a; a = b; b = temp;
        int tempLen = alen; alen = blen; blen = tempLen;
    }

    *rlen = 0;
    int borrow = 0;
    for (int i = 0; i < alen; i++) {
        int sub = a[i] - borrow - (i < blen ? b[i] : 0);
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[(*rlen)++] = sub;
    }

    // 移除前導 0
    while (*rlen > 1 && result[*rlen - 1] == 0) (*rlen)--;
}



void multiplication(int *a, int alen, int *b, int blen, int *result, int *rlen) {
    *rlen = alen + blen;
    memset(result, 0, (*rlen) * sizeof(int));
    for (int i = 0; i < alen; i++) {
        for (int j = 0; j < blen; j++) {
            result[i + j] += a[i] * b[j];
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
    while (*rlen > 1 && result[*rlen - 1] == 0) (*rlen)--;
}

void print_result(int *result, int rlen, int isNegative) {
    if (rlen == 1 && result[0] == 0) {
        printf("0\n");
        return;
    }

    if (isNegative) printf("-");
    for (int i = rlen - 1; i >= 0; i--) printf("%d", result[i]);
    printf("\n");
}


int main() {
    char inputA[102], inputB[102];
    int A[101] = {0}, B[101] = {0}, result[202] = {0};
    int alen, blen, rlen, isNegativeA, isNegativeB, isNegativeResult;

    // 讀取輸入
    scanf("%s %s", inputA, inputB);

    // 轉換數據
    transtype(inputA, A, &alen, &isNegativeA);
    transtype(inputB, B, &blen, &isNegativeB);

    // **加法 (若 A 和 B 符號相反，實際上是做減法)**
    if (isNegativeA == isNegativeB) {
        // 同號直接相加
        addition(A, alen, B, blen, result, &rlen);
        print_result(result, rlen, isNegativeA);
    } else {
        // 異號，轉為減法 (較大數 - 較小數)
        int isFinalNegative = 0;
        subtraction(A, alen, B, blen, result, &rlen, &isFinalNegative);
        isFinalNegative=isNegativeA^isFinalNegative;
        print_result(result, rlen, isFinalNegative);
    }

    // **減法**
    if (isNegativeA != isNegativeB) {  
        // 異號時，減法變成加法 (A - (-B) = A + B)
        addition(A, alen, B, blen, result, &rlen);
        print_result(result, rlen, isNegativeA);
    } else {  
        // 同號時，正常減法
        int isFinalNegative = 0;
        subtraction(A, alen, B, blen, result, &rlen, &isFinalNegative);
        isFinalNegative=isNegativeA^isFinalNegative;
        print_result(result, rlen, isFinalNegative);
    }

    // **乘法**
    multiplication(A, alen, B, blen, result, &rlen);
    print_result(result, rlen, isNegativeA ^ isNegativeB);  // 異或處理負號

    return 0;
}
