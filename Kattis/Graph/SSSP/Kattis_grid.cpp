#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;



int main(){
    cin >>R>>C;
    grid.assign(R, vector<char>(C, '.'));
    for(int r=0;r<R;++r){
        for (int c=0;c<C;++c){
            cin >>grid[r][c];
        }
    }

    queue <pair<int,int>> q;
    q.emplace(0,0);
    vector<vi> dist(R,vi(C,INF));
    dist[0][0]=0;
    while (!q.empty()){
        pair<int,int> u=q.front(); q.pop();
        int r=u.first; int c=u.second;
        if (r==R-1 && c==C-1)
            break;
        int dr[] = { grid[r][c]-'0',  0,-(grid[r][c]-'0'),0};
        int dc[] = { 0,  grid[r][c]-'0',  0,-(grid[r][c]-'0')};
        for(int d=0;d<4;++d){
            int rtemp=r+dr[d];
            int ctemp=c+dc[d];
            if ((rtemp< 0) || (rtemp >= R)) continue; // outside grid, part 1
            if ((ctemp < 0) || (ctemp >= C)) continue; // outside grid, part 2
            if (dist[rtemp][ctemp]!=INF) continue;
            dist[rtemp][ctemp]=dist[r][c]+1;
            q.emplace(rtemp,ctemp);
        }
    }
    if (dist[R-1][C-1]!=INF)
        cout<<dist[R-1][C-1]<<endl;
    else
        cout<<-1<<endl;

}
