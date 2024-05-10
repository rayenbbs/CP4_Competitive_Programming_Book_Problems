#include <bits/stdc++.h>

using namespace std;


typedef  vector<int> vi ;
typedef  vector<vi> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;
int dr[] = { -1, -1, 0,1,1,1, 0, -1}; // the order is:
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1}; // N/NE/E/SE/S/SW/W/NW


int main() {
    cin >>R>>C;
    grid.assign(R,vector<char>(C,'.'));
    for(int r=0;r<R;++r){
        for (int c=0;c<C;++c){
            char a;
            cin >>a;
            grid[r][c]=a;
        }
    }
    int t;
    cin >>t;
    while(t--){
        int rs,cs,rd,cd;
        cin >>rs>>cs >>rd>>cd;
        rs--;
        cs--;
        rd--;
        cd--;
        int nextr;
        int nextc;
        deque<pair<int,int>> q;
        vii dist(R,vi(C,INF));
        dist[rs][cs]=0;
        q.emplace_front(rs,cs);
        while(!q.empty()){
            pair<int,int> u=q.front(); q.pop_front();
            int r1=u.first; int c1=u.second;
            nextr=r1+dr[grid[r1][c1]-'0'];
            nextc=c1+dc[grid[r1][c1]-'0'];
            if (nextr>=0 && nextr<R && nextc >=0 && nextc<C && dist[r1][c1]<dist[nextr][nextc]) {
                dist[nextr][nextc]=dist[r1][c1];
                q.emplace_front(nextr,nextc);
            }
            for(int d=0;d<8;++d){
                nextr=r1+dr[d];
                nextc=c1+dc[d];
                if (nextr<0 || nextr>=R) continue;
                if (nextc<0 || nextc >=C) continue;
                if (dist[nextr][nextc]!=INF) continue;
                dist[nextr][nextc]=dist[r1][c1]+1;
                q.emplace_back(nextr,nextc);
            }
        }
        cout<<dist[rd][cd]<<endl;
        /*for(int r=0;r<R;++r){
            for (int c=0;c<C;++c){
                cout<<dist[r][c]<<" ";
            }
            cout<<endl;
        }*/
    }
}

/*
5 5
44125
03355
64734
72377
02062
4
1 1 2 1
4 2 4 2
4 5 1 4
5 3 3 4

 */