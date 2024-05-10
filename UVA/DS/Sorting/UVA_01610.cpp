#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


#define PI 3.1415926535897932384626433832795

#define LSOne(S) ((S) & -(S))




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    while(cin>>n && n){
        vector<string> v(n);
        f(i,0,n){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        string small;string big;
        small=v[(n>>1)-1]; big=v[n>>1];
        int length=min(small.size(),big.size());
        string result;
        f(i,0,length){
            if (small[i]<big[i]){
                if (small.size()-1==i){
                    result.pb(small[i]);
                }
                else {
                    result.pb(small[i] + 1);
                }
                break;
            }
            else if (small[i]==big[i]){
                result.pb(small[i]);
            }
        }
        if(result==big){
            result[length-1]-=1;
            f(i,length,small.size()){
                if (small[i]!='Z' && i!=small.size()-1) {
                    result.pb(small[i] + 1);
                    break;
                }
                else{
                    result.pb(small[i]);
                }
            }
        }
        cout<<result<<'\n';
    }
    return 0;
}
