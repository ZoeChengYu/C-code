#include<stdio.h>
int sub(int sts[]){
    for(int h=2;h>0;h--){
        for(int i=0;i<2;i++){
            if (sts[i]>sts[i+1]){
                int wo=sts[i+1];
                sts[i+1]=sts[i];
                sts[i]=wo;
            }
        }
    }
    if((sts[0]+sts[1])<=sts[2]){
        printf("Not Triangle");
    }else{
        if(sts[0]==sts[2]){
            printf("Equilateral Triangle\n");
        }if(sts[0]==sts[1]||sts[1]==sts[2]){
            printf("Isosceles Triangle\n");
        }if(sts[0]*sts[0]+sts[1]*sts[1]<sts[2]*sts[2]){
            printf("Obtuse Triangle");
        }else if(sts[0]*sts[0]+sts[1]*sts[1]>sts[2]*sts[2]){
            printf("Acute Triangle");
        }else{
            printf("Right Triangle");
        }
    }
}
int main(){
    int n;
    scanf("%d%*c",&n);
    int sc[n][3];
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d%*c",&a,&b,&c);
        sc[i][0]=a;
        sc[i][1]=b;
        sc[i][2]=c;

    }
    for(int i=0;i<n;i++){
        sub(sc[i]);
        if (i!=n-1){
            printf("\n");
            for(int j=0;j<n;j++){printf("*");}
            printf("\n");
        }
    }
}