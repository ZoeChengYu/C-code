#include<stdio.h>
int tyde_program(int uid){
    if(uid==1||uid==0){
        return 0;
    }else{
        return tyde_program(uid/2+uid%2)+1;
    }
}
int printb(int num){
    int numb=0,bou=1;
    for(int i=0;i<=3;i++){
        numb+=num%2*bou;
        bou*=10;
        num/=2;
    }
    printf("%04d\n",numb);
    return 0;
} 
int main(){
    int numb[100],numd[100],i=0;
    do{
        scanf("%d%*c",&numb[i]);
        numd[i]=0;
        i++;
    }while(numb[i-1]!=-1);
    for(int o=0;o<i;o++){
        int fin=0,time=1;
    do{
        numd[o]=numd[o]+(numb[o]%10)*time;
        time*=2;
        numb[o]/=10;
    }while(numb[o]>0);
    fin=tyde_program(numd[o]);
    printb(fin);}
}