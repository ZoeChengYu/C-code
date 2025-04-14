#include<stdio.h>
#include<string.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
int getMinIndex(int d[], int left, int right,int *work) {
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++) {
        (*work)++;
        if (d[i]<d[minIndex]) minIndex=i;
    }
        return minIndex;
}
void selectSort(int d[], int n) {
    int i=0, index=0, change=0, work=0;
    for (i=0; i<n; i++) {
        index = getMinIndex(d, i, n,&work);
        if (index!=i){
            SWAP(d[i], d[index]);
            change+=3;
        }

    }
    printf("%d %d\n",work,change);
}
void insertionSort(int a[], int n) {
    int target=0, i=0, j=0, work=0, change=0;
    for (i=1; i<n; i++) {
        target = a[i];
        change++;
        for (j=i;; j--){
            work++;
            if(j<=0)break;
            work++;
            if(a[j-1]<=target)break;
            a[j] = a[j-1];
            change++;
        }
        a[j] = target;
        change++;
    }
    printf("%d %d",work,change);
}
int main(){
    int len;
    scanf("%d",&len);
    int data[len],sdata[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &data[i]);  // 讀取 n 個整數
    }
    memcpy(sdata,data,sizeof(data));
    // for(int i=0;i<len;i++){
    //     printf("%d\n",data[i]);
    // }
    selectSort(data,len);
    insertionSort(sdata,len);
    
}