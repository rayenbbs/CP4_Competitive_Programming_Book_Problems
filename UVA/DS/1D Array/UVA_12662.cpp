#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))
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
    int n; cin>>n;
    vector<string> v(n);
    f(i,0,n){
        cin>>v[i];
    }
    int q; cin>>q;
    while(q--){
        int indice; cin>>indice; --indice;
        int resultleft=INF; int resultright=INF;
        string sleft;   string sright;

        if (v[indice]=="?") {
            int temp = indice;
            while (temp > 0) {
                temp--;
                if (resultleft==INF){
                    resultleft=0;
                }
                resultleft++;
                if (v[temp] != "?") {
                    sleft = v[temp];
                    break;
                }
                if (temp==0){
                    resultleft=INF;
                }
            }
            temp = indice;
            while (temp < n-1) {
                temp++;
                if (resultright==INF){
                    resultright=0;
                }
                resultright++;
                if (v[temp] != "?") {
                    sright = v[temp];
                    break;
                }
                if (temp==n-1){
                    resultright=INF;
                }
            }
            if (resultright < resultleft) {
                f(i, 0, resultright) {
                    cout << "left of ";
                }
                cout << sright << '\n';
            } else if (resultright > resultleft) {
                f(i, 0, resultleft) {
                    cout << "right of ";
                }
                cout << sleft << '\n';
            } else {
                cout << "middle of " << sleft << " and " << sright << '\n';
            }
        }
        else{
            cout<<v[indice]<<'\n';
        }

    }

    return 0;
}

