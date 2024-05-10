#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;

int knightr[]{2, 2, -2 , -2, 1,-1 ,1 ,-1 };
int knightc[]{1, -1, 1 , -1, 2, 2, -2,-2 };


int main(){
    R=8;
    C=8;
    int t;
    cin >>t;
    while(t--){
        int rs,cs;
        string s;
        cin >>s;
        rs='8'-s[1];
        cs=s[0]-'a';
        vii dist(R,vi(C,INF));
        dist[rs][cs]=0;
        queue<pair<int,int>> q;
        q.emplace(rs,cs);
        int max=-1;
        while(!q.empty()){
            pair<int,int> u=q.front(); q.pop();
            for(int d=0;d<8;++d){
                int nextr=u.first+knightr[d];
                int nextc=u.second+knightc[d];
                if (nextr<0 || nextr>=R) continue;
                if (nextc<0 || nextc>=C) continue;
                if (dist[nextr][nextc]!=INF) continue;
                dist[nextr][nextc]=dist[u.first][u.second]+1;
                if (dist[nextr][nextc]>max)
                    max=dist[nextr][nextc];
                q.emplace(nextr,nextc);
            }
        }
        vector<pair<int,int>> vp;
        for(int r=0;r<8;++r){
            for(int c=0;c<8;++c){
                if (dist[r][c]==max)
                    vp.emplace_back(r,c);
            }
        }
        sort(vp.begin(),vp.end(),[](auto &a,auto &b){
            if (a.first==b.first)
                return (b.second>a.second);
            return (b.first>a.first);
        });
        cout<<max;
        for(int i=0;i<vp.size();++i){
            cout<<" "<<(char)(vp[i].second+'a')<<(char)('8'-vp[i].first);
        }
        cout<<endl;
    }

}

/*

2
d5
a1

 */