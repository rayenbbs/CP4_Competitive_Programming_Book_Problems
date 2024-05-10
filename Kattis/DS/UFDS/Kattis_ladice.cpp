#include <bits/stdc++.h>

using namespace std;
#define ll long long int
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
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
    void decSize(int i){ setSize[findSet(i)]--;}// optional
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
    int a,b;
    cin >>a>>b;
    UnionFind ufds(b);
    vector<int>v;
    unordered_map<int,int> mymap;
    for(int i=0;i<a;++i)
    {
        int c,d;
        cin >>c>>d;
        --c;
        --d;
        ufds.unionSet(c,d);
        if (ufds.sizeOfSet(c)>0) {
            cout<<"LADICA\n";
            ufds.decSize(c);
        }
        else
            cout<<"SMECE\n";

    }


}

