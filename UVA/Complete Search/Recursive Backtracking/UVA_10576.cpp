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



int n,k;
int t;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >>n>>k){
        vector<vector<ll>> test(13,vector<ll>());
        f(i,0,13){
            f(j,0,i){
                test[i].pb(n);
            }
            f(j,i,12){
                test[i].pb(-k);
            }
        }
        ll best=-1;
        f(i,0,13){
            ll sum2=0;
            f(m,0,12){
                sum2+=test[i][m];
            }
            if (sum2>=0) {
                sort(test[i].begin(),test[i].end());
                do {
                    bool temp1 = true;
                    f(j, 0, 8) {
                        ll sum = 0;
                        f(m, 0, 5) {
                            sum += test[i][j + m];
                        }
                        if (sum > 0) {
                            temp1 = false;
                            break;
                        }
                    }
                    if (!temp1) {
                        continue;
                    } else {
                        if (sum2 > 0) {
                            best = max(best, sum2);
                        }
                    }
                } while (next_permutation(test[i].begin(), test[i].end()));
            }
        }
        if (best>=0)
            cout<<best<<'\n';
        else cout<<"Deficit\n";
    }
}


