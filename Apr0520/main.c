#include<stdio.h>

int main(){
    int time;
    scanf("%d%*c",&time);
    int data[4][time],totals[4][6],error=0;
    for(int i=0;i<time;i++){
        scanf("%d %d %d %d",&data[0][i],&data[1][i],&data[2][i],&data[3][i]);
    }
    for(int i=0;i<4;i++){for(int j=0;j<6;j++){totals[i][j]=0;}}
    for(int i=0;i<4;i++){
        for(int j=0;j<time;j++){
            if(data[i][j]==1){
                totals[i][0]++;
                if(totals[i][0]==2){
                    totals[i][4]++;
                    totals[i][0]=0;
                }
            }else if(data[i][j]==2){
                totals[i][1]++;
                if(totals[i][1]==2){
                    totals[i][4]++;
                    totals[i][1]=0;
                }
            }else if(data[i][j]==3){
                totals[i][2]++;
                if(totals[i][2]==2){
                    totals[i][4]++;
                    totals[i][2]=0;
                }
            }else if(data[i][j]==4){
                totals[i][3]++;
                if(totals[i][3]==2){
                    totals[i][4]++;
                    totals[i][3]=0;
                }
            }else{
                error=1;
            }
        }

    }
}