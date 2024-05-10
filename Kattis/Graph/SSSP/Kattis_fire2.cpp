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
    int t;
    cin >>t;
    while(t--){
        cin >>C>>R;
        int rs,cs;
        grid.assign(R,vector<char>(C,'.'));
        vector<pair<int,int>> fire;
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                char a;
                cin >>a;
                grid[r][c]=a;
                if (a=='*'){
                    fire.emplace_back(r,c);
                }
                if (a=='@'){
                    rs=r;
                    cs=c;
                }
            }
        }
        queue <pair<int,int>> q;
        for(auto v: fire){
            q.emplace(v.first,v.second);
        }
        q.emplace(rs,cs);
        vii dist(R,vi(C,INF));
        dist[rs][cs]=0;
        grid[rs][cs]='x';
        bool test =false;
        int result;
        while(!q.empty() && !test){
            pair<int,int> u =q.front();q.pop();
            int r1=u.first; int c1=u.second;
            if (grid[r1][c1]=='*'){
                for(int d=0;d<4;++d){
                    int rtemp=r1+dr[d];
                    int ctemp=c1+dc[d];
                    if ((rtemp< 0) || (rtemp >= R)) continue; // outside grid, part 1
                    if ((ctemp < 0) || (ctemp >= C)) continue; // outside grid, part 2
                    if (grid[rtemp][ctemp]=='#') continue;
                    if (grid[rtemp][ctemp]=='x')continue;
                    if (grid[rtemp][ctemp]=='*')continue;

                    grid[rtemp][ctemp]='*';
                    q.emplace(rtemp,ctemp);
                }
            }
            else if (grid[r1][c1]=='x'){
                for(int d=0;d<4;++d){
                    int rtemp=r1+dr[d];
                    int ctemp=c1+dc[d];
                    if ((rtemp< 0) || (rtemp >= R)) {
                        test=true;
                        result = dist[r1][c1]+1;
                        break;
                    }
                    if ((ctemp < 0) || (ctemp >= C)) {
                        test=true;
                        result = dist[r1][c1]+1;
                        break;
                    } // outside grid, part 2
                    if (grid[rtemp][ctemp] == '*') continue;
                    if (grid[rtemp][ctemp] == '#') continue;
                    if (dist[rtemp][ctemp]!=INF) continue;
                    dist[rtemp][ctemp]=dist[r1][c1]+1;
                    grid[rtemp][ctemp]='x';
                    q.emplace(rtemp,ctemp);
                }
            }
        }
        if (test){
            cout<<result<<endl;
        }
        else {
            cout<<"IMPOSSIBLE\n";
        }
    }
}

/*
1
4 3
####
#*@.
####
 */