#include<stdio.h>
#include<string.h>
#include<math.h>

void findmb(char *m,char *b,int *x1,int *y1,int *x2,int *y2){
    int Md=(*y2-*y1);
    int Dd=(*x2-*x1);
    int Bd=(*x2**y1-*x1**y2);
    char M=(char)(Md/(Dd/abs(Dd)));
    char D=(char)abs(Dd);
    char B=(char)(abs(Bd)/abs(Dd));
    if(Md%Dd==0){
        *m=(char)(Md/Dd);
    }else{
        strcat(m,&M);
        strcat(m,"/");
        strcat(m,&D);
    }
    if (Bd%Dd==0){
        *b=(char)(Bd/Dd);
    }else{
        if((Bd/(Dd/abs(Dd)))<0){
            strcat(b,"- ");
            strcat(b,&B);
            strcat(m,"/");
            strcat(m,&D);
        }else{
            if(Md/Dd!=0){
            strcat(b,"+ ");}
            strcat(b,&B);
            strcat(m,"/");
            strcat(m,&D);
        }
    }

}

void prints(char *m,char *b){
    if(*m=="0"){
        printf("y = %s",*b);
    }else
    if(*m=="1"){
        if(b!=0){printf("y = x %s",*b);}
        else{printf("y = x");}
    }else
    if(*m=="-1"){
        if(b!=0){printf("y = -x %s",*b);}
        else{printf("y = -x");}
    }else
    {
        if(b!=0){printf("y = %sx %s",*m,*b);}
        else{printf("y = %sx");}
    }
}

int main(){
    int n;
    scanf("%d%*c",&n);
    char function[n][2];
    for(int i=0;i<n;i++){
        int *x1,*y1,*x2,*y2;
        char m[46],b[46];
        scanf("%d %d %d %d%*c",x1,y1,x2,y2);
        findmb(m,b,x1,y1,x2,y2);
        function[i][0]=*m;
        function[i][1]=*b;
    }
    prints(m,b);
}