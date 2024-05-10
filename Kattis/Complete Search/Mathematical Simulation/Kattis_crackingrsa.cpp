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


void primeFactors(ll n,vector<ll> &factors) {
    while (n % 2 == 0) {
        factors.pb(2);
        n = n / 2;
    }
    for (int i = 3; i <= std::sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        factors.pb(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        ll n,e;
        cin >>n>>e;
        vector<ll> factors;
        primeFactors(n,factors);
        ll c= (factors[0]-1)*(factors[1]-1);
        ll coef=1;
        while(true){
            if ((1+coef*c)%e==0){
                cout<<(1+coef*c)/e<<'\n';
                break;
            }
            else
                ++coef;
        }
    }
}

