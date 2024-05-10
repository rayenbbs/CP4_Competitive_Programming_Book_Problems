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

    int n,m;
    cin >> n>>m;
    do {


        vector<pair<int, int>> ve;
        vector<iii> EL(m);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            EL[i] = {w, u, v};
        }
        sort(EL.begin(), EL.end());
        int mst_cost = 0, num_taken = 0;
        UnionFind UF(n);
        for (auto &[w, u, v]: EL) { // C++17 style
            if (UF.isSameSet(u, v)) {
                continue;
            }
            if (u > v)
                ve.emplace_back(v, u);
            else
                ve.emplace_back(u, v);
            mst_cost += w;
            UF.unionSet(u, v);
            ++num_taken;
            if (num_taken == n - 1) break;// optimization
        }
        if (num_taken!=n-1)
            cout<<"Impossible"<<endl;
        else {

            sort(ve.begin(), ve.end());
            cout << mst_cost << endl;
            for (auto &[u, v]: ve) {
                cout << u << " " << v << endl;
            }
        }


        cin >>n>>m;
    }while (n!=0 || m!=0);


}