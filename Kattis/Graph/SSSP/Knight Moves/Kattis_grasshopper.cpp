#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;

int knightr[]{2, 2, -2 , -2, 1,-1 ,1 ,-1 };
int knightc[]{1, -1, 1 , -1, 2, 2, -2,-2 };


int main(){
    string line;
    getline(cin,line);
    while(!line.empty()){
        stringstream s(line);
        int rs,cs,rd,cd;
        s>>R>>C>>rs>>cs>>rd>>cd;
        rs--;
        cs--;
        cd--;
        rd--;
        vii dist(R,vi(C,INF));
        dist[rs][cs]=0;
        queue<pair<int,int>> q;
        q.emplace(rs,cs);
        while(!q.empty()){
            pair<int,int> u=q.front(); q.pop();
            if (u.first==rd && u.second==cd)
                break;
            for(int d=0;d<8;++d){
                int nextr=u.first+knightr[d];
                int nextc=u.second+knightc[d];
                if (nextr<0 || nextr>=R) continue;
                if (nextc<0 || nextc>=C) continue;
                if (dist[nextr][nextc]!=INF) continue;
                dist[nextr][nextc]=dist[u.first][u.second]+1;
                q.emplace(nextr,nextc);
            }
        }
        if (dist[rd][cd]==INF)
            cout<<"impossible\n";
        else
            cout<<dist[rd][cd]<<endl;
        getline(cin,line);
    }

}

/*

10 10 10 10 1 1
2 2 1 1 1 2
8 8 1 1 1 2


 */