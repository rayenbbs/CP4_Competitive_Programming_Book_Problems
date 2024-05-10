#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;

int kingr[]{ 1, 1, 0,-1,-1,-1, 0, 1};
int kingc[] { 0, 1, 1, 1, 0,-1,-1,-1};


int main(){
    string line;
    getline(cin,line);
    int t=0;
    while(!line.empty()){
        t++;
        stringstream s(line);
        int r1,c1,r2,c2,r3,c3;
        s>>r1>>c1>>r2>>c2>>r3>>c3;
        r1--;
        c1--;
        r2--;
        c2--;
        r3--;
        c3--;
        R=8;
        C=8;
        grid.assign(R,vector<char>(C,'.'));
        grid[r3][c3]='x';
        vii dist(R,vi(C,INF));
        queue<pair<int,int>> q;
        q.emplace(r1,c1);
        dist[r1][c1]=0;
        while(!q.empty()){
            pair<int,int> u = q.front(); q.pop();
            for(int d=0;d<8;++d){
                int nextr=u.first+kingr[d];
                int nextc=u.second+kingc[d];
                if (nextr<0 || nextr>=R) continue;
                if (nextc<0 || nextc>=C) continue;
                if (dist[nextr][nextc]!=INF) continue;
                if (grid[nextr][nextc]=='x') continue;
                dist[nextr][nextc]=dist[u.first][u.second]+1;
                if (nextr==r2 && nextc==c2) break;
                q.emplace(nextr,nextc);
            }
        }
        cout<<"Case "<<t<<": "<<dist[r2][c2]<<endl;
        getline(cin,line);

    }

}

/*
1 1 8 7 5 6
1 1 3 3 2 2
 */