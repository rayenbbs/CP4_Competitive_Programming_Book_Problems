#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;

int dr[] = { 1,  0,-1,0};
int dc[] = { 0,  1,  0,-1};

int main() {
    int W,H;
    cin >>W>>H;
    while(H!=0 || W!=0){
        vii grid(H,vi(W,0));
        vector<vector<tuple<int,int,int>>> AL(H,vector<tuple<int,int,int>>(W,{-1,-1,-1}));
        int g;
        cin >>g;
        for(int i=0;i<g;++i){
            int r,c;
            cin >>c>>r;
            grid[r][c]=-1;
        }
        int e;
        cin >>e;
        for(int i=0;i<e;++i){
            int r1,c1,r2,c2;
            int w;
            cin >>c1>>r1>>c2>>r2>>w;
            grid[r1][c1]=1;
            AL[r1][c1]={r2,c2,w};
        }
        // inside int main()
        vii dist(H,vi(W,INF)); dist[0][0] = 0; // INF = 1e9 here
        for (int i = 0; i < H*W; ++i) {// total O(V*E)
            for (int r = 0; r < H; ++r) // these two loops = O(E)
            {
                for (int c = 0; c < W; ++c) {
                    if (dist[r][c] != INF) {
                        if (r==H-1 && c==W-1) continue;
                        if (grid[r][c] == -1) continue;
                        if (grid[r][c] == 1) {
                            dist[get<0>(AL[r][c])][get<1>(AL[r][c])] = min((dist[get<0>(AL[r][c])][get<1>(AL[r][c])]),(dist[r][c] + get<2>(AL[r][c])));
                        }
                        else
                        {
                            for (int d = 0; d < 4; ++d) {
                                int nextr = r + dr[d];
                                int nextc = c + dc[d];
                                if ((nextr < 0) || (nextr >= H)) continue; // outside grid, part 1
                                if ((nextc < 0) || (nextc >= W)) continue; // outside grid, part 2
                                if (grid[nextr][nextc] == -1) continue;
                                dist[nextr][nextc] = min(dist[nextr][nextc], dist[r][c] + 1);
                            }
                        }

                    }
                }
            }
        }

        bool hasNegativeCycle = false;
        for (int r = 0; r < H; ++r) // these two loops = O(E)
        {
            for(int c=0;c<W;++c){
                if (dist[r][c] != INF)
                {
                    if (r==H-1 && c==W-1) continue;
                    if (grid[r][c]==-1 ) continue;
                    if (grid[r][c]==1){
                        if(dist[get<0>(AL[r][c])][get<1>(AL[r][c])]>(dist[r][c]+get<2>(AL[r][c])))
                            hasNegativeCycle=true;
                    }
                    else{
                        for(int d=0;d<4;++d){
                            int nextr=r+dr[d];
                            int nextc=c+dc[d];
                            if ((nextr< 0) || (nextr >= H)) continue; // outside grid, part 1
                            if ((nextc < 0) || (nextc >= W)) continue; // outside grid, part 2
                            if (grid[nextr][nextc]==-1 ) continue;
                            if (dist[nextr][nextc]>dist[r][c]+1)
                                hasNegativeCycle=true;
                        }
                    }

                }
            }
        }
        if (hasNegativeCycle)
            cout<<"Never"<<endl;
        else{
            if (dist[H-1][W-1]!=INF)
                cout<<dist[H-1][W-1]<<endl;
            else cout<<"Impossible"<<endl;
        }

        cin >>W>>H;
    }

}




/*

3 3
2
2 1
1 2
0
4 3
2
2 1
3 1
1
3 0 2 2 0
4 2
0
1
2 0 1 0 -3
0 0




 */
