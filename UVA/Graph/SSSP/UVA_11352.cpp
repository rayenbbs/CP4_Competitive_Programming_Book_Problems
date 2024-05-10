#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;

int knightr[]{2, 2, -2 , -2, 1,-1 ,1 ,-1 };
int knightc[]{1, -1, 1 , -1, 2, 2, -2,-2 };

int kingr[]{ 1, 1, 0,-1,-1,-1, 0, 1};
int kingc[] { 0, 1, 1, 1, 0,-1,-1,-1};

int main(){
    int t;
    cin >>t;
    while(t--){
        int rs,cs,rd,cd;
        cin >>R>>C;
        grid.assign(R,vector<char>(C,'.'));
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                char c1;
                cin >>c1;
                if (c1=='A')
                {
                    rs=r;
                    cs=c;
                }
                if (c1=='B')
                {
                    rd=r;
                    cd=c;
                }
                grid[r][c]=c1;
            }
        }

        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                if (grid[r][c]=='Z'){
                    for (int d=0;d<8;++d){
                        int nextr=r+knightr[d];
                        int nextc=c+knightc[d];
                        if (nextr<0 || nextr>=R) continue;
                        if (nextc<0 || nextc>=C) continue;
                        if (grid[nextr][nextc]=='A' || grid[nextr][nextc]=='B' || grid[nextr][nextc]=='Z') continue;
                        grid[nextr][nextc]='x';
                    }
                }
            }
        }
        vector<vi> dist(R,vi(C,INF));
        dist[rs][cs]=0;
        queue<pair<int,int>> q;
        q.emplace(rs,cs);
        while(!q.empty()){
            pair<int,int> u=q.front(); q.pop();
            if (u.first==rd && u.second==cd)
                break;
            for(int d=0;d<8;++d){
                int nextr=u.first+kingr[d];
                int nextc=u.second+kingc[d];
                if (nextr<0 || nextr>=R) continue;
                if (nextc<0 || nextc>=C) continue;
                if (dist[nextr][nextc]!=INF) continue;
                if (grid[nextr][nextc]=='x' || grid[nextr][nextc]=='Z') continue;
                dist[nextr][nextc]=dist[u.first][u.second]+1;
                q.emplace(nextr,nextc);
            }
        }
        if (dist[rd][cd]==INF)
        {
            cout<<"King Peter, you can't go now!\n";
        }
        else
        {
            cout<<"Minimal possible length of a trip is "<<dist[rd][cd]<<endl;
        }
    }
}
/*
4
5 5
.Z..B
..Z..
Z...Z
.Z...
A....
3 2
ZB
.Z
AZ
6 5
....B
.....
.....
..Z..
.....
A..Z.
3 3
ZZ.
...
AB.

 */