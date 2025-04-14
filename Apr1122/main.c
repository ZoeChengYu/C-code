#include <stdio.h>
#include <stdlib.h>

void fill(int **list, int row, int col, int size, int val) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            list[row + i][col + j] = val;
}

void parse(char *data, int *pos, int **list, int row, int col, int size) {
    char current = data[*pos];
    (*pos)++;

    if (current == '0' || current == '1') {
        fill(list, row, col, size, current - '0');
    } else if (current == '2') {
        int half = size / 2;
        parse(data, pos, list, row, col, half);                   // top-left
        parse(data, pos, list, row, col + half, half);            // top-right
        parse(data, pos, list, row + half, col, half);            // bottom-left
        parse(data, pos, list, row + half, col + half, half);     // bottom-right
    }
}

int main() {
    char *data = malloc(sizeof(char) * 50);
    int len;

    fgets(data, 100, stdin);
    scanf("%d", &len);

    // Dynamic 2D array
    int **list = malloc(len * sizeof(int *));
    for (int i = 0; i < len; i++) {
        list[i] = malloc(len * sizeof(int));
        for (int j = 0; j < len; j++) list[i][j] = 8;
    }

    int pos = 0;
    parse(data, &pos, list, 0, 0, len);
    int count=0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(list[i][j]==1){
                printf("%d,%d\n",i,j);
                count++;
            }
        }
    }
    if(count==0){
        printf("all white");
    }

    // Cleanup
    for (int i = 0; i < len; i++) free(list[i]);
    free(list);
    free(data);

    return 0;
}
