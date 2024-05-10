#include <bits/stdc++.h>
using namespace std;

template<typename T>
T mmax(T t) {
    return t;
}

template<typename T, typename... Args>
T mmax(T t, Args... args) {
    return std::max(t, mmax(args...));
}

#define uint unsigned int
#define ll long long
#define ull unsigned long long
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define LSOne(S) ((S) & -(S))
#define INF 1e18



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    while(cin>>t && t) {
        vector<pair<int,int>> v(t);
        f(i,0,t){
            int l,w,h; cin>>l>>w>>h;
            v[i]={h,l*w*h};
        }
        sort(v.begin(),v.end());
        cout<<v[t-1].second<<'\n';
    }

}