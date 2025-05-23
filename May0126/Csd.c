#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 4

#define INF 0x3f3f3f3f

void print(int R[][1<<MAX_N]) {
for (int i=0; i<MAX_N; i++)
for (int j=0; j<(1<<MAX_N); j++) printf("%d ", R[i][j]);
printf("\n");
}
int minValue(int x, int y) { return (x>y?y:x); }
int Rec(int R[][1<<MAX_N], int d[][MAX_N], int v, int S, int n){
int t=0, ans = INF;
if(R[v][S] >= 0) { return R[v][S]; } //已經計算過有紀錄,不用再計算
for(int i = 0 ; i < n ; i ++) {
if(!(S>>i&1)) { //集合 S,{0, 1, 2, 3},判斷第i個存在(0為存在)
t = Rec(R, d, i, S|(1<<i),n); //集合 S,去掉存在的那一個,第i個設為1
ans = minValue(ans,d[v][i]+ t);
}
}
return R[v][S] = ans;
}

#include <stdio.h> #include <string.h>
#define MAX_N 4 #define INF 0x3f3f3f3f
void print(int R[][1<<MAX_N]) {
for (int i=0; i<MAX_N; i++)
for (int j=0; j<(1<<MAX_N); j++) printf("%d ", R[i][j]);
printf("\n");
}
int minValue(int x, int y) { return (x>y?y:x); }
int Rec(int R[][1<<MAX_N], int d[][MAX_N], int v, int S, int n){
int t=0, ans = INF;
if(R[v][S] >= 0) { return R[v][S]; } //已經計算過有紀錄,不用再計算
for(int i = 0 ; i < n ; i ++) {
if(!(S>>i&1)) { //集合 S,{0, 1, 2, 3},判斷第i個存在(0為存在)
t = Rec(R, d, i, S|(1<<i),n); //集合 S,去掉存在的那一個,第i個設為1
ans = minValue(ans,d[v][i]+ t);
}
}
return R[v][S] = ans;
}

void travel(int n,const number W[][],index P[][],number& minlenth) {
    index i,j,k;
    number D[n][V-{v1}];
    for(i=2;i<=n;i++)
    D[i][空集]=W[i][1];//從頂點vi到v1的直接距離
    for(k=1;k<=n-2;k++)//遍歷A的每個子集
    for(包含k個頂點的所有子集A屬於V-{vi}) //從小到大遍歷
    for(滿足i!=1且vi不在v中的i)//算出任意點出發到v1結束的最短距離 
    {
    D[i][A]=min{W[i][j]+D[j][A-{vj}};//vj∈A
    P[i][A]=最小值的j值;
    }
    D[1][V-{vi}]=min{W[i][j]+D[j][A-{v1,vj}};
    //2<=j<=n 從v1出發到v1結束的最短距離
    P[1][V-{vi}]=最小值的j值 ;
    minlengt=D[1][V-{vi}];
    }

    findNextNodes(d[][], R[][], k, S, N, nextNodes[])
    // ---- 找最短那一條的距離 minDistance
    for i=0~N-1
    if (Si ∈ S) // S&(1<<i)==0
    distance = d[k][i]+R[i][S- Si]
    if (distance < minDistance)
    minDistance = distance
    // -----找出所有最短距離的所有點
    for i=0~N-1
    if (Si ∈ S) // S&(1<<i)==0
    distance = d[k][i]+R[i][S- Si]
    if (distance == minDistance)
    nextNodes[count++] = i
    
    // 得到所有最短距離的下一個點 nextNodes[]

    findPath(R, d, k, S, N) // N為節點數,k為目前探索的節點,d距離
    S = S – Si
    if(S==(1111..11) //結束條件,沒有存在任何節點
    印出stack中存的節點
    else //一般條件
    count = getNextNodes() // 取得所有最短路徑的下一個節點
    for i = 1~count-1
    將 nextNodes[i]存入stack
    findPath(R, d, nextNodes[i], S, N)
    pop stack
int build_path(int end,){}
int main(){
    int N;
    scanf(" %d",&N);
    int **box=(int**)malloc(sizeof(int*)*N);
    for(int i=0;i<N;i++){
        int *box[i]=(int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf(" %d",box[i][j]);
    int c,u,v;
    scanf(" %d %d %d",&c,&u,&v);
    int end,base=tsp(S,1<<S,&end,N,W,dp,pre);
    if(base>=INF){puts("Graph disconnected.");return 0;}
    int head[MAX_N];int hLen
    
}