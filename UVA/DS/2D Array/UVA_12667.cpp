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
    int n,t,m;
    cin>>n>>t>>m;
    vii ind(n,vi(t));
    map<char,pair<int,int>> mymap;
    f(i,0,m){
        int t,id;
        char problem;
        string verdict;
        cin>>t>>id>>problem>>verdict;
        if (verdict=="Yes"){
            if (!ind[problem-'A'][id-1]) {
                ind[problem-'A'][id-1]=1;
                mymap[problem] = {t, id};
            }
        }
    }
    f(i,0,n){
        char target='A'+i;
        if (mymap.find(target)==mymap.end()){
            cout<<target<<" - -\n";
        }
        else{
            cout<<target<<" "<<mymap[target].first<<" "<<mymap[target].second<<"\n";
        }
    }

    return 0;
}

