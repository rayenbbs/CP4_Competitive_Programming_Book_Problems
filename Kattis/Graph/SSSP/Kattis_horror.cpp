#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;

int main(){
    int N,H,L;
    cin >>N>>H>>L;
    vector <vi> AL(N,vi());
    queue<int> q;
    vector<int> dist(N,INF);
    while (H--){
        int a;
        cin >>a;
        dist[a]=0;
        q.push(a);
    }

    while(L--){
        int a,b;
        cin >>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto &v: AL[u]){
            if (dist[v]!=INF) continue;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    int max=-1;
    int result=-1;
    for(int i=0;i<N;++i)
    {
        if (dist[i]>max) {
            max = dist[i];
            result=i;
        }
    }
    cout<<result<<endl;
}
