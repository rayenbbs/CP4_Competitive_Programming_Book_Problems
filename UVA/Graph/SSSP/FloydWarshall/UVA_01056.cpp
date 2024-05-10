#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set


#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


#define MOD 998244353
#define PI 3.1415926535897932384626433832795
#define INF 1e9
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    int resultcount=1;
    cin >>V>>E;
    while (V!=0 ||E!=0) {
        cout<<"Network "<<resultcount++<<": ";
        umap<string, int> mymap;
        umap<int, string> revmap;
        uset<string> myset;
        int count = 0;
        vii AM(V, vi(V, INF));
        f(i, 0, E) {
            string a, b;
            cin >> a >> b;
            if (myset.find(a) == myset.end()) {
                myset.insert(a);
                mymap[a] = count;
                count++;
            }
            if (myset.find(b) == myset.end()) {
                myset.insert(b);
                mymap[b] = count;
                count++;
            }
            AM[mymap[a]][mymap[b]] = 1;
            AM[mymap[b]][mymap[a]] = 1;
        }
        f(i, 0, V) {
            AM[i][i] = 0;
        }
        // inside int main()
// precondition: AM[i][j] contains the weight of edge (i, j)
// or INF (1B) if there is no such edge, use memset(AM, 63, sizeof AM)
// Adjacency Matrix AM is a 32-bit signed integer array
        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);

        int result = -1;
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j) {
                result = max(result, AM[i][j]);
            }
        if (result == INF) {
            cout << "DISCONNECTED\n";
        } else cout << result << endl;
        cout<<endl;
        cin >>V>>E;
    }

    return 0;

}