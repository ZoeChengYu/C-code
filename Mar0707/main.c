#include<stdio.h>
int odd(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i);j++){
            printf("#");
        }
        for(int j=0;j<(2*i-1);j++){
            if(j%2==0){
                printf("*");
            }else{
                if(i%3==2){
                    printf("A");
                }else if(i%3==0){
                    printf("B");
                }else{
                    printf("C");
                }
            }
        }
        for(int j=1;j<=(n-i);j++){
            printf("#");
        }
        if(i!=n){
            printf("\n");
        }
    }
}
int even(int n){
    for(int i=1;i<=n;i++){
        for(int l=i;l>=1;l--){
            printf("%d",l);
        }
        for(int k=1;k<=(2*(n-i+1));k++){
            printf("*");
        }
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        if(i!=n){
            printf("\n");
        }
    }
}
int main(){
    int n,m;
    scanf("%d%*c",&n);
    scanf("%d%*c",&m);
    if(n>=1&&n<=2&&m>=1&&m<=9){
        if(n==1){
            odd(m);
        }else{
            even(m);
        }
    }else{
        printf("error");
    }
}