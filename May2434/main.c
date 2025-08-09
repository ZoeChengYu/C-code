#include<stdio.h>
typedef struct{
    int totalProcess;
    int processList[20][2];
    int time;
    int doneProcess;
    int done;
}job_t;

typedef struct 
{
    int time
}machine_t;

int main(){
    int n,work;
    scanf(" %d %d",&n,&work);
    job_t jobs[10];
    machine_t machinrs[10];
    int minchoice;
    int minProcessTime;
    int temp;
    int choose;
    int cost;
    int totalTime=0;
    while (!alldone(jobs,n))
    {
        minProcessTime=INT_MAX;
        for(int i=0;i<work;i++){
            if(jobs[i].done){
                continue;
            }
            choose=jobs[i].processList[jobs[i].doneProcess][0];
            cost=jobs[i].processList[jobs[i].doneProcess][1];
            temp=jobs[i].time>machinrs[choose].time?jobs[i].time:machinrs[i].time;
            temp+=cost;
            if(temp<minProcessTime){
                minchoice=i;
                minProcessTime=temp;

            }
        }
        choose=jobs[minchoice].processList[jobs[minchoice].doneProcess][0];
        jobs[minchoice].time=minProcessTime;
        jobs[minchoice].doneProcess++;
        machinrs[choose].time=minProcessTime;
    }
    
}