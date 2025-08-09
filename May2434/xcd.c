#include <stdio.h>
#include <limits.h>

typedef struct {
    int totalProcess;
    int processList[20][2]; // [機器][時間]
    int time;               // 此工作完成到目前為止的時間
    int doneProcess;        // 已完成的工序數量
    int done;               // 是否整個工作已完成
} job_t;

typedef struct {
    int time;               // 此機器目前可用的時間
} machine_t;

// 檢查是否所有工作都已完成
int alldone(job_t jobs[], int work) {
    for (int i = 0; i < work; i++) {
        if (!jobs[i].done) return 0;
    }
    return 1;
}

int main() {
    int n, work;
    scanf("%d %d", &n, &work);

    job_t jobs[10] = {0};
    machine_t machines[10] = {0};

    // 讀取工作資料
    for (int i = 0; i < work; i++) {
        scanf("%d", &jobs[i].totalProcess);
        for (int j = 0; j < jobs[i].totalProcess; j++) {
            scanf("%d %d", &jobs[i].processList[j][0], &jobs[i].processList[j][1]);
        }
    }

    int totalTime = 0;
    while (!alldone(jobs, work)) {
        int minTime = INT_MAX;
        int chosenJob = -1;

        for (int i = 0; i < work; i++) {
            if (jobs[i].done) continue;

            int procIndex = jobs[i].doneProcess;
            int machine = jobs[i].processList[procIndex][0];
            int duration = jobs[i].processList[procIndex][1];

            int startTime = jobs[i].time > machines[machine].time ? jobs[i].time : machines[machine].time;
            int completeTime = startTime + duration;

            // 挑最早完成時間，若相同取工作編號小的
            if (completeTime < minTime || 
               (completeTime == minTime && i < chosenJob)) {
                minTime = completeTime;
                chosenJob = i;
            }
        }

        // 排程該工作下一工序
        int procIndex = jobs[chosenJob].doneProcess;
        int machine = jobs[chosenJob].processList[procIndex][0];
        int duration = jobs[chosenJob].processList[procIndex][1];

        int startTime = jobs[chosenJob].time > machines[machine].time ? jobs[chosenJob].time : machines[machine].time;
        int completeTime = startTime + duration;

        jobs[chosenJob].time = completeTime;
        machines[machine].time = completeTime;
        jobs[chosenJob].doneProcess++;

        // 若該工作已完成所有工序
        if (jobs[chosenJob].doneProcess == jobs[chosenJob].totalProcess) {
            jobs[chosenJob].done = 1;
            totalTime += jobs[chosenJob].time;
        }
    }

    printf("%d\n", totalTime);
    return 0;
}
