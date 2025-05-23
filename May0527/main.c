#include<stdio.h>
#include<string.h>
#include<ctype.h>
void split_word(const char* in,char* base,char* punct){
    int len=strlen(in);
    if(len>1&&ispunct(in[len-1])){
        strcpy(punct,in+len-1);
        strncpy(base,in,len-1);
        base[len-1]='\0';
    }else{
        strcpy(base,in);
        punct[0]='\0';
    }
}
int is_word_match(const char *word,const char *targer){
    char base[20],punct[5];
    split_word(word,base,punct);
    return strcmp(base,targer)==0;
}
int main(){
    char A[200],P[20],Q[20];

    fgets(A,sizeof(A),stdin);
    scanf(" %s",P);
    scanf(" %s",Q);

    int c =0;
    char word[100][20];
    char *ss;

    ss=strtok(A," \n");
    while (ss != NULL)
    {
        strcpy(word[c++],ss);
        ss=strtok(NULL," \n");
    }
    replaceWord(word,P,Q,c);
    insertBeforeWord(word,P,Q,c);
    insertAfterWord(word,P,Q,c);
    deleteWord(word,P,c);
    reverseWord(word,c);
}