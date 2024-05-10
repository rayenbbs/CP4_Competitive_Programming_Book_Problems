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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<pii> intervals(n);
    f(i,0,n){
        int a,b;
        cin>>a>>b;
        intervals[i]={b,a};
    }
    sort(intervals.begin(),intervals.end());
    int count=0;
    multiset<int> myset;
    f(i,0,k){
        myset.insert(0);
    }
    f(i,0,n){
        auto it=myset.lower_bound(intervals[i].second);
        if (it==myset.begin()){
            continue;
        }
        else{
            myset.erase(prev(it));
            myset.insert(intervals[i].first);
            ++count;
        }
    }
    cout<<count<<'\n';

}