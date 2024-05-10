#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> iii;
#define ll long long int
typedef vector<int> vi;
using namespace std;
typedef vector<int> vi;
typedef vector <pair<int,int>> vii;


class UnionFind { // OOP style
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0); // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N; // optional feature
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; } // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y]) swap(x, y); // keep x ’shorter’ than y
        p[x] = y; // set x under y
        if (rank[x] == rank[y]) ++rank[y]; // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets; // a union reduces numSets
    }
};

enum{
    VISITED=-1, UNVISITED=-2
};
vi dfs_num;
vector <vector<pair<int,double>>> AL;
void dfs(int u, vector<double> &distance){
    dfs_num[u]=VISITED;
    for (auto&[v,w]:AL[u]){
        if (dfs_num[v]==UNVISITED) {
            distance[v]=max(distance[u],w);
            dfs(v, distance);
        }
    }
}

int main() {
    int V, E;
    cin >> V;
    ll count=0;
    while(V!=0) {
        ++count;
        E = V * (V - 1) / 2;
        vector<tuple<double, int, int>> EL;
        AL.assign(V, vector<pair<int, double>>());
        dfs_num.assign(V, UNVISITED);
        vector<pair<int, int>> vp(V, {0, 0});
        vector<double> inhabitants(V, 0);
        vector<double> distance(V, 0);
        double totalm = 0;
        for (int i = 0; i < V; ++i) {
            int a, b;
            cin >> a >> b;
            vp[i] = {a, b};
            double m;
            cin >> m;
            totalm += m;
            inhabitants[i] = m;
        }
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                if (i != j) {
                    EL.emplace_back(sqrt(pow(vp[i].first - vp[j].first, 2) + pow(vp[i].second - vp[j].second, 2)), i,
                                    j);
                }
            }
        }
        sort(EL.begin(), EL.end());

        double mst_cost = 0, num_taken = 0;
        UnionFind UF(V);

        for (auto &[w, u, v]: EL) {
            if (UF.isSameSet(u, v)) continue;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
            mst_cost += w;
            UF.unionSet(u, v);
            ++num_taken;
            if (num_taken == V - 1) break;
        }
        dfs(0, distance);
        double sum = 0;
        for (int i = 0; i < V; ++i) {
            sum += inhabitants[i] * distance[i];
        }
        double result = sum / totalm;
        cout<<"Island Group: "<<count<<" Average ";
        cout << fixed << setprecision(2)<<result << endl<<endl;
        cin>>V;
    }


}
