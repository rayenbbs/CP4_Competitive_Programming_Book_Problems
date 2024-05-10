#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vi>
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


#define MOD 1000000007
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
    int n;
    int c;
    cin >>n>>c;
    while (n!=0 || c!=0) {
        vi v;
        f(i, 0, n) {
            v.pb(i);
        }
        vector<pair<int, pair<int, int>>> vp;
        f(i, 0, c) {
            int a, b, d;
            cin >> a >> b >> d;
            vp.pb({d, {a, b}});
        }
        int count = 0;

        do {
            bool test = true;
            f(i, 0, c) {
                pair<int, pair<int, int>> target;
                target = vp[i];
                int indice1;
                int indice2;
                f(j, 0, n) {
                    if (v[j] == target.second.first) {
                        indice1 = j;
                    }
                    if (v[j] == target.second.second) {
                        indice2 = j;
                    }
                }
                int dist = abs(indice1 - indice2);
                if ((target.first) > 0) {
                    if (dist > target.first) {
                        test = false;
                    }
                }
                else {
                    if (dist < -(target.first)) {
                        test = false;
                    }
                }
            }
            if (test)
                ++count;
        } while (next_permutation(v.begin(), v.end()));
        cout<<count<<endl;
        cin >>n>>c;
    }
}