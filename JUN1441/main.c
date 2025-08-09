#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 510

typedef struct {
    int id;
    int capacity;
} Room;

typedef struct {
    int id, students, start, end, duration;
} Course;

typedef struct {
    int course_id, room_id;
} Assignment;

int M, N, mode;
Room rooms[MAXN];
Course courses[MAXN];

int best_hours = 0, best_count = 0;
Assignment best_assignments[MAXN];

Assignment curr_assignments[MAXN];
int curr_hours = 0, curr_count = 0;

// 每間教室已排課的時間表
int room_schedule[MAXN][24]; // index: room_idx, time slot 0~23

int course_assigned[MAXN]; // 避免重複分配

int overlap(int s1, int e1, int s2, int e2) {
    return !(e1 <= s2 || e2 <= s1);
}

// 檢查這門課是否能排進這間教室
int can_assign(int room_idx, Course c) {
    if (mode >= 1 && c.students > rooms[room_idx].capacity) return 0;

    for (int t = c.start; t < c.end; t++) {
        if (room_schedule[room_idx][t]) return 0;
    }
    return 1;
}

void assign_course(int room_idx, Course c, int assign) {
    for (int t = c.start; t < c.end; t++) {
        room_schedule[room_idx][t] = assign;
    }
}

void dfs(int idx) {
    if (idx == N) {
        if (curr_hours > best_hours || (curr_hours == best_hours && curr_count > best_count)) {
            best_hours = curr_hours;
            best_count = curr_count;
            memcpy(best_assignments, curr_assignments, sizeof(Assignment) * curr_count);
        }
        return;
    }

    if (course_assigned[idx]) {
        dfs(idx + 1);
        return;
    }

    // 嘗試不選擇此課程（可剪枝）
    dfs(idx + 1);

    for (int r = 0; r < M; r++) {
        if (can_assign(r, courses[idx])) {
            assign_course(r, courses[idx], 1);
            course_assigned[idx] = 1;
            curr_assignments[curr_count++] = (Assignment){courses[idx].id, rooms[r].id};
            curr_hours += courses[idx].duration;

            dfs(idx + 1);

            assign_course(r, courses[idx], 0);
            course_assigned[idx] = 0;
            curr_count--;
            curr_hours -= courses[idx].duration;
        }
    }
}

int compare_assignment(const void *a, const void *b) {
    Assignment *x = (Assignment *)a;
    Assignment *y = (Assignment *)b;
    return x->course_id - y->course_id;
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &rooms[i].id, &rooms[i].capacity);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &courses[i].id, &courses[i].students, &courses[i].start, &courses[i].end);
        courses[i].duration = courses[i].end - courses[i].start;
    }
    scanf("%d", &mode);

    dfs(0);

    qsort(best_assignments, best_count, sizeof(Assignment), compare_assignment);

    printf("max hours %d\n", best_hours);
    printf("max courses %d\n", best_count);
    if (mode == 2) {
        for (int i = 0; i < best_count; i++) {
            printf("%d %d\n", best_assignments[i].course_id, best_assignments[i].room_id);
        }
    }

    return 0;
}
