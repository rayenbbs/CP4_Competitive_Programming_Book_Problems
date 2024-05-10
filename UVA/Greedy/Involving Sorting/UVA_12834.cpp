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
    int t;
    cin>>t;
    int testcount=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        vi v1(n);
        vi v2(n);
        f(i,0,n){
            cin>>v1[i];
        }
        f(i,0,n){
            cin>>v2[i];
        }
        vi diff(n);
        f(i,0,n){
            diff[i]=v1[i]-v2[i];
        }
        sort(diff.begin(),diff.end());
        ll result=0;
        f(i,0,n-k){
            result+=-diff[i];
        }
        f(i,n-k,n){
            if (diff[i]<0){
                result+=-diff[i];
            }
        }
        if (result>0){
            cout<<"Case "<<testcount++<<": "<<result<<'\n';
        }
        else cout<<"Case "<<testcount++<<": No Profit\n";
    }




    return 0;

}