#include <bits/stdc++.h>


using namespace std;

#define vi vector<int>
const int INF=1e9;
vector<vector<pair<int,int>>> AL;

int main()
{
    int t;
    cin>>t;
    int test=0;
    while (t--)
    {
        test++;
        int v,e;
        cin>>v>>e;
        unordered_map <int,int> mymap;
        AL.assign(v,vector<pair<int,int>>());
        for(int i=0;i<v;++i)
        {
            int w;
            cin >>w;
            mymap[i]=w;
        }
        for (int i=0;i<e;++i)
        {
            int a,b;
            cin >>a>>b;
            AL[a].emplace_back(b,mymap[b]);
        }
        vi dist(v, INF); dist[0] = 0;
        queue<int> q; q.push(0);
        int count=0;
        int last;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            last=u;
            int maxw=-1;
            int maxind=-1;
            for (auto &[n, w] : AL[u]) {
                if (dist[n]!=INF)continue;
                if (w>maxw) {
                    maxw = w;
                    maxind=n;
                }
            }
            if (maxw!=-1 && maxind!=-1) {
                dist[maxind] = dist[u] + 1;
                count += maxw;
                q.push(maxind);
            }
        }
        cout<<"Case "<<test<<": "<<count<<" "<<last<<endl;
    }
}