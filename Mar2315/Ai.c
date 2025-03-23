#include <stdio.h>
#include <stdlib.h>

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

// 打印化簡後的直線方程式
void printLineEquation(int mNumerator, int mDenominator, int bNumerator, int bDenominator) {
    // 處理 m
    if (mDenominator == 0) { // 無效的直線
        printf("Error\n");
        return;
    }

    if (mNumerator == 0) { // m = 0，只輸出 b
        if (bNumerator != 0) {
            if (bDenominator == 1) {
                printf("y = %d\n", bNumerator);
            } else {
                printf("y = %d/%d\n", bNumerator, bDenominator);
            }
        } else {
            printf("y = 0\n");
        }
    } else {
        // m 不為 0
        if (mNumerator == mDenominator) { // m = 1
            printf("y = x");
        } else if (mNumerator == -mDenominator) { // m = -1
            printf("y = -x");
        } else {
            if (mDenominator == 1) {
                printf("y = %dx", mNumerator);
            } else {
                printf("y = %d/%dx", mNumerator, mDenominator);
            }
        }

        // 處理 b
        if (bNumerator > 0) {
            if (bDenominator == 1) {
                printf(" + %d", bNumerator);
            } else {
                printf(" + %d/%d", bNumerator, bDenominator);
            }
        } else if (bNumerator < 0) {
            if (bDenominator == 1) {
                printf(" - %d", -bNumerator);
            } else {
                printf(" - %d/%d", -bNumerator, bDenominator);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // 計算 m 和 b
        int mNumerator = y2 - y1;
        int mDenominator = x2 - x1;
        int bNumerator = x2 * y1 - x1 * y2;
        int bDenominator = x2 - x1;

        // 化簡 m 和 b
        simplify(&mNumerator, &mDenominator);
        simplify(&bNumerator, &bDenominator);

        // 輸出結果
        printLineEquation(mNumerator, mDenominator, bNumerator, bDenominator);
    }

    return 0;
}
