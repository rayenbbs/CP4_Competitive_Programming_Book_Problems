#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;



int main() {
    int t;
    cin >>t;
    int scenario=1;

    while(t--){
        if (scenario!=1)
            cout<<"\n";
        cout<<"Scenario #"<<scenario++<<endl;
        int V;
        cin >>V;
        unordered_map <string,int> mymap;
        unordered_map <int,string> revmap;
        for(int i=0;i<V;++i){
            string id;
            cin >>id;
            mymap[id]=i;
            revmap[i]=id;
        }
        vector<vector<ii>> AL(V,vector<ii>());
        int E;
        cin >>E;
        for(int i=0;i<E;++i){
            string u,v; int w;
            cin >>u >>v >> w;
            AL[mymap[u]].emplace_back(mymap[v],w);
        }

        int Q;
        cin >>Q;
        for(int j=0;j<Q;++j){
            int maxq;
            cin >>maxq;
            // inside int main()
            vector<vi> dist(V, vi(maxq+2,INF)); dist[0][0] = 0; // INF = 1e9 here
            for (int i = 0; i < V-1; ++i) { // total O(V*E)
                bool modified = false; // optimization
                for (int u = 0; u < V; ++u) // these two loops = O(E)
                    for(int j=0;j<=maxq;++j) {
                        if (dist[u][j] != INF) // important check
                        {
                            for (auto &[v, w]: AL[u]) { // C++17 style
                                if (dist[u][j] + w >= dist[v][j+1]) continue; // not improving, skip
                                //cout<<dist[u][j]+w<<endl;
                                dist[v][j+1] = dist[u][j] + w; // relax operation
                                modified = true; // optimization
                            }
                            if (!modified) break; // optimization
                        }
                    }
            }
            int min=INF;
            for(int q=0;q<=maxq+1;++q){
                if( dist[V-1][q]!=INF) {
                    if (dist[V - 1][q] < min) {
                        min = dist[V - 1][q];

                    }
                }
            }

            if (min!=INF)
                cout<<"Total cost of flight(s) is $"<<min<<"\n";
            else cout<<"No satisfactory flights\n";
        }


    }

}




/*

4

4
Calgary
Winnipeg
Ottawa
Fredericton
6
Calgary Winnipeg 125
Calgary Ottawa 300
Winnipeg Fredericton 325
Winnipeg Ottawa 100
Calgary Fredericton 875
Ottawa Fredericton 175
3 2 1 0
3
Calgary
Montreal
Fredericton
2
Calgary Montreal 300
Montreal Fredericton 325
1 0

4
Calgary
Winnipeg
Ottawa
Fredericton
6
Calgary Winnipeg 125
Calgary Ottawa 300
Winnipeg Fredericton 325
Winnipeg Ottawa 100
Calgary Fredericton 875
Ottawa Fredericton 175
3 2 1 0

3
Calgary
Montreal
Fredericton
2
Calgary Montreal 300
Montreal Fredericton 325
1 0




 */