#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void transcube(int mode,int cube[6][9]){
    if(mode==10){
        int r0=cube[2][0],r1=cube[2][3],r2=cube[2][6],r3=cube[1][0],r4=cube[1][1];
        cube[2][0]=cube[5][0];
        cube[5][0]=cube[4][8];
        cube[4][8]=cube[0][0];
        cube[0][0]=r0;
        cube[2][3]=cube[5][3];
        cube[5][3]=cube[4][5];
        cube[4][5]=cube[0][3];
        cube[0][3]=r1;
        cube[2][6]=cube[5][6];
        cube[5][6]=cube[4][2];
        cube[4][2]=cube[0][6];
        cube[0][6]=r2;
        cube[1][0]=cube[1][2];
        cube[1][2]=cube[1][8];
        cube[1][8]=cube[1][6];
        cube[1][6]=r3;
        cube[1][1]=cube[1][5];
        cube[1][5]=cube[1][7];
        cube[1][7]=cube[1][3];
        cube[1][3]=r4;
    }else if(mode==11){
        int r0=cube[2][1],r1=cube[2][4],r2=cube[2][7];
        cube[2][1]=cube[5][1];
        cube[5][1]=cube[4][7];
        cube[4][7]=cube[0][1];
        cube[0][1]=r0;
        cube[2][4]=cube[5][4];
        cube[5][4]=cube[4][4];
        cube[4][4]=cube[0][4];
        cube[0][4]=r1;
        cube[2][7]=cube[5][7];
        cube[5][7]=cube[4][1];
        cube[4][1]=cube[0][7];
        cube[0][7]=r2;
    }else if(mode==12){
        int r0=cube[2][2],r1=cube[2][5],r2=cube[2][8],r3=cube[3][0],r4=cube[3][1];
        cube[2][2]=cube[5][2];
        cube[5][2]=cube[4][6];
        cube[4][6]=cube[0][2];
        cube[0][2]=r0;
        cube[2][5]=cube[5][5];
        cube[5][5]=cube[4][3];
        cube[4][3]=cube[0][5];
        cube[0][5]=r1;
        cube[2][8]=cube[5][8];
        cube[5][8]=cube[4][0];
        cube[4][0]=cube[0][8];
        cube[0][8]=r2;
        cube[3][0]=cube[3][6];
        cube[3][6]=cube[3][8];
        cube[3][8]=cube[3][2];
        cube[3][2]=r3;
        cube[3][1]=cube[3][3];
        cube[3][3]=cube[3][7];
        cube[3][7]=cube[3][5];
        cube[3][5]=r4;
    }else if(mode==20){
        int r0=cube[1][0],r1=cube[1][1],r2=cube[1][2],r3=cube[0][0],r4=cube[0][1];
        cube[1][0]=cube[2][0];
        cube[2][0]=cube[3][0];
        cube[3][0]=cube[4][0];
        cube[4][0]=r0;
        cube[1][1]=cube[2][1];
        cube[2][1]=cube[3][1];
        cube[3][1]=cube[4][1];
        cube[4][1]=r1;
        cube[1][2]=cube[2][2];
        cube[2][2]=cube[3][2];
        cube[3][2]=cube[4][2];
        cube[4][2]=r2;
        cube[0][0]=cube[0][6];
        cube[0][6]=cube[0][8];
        cube[0][8]=cube[0][2];
        cube[0][2]=r3;
        cube[0][1]=cube[0][3];
        cube[0][3]=cube[0][7];
        cube[0][7]=cube[0][5];
        cube[0][5]=r4;
    }else if(mode==21){
        int r0=cube[1][3],r1=cube[1][4],r2=cube[1][5];
        cube[1][3]=cube[2][3];
        cube[2][3]=cube[3][3];
        cube[3][3]=cube[4][3];
        cube[4][3]=r0;
        cube[1][4]=cube[2][4];
        cube[2][4]=cube[3][4];
        cube[3][4]=cube[4][4];
        cube[4][4]=r1;
        cube[1][5]=cube[2][5];
        cube[2][5]=cube[3][5];
        cube[3][5]=cube[4][5];
        cube[4][5]=r2;
    }else if(mode==22){
        int r0=cube[1][6],r1=cube[1][7],r2=cube[1][8],r3=cube[5][0],r4=cube[5][1];
        cube[1][6]=cube[2][6];
        cube[2][6]=cube[3][6];
        cube[3][6]=cube[4][6];
        cube[4][6]=r0;
        cube[1][7]=cube[2][7];
        cube[2][7]=cube[3][7];
        cube[3][7]=cube[4][7];
        cube[4][7]=r1;
        cube[1][8]=cube[2][8];
        cube[2][8]=cube[3][8];
        cube[3][8]=cube[4][8];
        cube[4][8]=r2;
        cube[5][0]=cube[5][2];
        cube[5][2]=cube[5][8];
        cube[5][8]=cube[5][6];
        cube[5][6]=r3;
        cube[5][1]=cube[5][5];
        cube[5][5]=cube[5][7];
        cube[5][7]=cube[5][3];
        cube[5][3]=r4;
    }
}
int main(){
    int MagicCube[6][9]={{1,1,1,1,1,1,1,1,1},{5,5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4,4},{2,2,2,2,2,2,2,2,2},{3,3,3,3,3,3,3,3,3},{6,6,6,6,6,6,6,6,6}};
    int work=0;
    scanf("%d",&work);
    int *type=malloc(work*sizeof(int));
    for(int i=0;i<work;i++){
        scanf("%d",&type[i]);
    }
    for(int i=0;i<work;i++){
        transcube(type[i],MagicCube);
    }
    for(int i=0;i<9;i++){
        printf("%d",MagicCube[2][i]);
        if(i%3==2){
            printf("\n");
        }else{
            printf(" ");
        }
    }
}