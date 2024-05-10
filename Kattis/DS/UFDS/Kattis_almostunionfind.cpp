#include <bits/stdc++.h>

using namespace std;
#define ll long long int
typedef vector<int> vi;
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind { // OOP style
private:
    vi p, rank, setSize;
    vector<ll> sum;// vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(2*N, 0); for (int i = 0; i < N; ++i) {
            p[i] = N+i;
            p[N+i]=N+i;
        }
        rank.assign(2*N, 0); // optional speedup
        setSize.assign(2*N, 1); // optional feature
        numSets = N;
        sum.assign(2*N,0);
        for (int i = 0; i < N; ++i) {
            sum[i]=0;
            sum[N+i]=i+1;
        }// optional feature
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; } // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
    ll getSum(int i)
    {
        return (sum[findSet(i)]);
    }
    void move(int i, int j)
    {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        p[i]=y;
        setSize[x]--;
        setSize[y]++;
        sum[y]+=i+1;
        sum[x]-=i+1;
    }// optional
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items// keep x ’shorter’ than y
        p[x] = y;
        sum[y]+=sum[x];// set x under y// optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets; // a union reduces numSets
    }
};

int main()
{
    int n,m;
    string line;
    while(getline(cin,line)) {
        stringstream l(line);
        l >>n>>m;
        UnionFind ufds(n);
        for (int i = 0; i < m; ++i) {
            int a,b,c;
            getline(cin,line);
            stringstream l(line);
            l>>a;
            if (a!=3) {
                l >> b >> c;
            }
            else
                l>>b;
            if (a==1)
            {
                ufds.unionSet(b-1,c-1);
            }
            else if (a==2)
            {
                ufds.move(b-1,c-1);
            }
            else if (a==3)
            {
                cout<<ufds.sizeOfSet(b-1)<<" "<<ufds.getSum(b-1)<<endl;
            }
        }
    }



}

