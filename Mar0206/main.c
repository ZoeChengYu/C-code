#include<stdio.h>
float card(){
    char cars[2];
    float point;
    scanf("%s%*c",cars);
    if(cars[0]=='1'&&cars[1]=='0'){
        point=10;
    }else if(cars[0]=='J'||cars[0]=='Q'||cars[0]=='K'){
        point=0.5;
    }else if (cars[0]=='A')
    {
        point=1.0;
    }else{
        point=(int)(cars[0]-'0');
    }
    return point;
}
float point(){
    float point,pa,pb,pc;
    pa=card();
    pb=card();
    pc=card();
    point=pa+pb+pc;
    if (point>10.5){
        point=0;
    }
    return point;
}
void printpoint(float gamer){
    int K=(int)(gamer*10)%10;
    if(K==0){
        printf("%d\n",(int)gamer);
    }else
    {
        printf("%.1f\n",gamer);
    }
}
int main(){
    float player1,player2;
    player1=point();
    player2=point();
    printpoint(player1);
    printpoint(player2);
    if(player1>player2){
        printf("X Win");
    }else if(player1<player2){
        printf("Y Win");
    }else{
        printf("Tie");
    }
}