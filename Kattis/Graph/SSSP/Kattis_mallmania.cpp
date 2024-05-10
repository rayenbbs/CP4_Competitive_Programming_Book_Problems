#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;

int dr[] = { 1,  0,-1,0};
int dc[] = { 0,  1,  0,-1};


int main(){
    R=2001;
    C=2001;
    int m1;
    int m2;
    cin >>m1;
    while (m1!=0){
        queue<pair<int,int>> q;
        vii dist(R,vi(C,INF));
        grid.assign(R,vector<char> (C,'.'));
        for(int i=0;i<m1;++i)
        {
            int r;
            int c;
            cin >>r>>c;
            q.emplace(r,c);
            dist[r][c]=0;
        }
        cin >>m2;
        for(int i=0;i<m2;++i)
        {
            int r;
            int c;
            cin >>r>>c;
            grid[r][c]='x';
        }
        while(!q.empty()){
            pair<int,int> u =q.front(); q.pop();
            int r1=u.first; int c1=u.second;
            if (grid[r1][c1]=='x')
            {
                cout<<dist[r1][c1]<<endl;
                break;
            }
            for(int d=0;d<4;++d){
                int rtemp=r1+dr[d];
                int ctemp=c1+dc[d];
                if ((rtemp< 0) || (rtemp >= R)) continue; // outside grid, part 1
                if ((ctemp < 0) || (ctemp >= C)) continue; // outside grid, part 2
                if (dist[rtemp][ctemp]!=INF) continue;
                dist[rtemp][ctemp]=dist[r1][c1]+1;
                q.emplace(rtemp,ctemp);
            }
        }
        cin >>m1;
    }
}

/*
4
0 0 0 1 1 1 1 0
6
4 3 4 2 3 2 2 2 2 3 3 3
0
 */