#include <bits/stdc++.h>

using namespace std;

int dr[] = { 1,  0,-1,0};
int dc[] = { 0,  1,  0,-1};

typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;

int main(){
    cin >>R>>C;
    do {
        grid.assign(R, vector<char>(C, '.'));
        int t;
        cin >> t;
        while (t--) {
            int r, nb;
            cin >>r>>nb;
            while (nb--) {
                int c;
                cin >> c;
                grid[r][c] = '+';
            }
        }
        int rs, cs;
        int rd, cd;
        cin >> rs >> cs;
        cin >> rd >> cd;
        queue <pair<int,int>> q;
        q.emplace(rs,cs);
        vector<vi> dist(R,vi(C,INF));
        dist[rs][cs]=0;
        while (!q.empty()){
            pair<int,int> u=q.front(); q.pop();
            int r=u.first; int c=u.second;
            if (r==rd && c==cd)
                break;
            for(int d=0;d<4;++d){
                int rtemp=r+dr[d];
                int ctemp=c+dc[d];
                if ((rtemp< 0) || (rtemp >= R)) continue; // outside grid, part 1
                if ((ctemp < 0) || (ctemp >= C)) continue; // outside grid, part 2
                if (grid[rtemp][ctemp] == '+') continue;
                if (dist[rtemp][ctemp]!=INF) continue;
                dist[rtemp][ctemp]=dist[r][c]+1;
                q.emplace(rtemp,ctemp);
            }
        }
        cout<<dist[rd][cd]<<endl;


        cin >>R >>C;
    }while (R!=0 || C!=0);

}

