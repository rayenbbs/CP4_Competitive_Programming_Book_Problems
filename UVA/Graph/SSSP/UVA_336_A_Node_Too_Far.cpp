#include <bits/stdc++.h>
using namespace std;
#define vii vector<pair<ll,ll>>
#define ii pair<ll,ll>
#define vi vector<ll>
const int INF = 1e9;
#define ll long long
vector<vii> AL;
vi taken;
priority_queue<ii> pq;

int main(){
    int E;
    cin >>E;
    int test=0;
    while(E!=0){
        vector<vi> AL;
        unordered_map<int,int> mymap;
        unordered_map<int,int>revmap;
        int count=0;
        for(int i=0;i<E;++i){
            int a;
            int b;
            cin >>a;
            if (mymap.find(a)==mymap.end())
            {
                mymap[a]=count;
                revmap[count]=a;
                count++;
                AL.emplace_back(vi());
            }
            cin >>b;
            if (mymap.find(b)==mymap.end())
            {
                mymap[b]=count;
                revmap[count]=b;
                count++;
                AL.emplace_back(vi());
            }
            AL[mymap[a]].push_back(mymap[b]);
            AL[mymap[b]].push_back(mymap[a]);
        }
        int a;
        int b;
        cin >>a >>b;
        while(a!=0 || b!=0){
            int result=0;
            vi dist(count,INF);
            ++test;
            queue <int> q;
            q.push(mymap[a]);
            dist[mymap[a]]=0;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(auto i : AL[u]){
                    if (dist[i]!=INF)
                        continue;
                    dist[i]=dist[u]+1;
                    q.push(i);
                }
            }
            for(int i=0;i<count;++i){
                if (dist[i]>b)
                    result++;
            }
            cout<<"Case "<<test<<": "<<result<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<".\n";
            cin >>a>>b;
        }
        cin >>E;
    }

}


/*
1
4 6 10 3
1 2 3
1 2 4
1 3 8
1 4 1
2 3 2
2 4 5
3 4 20

 */