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
    ll t;
    cin>>t;
    ll testcount=1;
    while(t--){
        ll n,h,ta,td;
        cin>>n>>h>>ta>>td;
        vector<ll> heights(n);
        f(i,0,n){
            cin>>heights[i];
        }
        ll result=0;
        if (2*ta<=td){
            result+=n*ta;
        }
        else{
            sort(heights.begin(),heights.end());
            ll l=0,r=n-1;
            while(l<r){
                if (heights[l]+heights[r]<h){
                    result+=td;
                    n-=2;
                    l++;
                    r--;
                }
                else{
                    r--;
                }
            }
            result+=n*ta;
        }
        cout<<"Case "<<testcount++<<": "<<result<<'\n';

    }

    return 0;
}