#include<stdio.h>
int mathit(float w,float h){
    float H=h/100;
    float BaseBMI=w/H/H;
    int NewBMI=BaseBMI/1;
    int QBMI=BaseBMI*10;
    if(QBMI%10>5 || ((QBMI%10==5)&&(NewBMI%2==0))){
        NewBMI=NewBMI+1;
    }
    return NewBMI;
}
int main(){
    float w,h;
    scanf("%f%*c%f%*c",&w,&h);
    if(w<20||w>100||h<100||h>200){
        printf("ERROR");
    }else{
        int BMI=mathit(w,h);
        printf("%d\n",BMI);
        if(BMI<18){
            printf("too low");
        }
        if(BMI>24){
            printf("too high");
        }
    }
}