#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void dell(char *data,char *result){
    while(isprint((int)*data)){
        if(*data!=' '){
            *result=*data;
            result++;
        }
        data++;
    }
}
void switchword(char *data,char *result){
    while(isprint((int)*data)){
        if(*data=='_'){
            *result='A';
        }else{
            *result=*data;
        }
        result++;
        data++;
    }
}
void chack(char *data,int *flag){
    while(isprint((int)*data)){
        if(isalpha((int) *data)){
            *flag*=1;
        }else{
            *flag*=0;
        }
        //printf("%c-%d\n",*data,*flag);
        (data)++;
    }
}
void carry(char *data,int *count){
    while (isprint((int)*data)||isspace((int)*data))
    {
        (*count)++;
        //printf("%c - %d\n",*data,*count);
        data++;
    }
}
void inver(char *data,char *newdata,int num){
    while(num>0){
        num--;
        *newdata=*(data+num);
        printf("%c",*newdata);
        newdata++;
    }
    printf("\n");
    
}
void listed(char *data){
    while(isprint(*data)||isspace(*data)){
        printf("%c",*data);
        data++;
    }
}
int main(){
    char *liA=(char*)malloc(sizeof(int)*100);
    gets(liA);
    char *liB=(char*)malloc(sizeof(int)*100);
    gets(liB);
    char *hoA=(char*)malloc(sizeof(liA));
    char *hoB=(char*)malloc(sizeof(liB));
    dell(liA,hoA);
    dell(liB,hoB);
    //printf("%s\n%s\n",hoA,hoB);
    char *cmA=(char*)malloc(sizeof(hoA));
    char *cmB=(char*)malloc(sizeof(hoB));
    switchword(hoA,cmA);
    switchword(hoB,cmB);
    //printf("%s\n%s\n",cmA,cmB);
    int flagA=1,flagB=1,carryA=0,carryB=0;
    chack(cmA,&flagA);
    chack(cmB,&flagB);
    if(flagA&&flagB){
        carry(liA,&carryA);
        carry(liB,&carryB);
        char *rsA=(char*)malloc(sizeof(char)*carryA);
        char *rsB=(char*)malloc(sizeof(char)*carryB);
        inver(liA,rsA,carryA);
        inver(liB,rsB,carryB);
        int cfA=0,cfB=0;
        carry(hoA,&cfA);
        carry(hoB,&cfB);
        if(cfB>cfA){
            listed(liB);
        }else{
            listed(liA);
        }
    }else{
        printf("Error");
    }
}
