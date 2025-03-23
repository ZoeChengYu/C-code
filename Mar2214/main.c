#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 計算最大公因數 (GCD)
int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

// 化簡分數
void simplify(int *numerator, int *denominator) {
    int divisor = gcd(*numerator, *denominator);
    *numerator /= divisor;
    *denominator /= divisor;
    if (*denominator < 0) { // 確保分母為正
        *numerator = -*numerator;
        *denominator = -*denominator;
    }
}

// 輸出結果
void printResult(int numerator, int denominator) {
    if (denominator == 0) {
        printf("Error\n");
        return;
    }

    int whole = numerator / denominator; // 計算整數部分
    numerator = abs(numerator % denominator); // 計算餘數
    if (whole != 0 && numerator != 0) { // 帶分數
        printf("%d(%d/%d)\n", whole, numerator, denominator);
    } else if (numerator == 0) { // 整數
        printf("%d\n", whole);
    } else { // 真分數
        printf("%d/%d\n", numerator, denominator);
    }
}

int main() {
    char continueflag = 'y'; // 是否繼續

    while (continueflag == 'y') {
        char fract1[20], fract2[20], operation;
        int num1, den1, num2, den2;

        // 輸入第一個分數
        scanf("%s", fract1);
        if (strchr(fract1, '(')) { // 處理帶分數
            int whole;
            sscanf(fract1, "%d(%d/%d)", &whole, &num1, &den1);
            num1 = whole * den1 + (whole < 0 ? -num1 : num1);
        } else { // 處理真分數或假分數
            sscanf(fract1, "%d/%d", &num1, &den1);
        }
        if (den1 == 0) { // 分母為 0
            printf("Error\n");
            continue;
        }

        // 輸入運算符號
        scanf(" %c", &operation);

        // 輸入第二個分數
        scanf("%s", fract2);
        if (strchr(fract2, '(')) { // 處理帶分數
            int whole;
            sscanf(fract2, "%d(%d/%d)", &whole, &num2, &den2);
            num2 = whole * den2 + (whole < 0 ? -num2 : num2);
        } else { // 處理真分數或假分數
            sscanf(fract2, "%d/%d", &num2, &den2);
        }
        if (den2 == 0) { // 分母為 0
            printf("Error\n");
            continue;
        }

        // 運算結果
        int resNum, resDen;
        switch (operation) {
            case '+':
                resNum = num1 * den2 + num2 * den1;
                resDen = den1 * den2;
                break;
            case '-':
                resNum = num1 * den2 - num2 * den1;
                resDen = den1 * den2;
                break;
            case '*':
                resNum = num1 * num2;
                resDen = den1 * den2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error\n");
                    continue;
                }
                resNum = num1 * den2;
                resDen = num2 * den1;
                break;
            default:
                printf("Error\n");
                continue;
        }

        // 化簡分數
        simplify(&resNum, &resDen);

        // 輸出計算結果
        printResult(resNum, resDen);

        // 詢問是否繼續
        scanf(" %c", &continueflag);
    }

    return 0;
}