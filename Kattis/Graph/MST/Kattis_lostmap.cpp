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

    int n;
    cin >> n;
    vector<iii> EL(n*(n-1)/2);
    int count=0;
    for (int i = 0; i < n; ++i) {
        for (int j=0;j<n;++j)
        {
            int w;
            cin >>w;
            if (j>=i+1)
                EL[count++] = {w, i, j};
        }
    }
    sort(EL.begin(), EL.end()); // sort by w, O(E log E)
    int mst_cost = 0, num_taken = 0; // no edge has been taken
    UnionFind UF(n);// all V are disjoint sets
    for (auto &[w, u, v]: EL) { // C++17 style
        if (UF.isSameSet(u, v)) {
            continue;
        }
        cout<<u+1<<" "<<v+1<<endl;// already in the same CC
        mst_cost += w; // add w of this edge
        UF.unionSet(u, v); // link them
        ++num_taken; // 1 more edge is taken
        if (num_taken==n-1) break;// optimization
    }


}