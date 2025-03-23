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
    int nage=1;
    if (denominator == 0) {
        printf("Error\n");
        return;
    }
    if((numerator<0&&denominator>0)||(numerator>=0&&denominator<0)){
        nage=-1;
    }
    int whole = numerator / denominator; // 計算整數部分
    numerator = abs(numerator % denominator); // 計算餘數
    if (whole != 0 && numerator != 0) { // 帶分數
        printf("%d(%d/%d)\n", whole, numerator, denominator);
    } else if (numerator == 0) { // 整數
        printf("%d\n", whole);
    } else { // 真分數
        printf("%d/%d\n", nage*numerator, denominator);
    }
}

int main() {
    char continueflag = 'y'; // 是否繼續
    int numlist[20],denlist[20],i=0;

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

        // 輸入是否繼續運算
        scanf(" %c", &continueflag);

        // 進行計算
        if (den1 == 0 || den2 == 0) { // 分母為 0 的例外處理
            numlist[i]=1;
            denlist[i]=0;
            i++;
            continue;
        }

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
                    numlist[i]=1;
                    denlist[i]=0;
                    i++;
                    continue;
                }
                resNum = num1 * den2;
                resDen = num2 * den1;
                break;
            default:
                numlist[i]=1;
                denlist[i]=0;
                i++;
                continue;
        }

        // 化簡並輸出結果
        simplify(&resNum, &resDen);
        //printf("%d/%d\n",resNum,resDen);
        numlist[i]=resNum;
        denlist[i]=resDen;
        i++;
    }
    for(int j=0;j<i;j++){
    printResult(numlist[j], denlist[j]);
    }
}