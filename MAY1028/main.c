#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct yuip
{
    char data[50];
    int lift;
    int limit[50];
    int time;
}yuip_t;
void input(char s[],int data[]){
    int len=strlen(s);
    int prev=isupper(s[0]);
    int curr;
    int *p=data;
    for(int i=0;i<len;i++){
        curr=isupper(s[i]);
        if(prev^curr)p++;
        (*p)++;
        prev=curr;
    }
}
int main(){
    int unit;
    scanf(" %d",&unit);
    yuip_t quit[unit];
    for (int i=0;i<unit;i++){
        quit[i].time=0;
        int ssd=0;
        scanf(" %s",quit[i].data);
        scanf(" %d",&quit[i].lift);
        for (int j=0;j<50;j++){
            quit[i].limit[j]=0;
        }
        input(quit[i].data,quit[i].limit);
        for(int j=0;j<50;j++){
            if(quit[i].limit[j]==quit[i].lift){
                ssd+=quit[i].limit[j];
                // printf("%d /",ssd);
            }else if(quit[i].limit[j]>quit[i].lift){
                
                ssd+=quit[i].lift;
                // printf("%d /",ssd);
                if(quit[i].time<ssd){
                quit[i].time=ssd;
                }
                ssd=quit[i].lift;
                // printf("%d ",ssd);
            }else {
                if(quit[i].time<ssd){
                quit[i].time=ssd;}
                // printf("%d /",ssd);
                ssd=0;
                // printf("%d ",ssd);
            }
            
        }
        // printf("\n");
        if(quit[i].time<=quit[i].lift){
            quit[i].time=0;
        }
    }
    // for(int i=0;i<unit;i++){
    //     for(int j=0;j<50;j++){
    //         printf("%d ",quit[i].limit[j]);
    //     }printf("\n");
    // }
    for(int i=0;i<unit;i++){
        printf("%d\n",quit[i].time);
    }
    
}