#include<stdio.h>
#include<math.h>
int gouy[][2];

void D(int n,int s){
    if(n == 1){
        printf("%d\n",s);
    }else if (s<pow(2,n-1)){
        printf("0");
        D(n-1,s);
    }else{
        printf("1");
        D(n-1,pow(2,n)-1-s);
    }
}

int main(){
    int iso=0;
    int n;
    do{
        int s;
        scanf("%d",&n);
        if(n != -1){
            scanf("%d",&s);
            getchar();
            gouy[iso][0]=n;
            gouy[iso][1]=s;
            iso++;}
        }while(n!=-1);
        for(int i=0;i<iso;i++){
            D(gouy[i][0],gouy[i][1]);
        }
}