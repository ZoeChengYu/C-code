#include<stdio.h>
double plan[3][11]={{183,500,400,300,10,15,0.08,0.1393,0.1349,1.1287,1.4803},{383,600,500,400,20,25,0.07,0.1304,0.1217,1.1127,1.2458},{983,700,600,500,30,35,0.06,0.1087,0.1018,0.9572,1.1243}};
int freecoda(int use,double free){
    if(use<=free){
        //printf("%d\n",0);
        return 0;
    }
    else{
        int time=use-(int)free;
        //printf("%d\n",time);
        return time;
    }
}
double cost(int time,double unit){
    double costed=unit*time;
    //printf("%d\n",(int) costed);
    return costed;
}
int ans(int data[],double constar[]){
    int inc,outc,city,inm,outm,total=0;
    inc=freecoda(data[0],constar[1]);
    outc=freecoda(data[1],constar[2]);
    city=freecoda(data[2],constar[3]);
    inm=freecoda(data[3],constar[4]);
    outm=freecoda(data[4],constar[5]);
    total=cost(inc,constar[6])+cost(outc,constar[7])+cost(city,constar[8])+cost(inm,constar[9])+cost(outm,constar[10]);
    if (total>constar[0]){
        return total;
    }else{
        return constar[0];
    }
}
int main(){
    int incall,outcall,citycall,inmessege,outmessege;
    scanf("%d%d%d%d%d",&incall,&outcall,&citycall,&inmessege,&outmessege);
    int data[5]={incall,outcall,citycall,inmessege,outmessege};
    int A0=ans(data,plan[0]);
    int A1=ans(data,plan[1]);
    int A2=ans(data,plan[2]);
    if (A1>A2&&A0>A2){
        printf("%d\n%d",A2,(int) plan[2][0]);
    }else if(A0>A1&&A2>A1){
        printf("%d\n%d",A1,(int) plan[1][0]);
    }else{
        printf("%d\n%d",A0,(int) plan[0][0]);
    }
    

}