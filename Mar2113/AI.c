#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 函數：將 M 進制數字轉換為十進制
int toDecimal(int base, char *data) {
    char *list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int length = strlen(data);
    int total = 0;

    for (int i = 0; i < length; i++) {
        char c = data[i];
        int value = strchr(list, c) - list;
        total += value * pow(base, length - i - 1);
    }

    return total;
}

// 函數：將十進制數字轉換為 N 進制
void fromDecimal(int data, int base, char *result) {
    char *list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i = 0;
    if(data==0){
        result[0]=list[0];
        result[1]='\0';
    }else{

    while (data > 0) {
        result[i] = list[data % base];
        data /= base;
        i++;
    }

    // 倒序排列，因為計算是從最低位開始的
    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    result[i] = '\0';} // 添加結尾符號
}

int main() {
    int M, N;
    char datas[11], result[50]; // 假設最大長度為 10 位數

    // 輸入
    scanf("%d", &M);
    scanf("%s", datas);
    scanf("%d", &N);
    if(M<=1||N<=1){
        printf("%d",0);
    }else{

    // M 進制轉十進制
    int decnum = toDecimal(M, datas);

    // 十進制轉 N 進制
    fromDecimal(decnum, N, result);

    // 輸出結果
    printf("%s\n", result);

    return 0;
    }
}