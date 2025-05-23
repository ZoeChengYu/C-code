#include<stdio.h>
#include<stdlib.h>
int inbound(int i,int j,int dx,int dy){
    if(i+4*dx<10){
        if(j+4*dy<10){
            return 1;
        }
    }
    return 0;
}
int find(int data[10][10],int result[10][10],int i,int j){
    int dir_x[4]={0,1,1,1};
    int dir_y[4]={1,0,1,-1};
    
    for(int d=0;d<4;d++){
        int dx=dir_x[d];
        int dy=dir_y[d];
        if(inbound(i,j,dx,dy)){
            int chess=0,zero_x=-1,zero_y=-1;
            for(int l=0;l<5;l++){
                int x=i+dx*l;
                int y=j+dy*l;
                if(data[x][y]==1){
                    chess++;
                }else{
                    zero_x=x;
                    zero_y=y;
                }
            }
            if(chess==4){
                int before_x=i-dx,before_y=j-dy;
                int after_x=i+5*dx,after_y=j+5*dy;
                if(before_x>=0&&before_x<10&&before_y>=0&&before_y<10){
                    if(data[before_x][before_y]==1)continue;
                }
                if(after_x>=0&&after_x<10&&after_y>=0&&after_y<10){
                    if(data[after_x][after_y]==1)continue;
                }
                result[zero_x][zero_y]++;
            }
        }
    }
}
int main(){
    int list[10][10],data[10][10],t=4;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf(" %d",&list[i][j]);
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            data[i][j]=0;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            find(list,data,i,j);
        }
    }
    while(t>0){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(data[i][j]==t){
                    printf("%d%d %d\n",i,j,data[i][j]);
                }
            }
        }
        t--;
    }

}