#include<stdio.h>
#include<math.h>
int main(void){
    int a,b,c;
    scanf("%d%*c",&a);
    scanf("%d%*c",&b);
    scanf("%d",&c);
    int x=b*b-(4*a*c);
    double v=sqrt(abs(x));
    if(x>=0){
        float s1=(-1*b+v)/(2.0*a);
        float s2=(-1*b-v)/(2.0*a);
        printf("%.1f",s1);
        if(s2!=s1){
            printf("\n%.1f",s2);
        }
    }else{
        float I=v/(2.0*abs(a));
        float R=b/(-2.0*a);
        if (R==-0.0){
            R=abs(R);
        }
        printf("%.1f+%.1fi\n",R,I);
        printf("%.1f-%.1fi",R,I);
    }
    }
