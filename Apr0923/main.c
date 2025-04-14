#include <stdio.h>
#include <stdlib.h>  // malloc 和 free

void addtion(int big, int small, int (*data)[2], int *index) {
    int flag = 1;
    for (int i = 0; i < *index; i++) {
        if (big == data[i][0] && small == data[i][1]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        data[*index][0] = big;
        data[*index][1] = small;
        (*index)++;
    }
}

int compare(int a[2], int b[2]) {
    if (a[0] != b[0]) return a[0] - b[0];
    return a[1] - b[1];
}

void merge(int (*data)[2], int left, int mid, int right) {
    int size = right - left + 1;
    int (*temp)[2] = malloc(size * sizeof(int[2]));

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (compare(data[i], data[j]) <= 0) {
            temp[k][0] = data[i][0];
            temp[k][1] = data[i][1];
            i++;
        } else {
            temp[k][0] = data[j][0];
            temp[k][1] = data[j][1];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k][0] = data[i][0];
        temp[k][1] = data[i][1];
        i++; k++;
    }

    while (j <= right) {
        temp[k][0] = data[j][0];
        temp[k][1] = data[j][1];
        j++; k++;
    }

    for (int m = 0; m < k; m++) {
        data[left + m][0] = temp[m][0];
        data[left + m][1] = temp[m][1];
    }

    free(temp);
}

void mergeSort(int (*data)[2], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

int main() {
    int N;
    scanf("%d", &N);

    int *list = malloc(N * sizeof(int));
    int (*data)[2] = malloc(N * N * sizeof(int[2]));  // 最多 N*N 個 pair（理論最大）

    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }

    int index = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (list[i] > list[j]) {
                addtion(list[i], list[j], data, &index);
            }
        }
    }

    //printf("Total pairs: %d\n", index);
    if (index==0)printf("0");
    if (index > 0) {
        mergeSort(data, 0, index - 1);
    }

    for (int i = 0; i < index; i++) {
        printf("(%d,%d)\n", data[i][0], data[i][1]);
    }

    free(list);
    free(data);

    return 0;
}
