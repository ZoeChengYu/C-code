#include<stdio.h>
int flag(int s0,int s1,char e1,char e2,int isInvalid){
    if(s0<0||s0>63){
        isInvalid=1;
        printf("S0 ERROR\n");
    }
    if(s1<0||s1>63){
        isInvalid=1;
        printf("S1 ERROR\n");
    }
    if(e1<'a'||e1>'f'){
        isInvalid=1;
        printf("e1 ERROR\n");
    }
    if(e2<'a'||e2>'f'){
        isInvalid=1;
        printf("e2 ERROR\n");
    }
    if(isInvalid==0){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    int s0,s1,s2,e2_val;
    int ascii=97;
    int isInvalid=0;
    char e1,e2;
    scanf("%d%*c%d%*c%c%*c%c%*c",&s0,&s1,&e1,&e2);
    int opCode=flag(s0,s1,e1,e2,isInvalid);
    if(opCode==0){
        s2=s1;
        s2=s2|1<<(e1-ascii);
        e2_val=0|1<<(e2-ascii);
        if((s2&e2_val)!=0){
            printf("Y\n");
        }else{
            printf("N\n");
        }
        if((s2&s0)==s2){
            printf("Y\n");
        }else{
            printf("N\n");
        }
        printf("%d\n",s0&s2);
        printf("%d\n",s0|s2);
        printf("%d\n",s0&~s2);
    }
}
