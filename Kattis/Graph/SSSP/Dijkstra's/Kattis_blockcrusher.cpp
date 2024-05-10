#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;

const int INF=1e9;
int R,C;
int dr[] = { -1, -1, 0,1,1,1, 0, -1}; // the order is:
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};

int main(){
    cin >>R>>C;
    while(R!=0 || C!=0)
    {
        vector<vector<char>> grid(R,vector<char>(C,'.'));
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                char a;
                cin >>a;
                grid[r][c]=a;
            }
        }
        vector<vector<pair<int,int>>> p (R,vector<pair<int,int>>(C,{-1,-1}));
        vii dist(R, vi(C,INF));
        for(int c=0;c<C;++c){
            dist[0][c] = (int)grid[0][c]-'0';
            p[0][c]={0,c};
        }

        set<tuple<int,int,int>> pq; // balanced BST version
        for (int r = 0; r < R; ++r)
        {
            for(int c=0;c<C;++c)
            {
                pq.emplace(dist[r][c], r,c);
            }
        }
        while (!pq.empty()) { // main loop
            auto [d, r1,c1] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());
            int nextr,nextc;
            for(int p1=0;p1<8;++p1) {
                nextr=r1+dr[p1];
                nextc=c1+dc[p1];
                if (nextr<0 || nextr>=R) continue;
                if (nextc<0 || nextc >=C) continue;
                int w=grid[nextr][nextc]-'0';

                if (dist[r1][c1]+w >= dist[nextr][nextc]) continue; // not improving, skip
                pq.erase(pq.find({dist[nextr][nextc], nextr,nextc})); // erase old pair
                dist[nextr][nextc] = dist[r1][c1]+w; // relax operation
                pq.emplace(dist[nextr][nextc], nextr,nextc); // enqueue better pair
                p[nextr][nextc]={r1,c1};
            }
        }
        int min=INF;
        pair<int,int> dest;
        for(int c=0;c<C;++c){
            int r=R-1;
            if (dist[r][c]<min)
            {
                min =dist[r][c];
                dest={r,c};
            }
        }
        int r1=dest.first,c1=dest.second;
        while(p[r1][c1].first!=r1 || p[r1][c1].second!=c1){
            grid[r1][c1]=' ';
            int tempr =r1;
            int tempc= c1;
            r1=p[tempr][tempc].first;
            c1=p[tempr][tempc].second;
        }
        grid[r1][c1]=' ';
        for (int r = 0; r < R; ++r)
        {
            for(int c=0;c<C;++c)
            {
                cout<<grid[r][c];
            }
            cout<<endl;
        }
        cout<<endl;
        cin >>R>>C;
    }
}




/*



 */