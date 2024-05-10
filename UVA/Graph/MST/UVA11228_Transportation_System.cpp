#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> iii;
#define ll long long int
typedef vector<int> vi;
using namespace std;
typedef vector<int> vi;


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

int main()
{
    int t;
    cin >>t;
    int t1=0;
    while (t--) {
        t1++;
        int V, E;
        int r;
        cin >>V>>r;
        E=V*V-1;
        vector<pair<int,int>>vf;
        vector<tuple<double, int, int>> EL(E);
        for (int i=0;i<V;++i)
        {
            int x,y;
            cin >>x>>y;
            vf.emplace_back(x,y);
        }
        int count=0;
        for (int i=0;i<V;++i)
        {
            for (int j=0;j<V;++j)
            {
                if (j==i) continue;
                double res=sqrt(pow(vf[i].first-vf[j].first,2)+pow(vf[i].second-vf[j].second,2));
                EL[count]={res,i,j};
                count++;
            }
        }
        sort(EL.begin(), EL.end());
        double mst_cost_roads = 0;
        double mst_cost_railroads = 0;
        int countstates=1;
        int num_taken = 0;
        UnionFind UF(V);
        for (auto &[w, u, v]: EL) {
            if (UF.isSameSet(u, v)) continue;
            if (w<=r)
                mst_cost_roads += w;
            else {
                countstates++;
                mst_cost_railroads += w;
            }
            UF.unionSet(u, v); /
            ++num_taken;
            if (num_taken == V - 1) break;
        }
        cout << "Case #"<<t1<<": "<<countstates<<" "<<round(mst_cost_roads)<<" "<<round(mst_cost_railroads)<< endl;
    }
}

