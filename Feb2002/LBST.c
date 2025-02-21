#include<stdio.h>
#include<math.h>
int main(){
    int tub=0;
    int common=0;
    int flog=0;
    int O[3]={0,0,0};
    for(int i=0;i<5;i++){
        int sata=0;
        scanf("%d",&sata);
        if (sata!=0){
            tub=tub<<1;
            tub++;
            tub=tub<<(sata-1);
        }
        else{
            flog++;
            if(flog%3==0){
            tub=tub>>3;
            tub=tub<<3;
            }
        }
        for(int j=0;j<3;j++){
            if((tub&(1<<j))==(1<<j)){
                O[j]=1;
            }
            else{
                O[j]=0;
            }
        }


    }
    int limit=log2(tub);
    for(int k=3;k<=limit;k++){
            if((tub&(1<<k))==(1<<k)){
                common++;
            }
        }

    printf("%d\n%d %d %d",common,O[0],O[1],O[2]);
}
