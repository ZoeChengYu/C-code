#include<stdio.h>
void transge(int CC[3][3]){
    int r=CC[0][0];
    CC[0][0]=CC[0][2];
    CC[0][2]=CC[2][2];
    CC[2][2]=CC[2][0];
    CC[2][0]=r;
    //----
    r=CC[0][1];
    CC[0][1]=CC[1][2];
    CC[1][2]=CC[2][1];
    CC[2][1]=CC[1][0];
    CC[1][0]=r;
}
int main(){
    int clio[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    transge(clio);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",clio[i][j]);
        }
        printf("\n");
    }
}