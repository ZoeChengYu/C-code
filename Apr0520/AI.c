#include <stdio.h>

typedef struct {
    int top, front, right;
} Dice;

void roll(Dice* d, int dir) {
    int temp;
    if (dir == 1) { // forward
        temp = d->top;
        d->top = 7 - d->front;
        d->front = temp;
    } else if (dir == 2) { // backward
        temp = d->top;
        d->top = d->front;
        d->front = 7 - temp;
    } else if (dir == 3) { // right
        temp = d->top;
        d->top = 7 - d->right;
        d->right = temp;
    } else if (dir == 4) { // left
        temp = d->top;
        d->top = d->right;
        d->right = 7 - temp;
    }
}

int calculate_score(int a, int b, int c, int d) {
    int count[7] = {0}; // index 1~6
    count[a]++;
    count[b]++;
    count[c]++;
    count[d]++;
    
    int pair = 0, triple = 0, four = 0;
    int pairs[2] = {0}, pair_idx = 0;
    int unique_sum = 0;
    
    for (int i = 1; i <= 6; i++) {
        if (count[i] == 4) return 18; // all same
        if (count[i] == 3) triple = 1;
        if (count[i] == 2) {
            pair++;
            pairs[pair_idx++] = i;
        }
        if (count[i] == 1) unique_sum += i;
    }
    
    if (triple || (pair == 0)) return 0; // all different or three same
    if (pair == 2) {
        // two different pairs
        return pairs[0] > pairs[1] ? pairs[0] * 2 : pairs[1] * 2;
    } else if (pair == 1) {
        // one pair + two other different
        return unique_sum;
    }
    
    return 0;
}

int main() {
    int time;
    scanf("%d", &time);
    
    Dice dice[4];
    for (int i = 0; i < 4; i++) {
        dice[i].top = 1;
        dice[i].front = 4;
        dice[i].right = 2;
    }

    for (int t = 0; t < time; t++) {
        int move[4];
        for (int i = 0; i < 4; i++) {
            scanf("%d", &move[i]);
            roll(&dice[i], move[i]);
        }
    }

    int tops[4];
    for (int i = 0; i < 4; i++) {
        tops[i] = dice[i].top;
    }

    int score = calculate_score(tops[0], tops[1], tops[2], tops[3]);
    printf("%d\n", score);

    return 0;
}
