#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector <vector<char>> grid;

int knightr[]{2, 2, -2 , -2, 1,-1 ,1 ,-1 };
int knightc[]{1, -1, 1 , -1, 2, 2, -2,-2 };


int main(){
    int n;
    cin >>n;
    R=n;
    C=n;
    int rs,cs;
    grid.assign(R,vector<char>(C,'.'));
    for(int r=0;r<R;++r){
        for(int c=0;c<C;++c){
            char a;
            cin >>a;
            grid[r][c]=a;
            if (a=='K'){
                rs=r;
                cs=c;
            }
        }
    }
    vii dist(R,vi(C,INF));
    dist[rs][cs]=0;
    queue<pair<int,int>> q;
    q.emplace(rs,cs);
    while(!q.empty()){
        pair<int,int> u=q.front(); q.pop();
        if (u.first==0 && u.second==0)
            break;
        for(int d=0;d<8;++d){
            int nextr=u.first+knightr[d];
            int nextc=u.second+knightc[d];
            if (nextr<0 || nextr>=R) continue;
            if (nextc<0 || nextc>=C) continue;
            if (grid[nextr][nextc]=='#') continue;
            if (dist[nextr][nextc]!=INF) continue;
            dist[nextr][nextc]=dist[u.first][u.second]+1;
            q.emplace(nextr,nextc);
        }
    }
    if (dist[0][0]==INF)
        cout<<-1<<endl;
    else {
        cout<<dist[0][0]<<endl;
    }


}

/*

3
..K
...
###

 */