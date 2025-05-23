#include<stdio.h>
#include<math.h>

double funtion1(double x, double a) {
    double val = a - x * x;
    return val < 0 ? 0 : sqrt(val);
}

double funtion2(double x, double a) {
    double denom = a + x;
    if (denom <= 0) return 0;
    return (a * pow(x,3) + 7 * x) / sqrt(denom);
}
double area(double (*f)(double,double),double a,double p,double q,int n){
    double h=(q-p)/n;
    double sum=(f(p,a)+f(q,a))/2.0;
    for(int i=1;i<n;i++){
        sum+=f(p+i*h,a);
    }
    return sum*h;
}
int main(){
    int choice;
    double n,u,d;
    int err;

    while(1){
        scanf("%d",&choice);
        if(choice==0){
            break;
        }
        if(choice!=1&&choice!=2){
            printf("Invalid\n");
            continue;
        }
        scanf(" %lf %lf %lf %d",&n,&u,&d,&err);

        double (*func)(double,double)=choice==1?funtion1:funtion2;
        int m=1;
        double p_a=0.0,c_a=0.0;
        do{p_a=c_a;
        c_a=area(func,n,u,d,m);
        m*=2;}while(fabs(c_a-p_a)>pow(10,-err));
        printf("%.12lf\n",c_a);
    }
}