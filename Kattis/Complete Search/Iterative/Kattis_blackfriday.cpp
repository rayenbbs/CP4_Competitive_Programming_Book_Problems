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
    cin >>n;
    vi v (n,0);
    umap<int,pair<int,int>> mymap;
    f(i,0,n){
        cin>>v[i];
        ++mymap[v[i]].first;
        mymap[v[i]].second=i+1;
    }
    int result=-1;
    int resultcount=-1;
    for (auto i: mymap){
        if (i.second.first==1){
            if (resultcount<i.first){
                resultcount=i.first;
                result=i.second.second;
            }
        }
    }
    if (result!=-1)
        cout<<result<<endl;
    else cout<<"none\n";

}