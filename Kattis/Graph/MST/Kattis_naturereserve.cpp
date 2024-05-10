#include <bits/stdc++.h>
using namespace std;
#define vii vector<pair<ll,ll>>
#define ii pair<ll,ll>
#define vi vector<ll>
#define ll long long
vector<vii> AL;
vi taken;
priority_queue<ii> pq;
void process(ll u) {
    taken[u] = 1;
    for (auto &[v, w] : AL[u])
        if (!taken[v])
            pq.emplace(-w, -v);
}

int main(){
    int t;
    cin >>t;
    while (t--)
    {
        ll V, E,S;
        ll L;
        cin >>V>>E>>L>>S;
        AL.assign(V, vii());
        vector <ll>vec;
        vector <ll > cost(V,1);
        for(int i=0;i<S;++i){
            ll a;
            cin >>a;
            a-=1;
            cost[a]=0;
            vec.push_back(a);
        }
        for (int i = 0; i < E; ++i) {
            ll u, v, w;
            cin >>u>>v>>w;
            u-=1;
            v-=1;
            AL[u].emplace_back(v, w+L);
            AL[v].emplace_back(u, w+L);
        }
        taken.assign(V, 0);
        for (int i=0;i<S;++i){
            taken[vec[i]]=1;
        }
        for (int i=0;i<S;++i){
            process(vec[i]);
        }

        ll mst_cost = 0, num_taken = 0; // no edge has been taken
        while (!pq.empty()) { // up to O(E)
            auto [w, u] = pq.top();
            pq.pop(); // C++17 style
            w = -w;
            u = -u;
            if (taken[u]) continue;
            mst_cost += w; /
            process(u);
            ++num_taken;
        }

        cout<<mst_cost <<endl;

    }
}

