#include<stdio.h>

typedef enum status_t{
    notYet,
    ready,
    done
}Status;

typedef struct taskInf {
    int queue[20];
    int queueSize;
    int time;
    Status status;
}task;

int main(){
    int mouse=0;
    scanf(" %d",&mouse);
    for(int i=0;i<mouse;i++){
        int gose=0;
        scanf(" %d",&gose);
        for(int j=0;j<gose;j++){
            
        }
    }
}