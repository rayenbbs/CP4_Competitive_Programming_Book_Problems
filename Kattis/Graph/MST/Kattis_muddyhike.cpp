#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi rd = {-1,0,1,0};
vi rc = {0,-1,0,1};


int main(){
    int R,C;
    cin >>R>>C;
    vector<vi> grid(R,vi(C,0));
    vector<vi> vis(R,vi(C,0));
    for(int i=0;i<R;++i){
        for (int j=0;j<C;++j)
        {
            int a;
            cin >>a;
            grid[i][j]=a;
        }
    }
    priority_queue<tuple<int,int,int>> pq;
    for(int i=0;i<R;++i){
        pq.emplace(-grid[i][0],i,0);
    }

    while (!pq.empty()){
        tuple<int,int,int> u=pq.top();
        pq.pop();
        int w=-get<0>(u);
        int r=get<1>(u);
        int c=get<2>(u);
        if (vis[r][c]){
            continue;
        }
        else {
            vis[r][c] = 1;
            grid[r][c] = w;
            for (int i = 0; i < 4; ++i) {
                if (r + rd[i] < 0 || r + rd[i] >= R || c + rc[i] < 0 || c + rc[i] >= C)
                    continue;
                if (vis[r + rd[i]][c + rc[i]])
                    continue;
                pq.emplace(-max(grid[r][c], grid[r + rd[i]][c + rc[i]]), r + rd[i], c + rc[i]);
            }
        }
    }
    int min=1e9;
    int indice=-1;
    for(int i=0;i<R;++i){
        if (grid[i][C-1]<min)
        {
            indice=i;
            min=grid[i][C-1];
        }
    }

    cout<<min<<endl;
}


