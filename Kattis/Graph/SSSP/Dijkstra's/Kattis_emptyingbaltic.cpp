#include <bits/stdc++.h>
using namespace std;


int R,C;


typedef vector<int> vi;
typedef vector<vi> vii;


int dr[] = { 1, 1, 0,-1,-1,-1, 0, 1}; // the order is:
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};

long long max(long long a, long long b){
    if (a>b) return a;
    else return b;
}

int main(){
    cin >>R>>C;
    vector<vector<long long>> grid(R,vector<long long>(C,0));
    for(int r=0;r<R;++r){
        for(int c=0;c<C;++c){
            cin >>grid[r][c];
        }
    }
    int rs,cs;
    cin >>rs>>cs;
    rs--;
    cs--;
    priority_queue<tuple<int,int,int>> q;
    vector<vector<long long int>> result(R,vector<long long int >(C,0));
    result[rs][cs]=grid[rs][cs];
    q.emplace(-result[rs][cs],rs,cs);
    vii visited (R,vi(C,0));
    while(!q.empty()){
        tuple<int,int,int> u;
        u=q.top(); q.pop();
        int r1=get<1>(u); int c1=get<2>(u);
        if (visited[r1][c1]==1)
            continue;
        visited[r1][c1]=1;
        for(int d=0;d<8;++d){
            int nextr=r1+dr[d],nextc=c1+dc[d];
            if (nextr<0 || nextr>=R) continue;
            if (nextc<0 || nextc>=C) continue;
            if (result[nextr][nextc]>max(result[r1][c1],grid[nextr][nextc]))
            {
                result[nextr][nextc]=max(result[r1][c1],grid[nextr][nextc]);
                q.emplace(-result[nextr][nextc],nextr,nextc);
            }
        }
    }
    long long fresult=0;
    for(int r=0;r<R;++r){
        for(int c=0;c<C;++c){
            fresult-=result[r][c];
        }
    }
    cout<<fresult<<endl;

}