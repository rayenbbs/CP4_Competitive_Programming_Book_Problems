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
    string line; getline(cin,line);
    int attributes=0;
    string temp;
    umap<string,int> mymap;
    stringstream s(line); while(s>>temp){
        mymap[temp]=attributes;
        attributes++;
    }
    int n; cin>>n;
    vector<vector<string>> v(n,vector<string>(attributes));
    vi order(n); f(i,0,n) order[i]=i;
    f(i,0,n){
        f(j,0,attributes){
            cin>>v[i][j];
        }
    }
    int q; cin>>q;
    while(q--){
        string criteria; cin>>criteria;
        stable_sort(order.begin(),order.end(),[&criteria, &v , &mymap](int a,int b){
            return (v[a][mymap[criteria]]<v[b][mymap[criteria]]);
        });
        cout<<line<<'\n';
        f(i,0,n){
            f(j,0,attributes){
                if(j){
                    cout<<" ";
                }
                cout<<v[order[i]][j];
            }
            cout<<'\n';
        }
        if(q){
            cout<<'\n';
        }
    }

    return 0;
}