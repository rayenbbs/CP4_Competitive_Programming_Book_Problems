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

    int n,m;
    cin>>n>>m;
    vi vn(n);
    vi vm(m);
    f(i,0,n){
        cin>>vn[i];
    }
    f(i,0,m){
        cin>>vm[i];
    }
    sort(vm.begin(),vm.end());
    sort(vn.begin(),vn.end());
    int im=0;
    int in=0;
    int result=0;
    while(im<m && in<n){
        if (vm[im]>=vn[in]){
            im++;
            in++;
            ++result;
        }
        else{
            im++;
        }
    }
    cout<<result<<'\n';


    return 0;

}
