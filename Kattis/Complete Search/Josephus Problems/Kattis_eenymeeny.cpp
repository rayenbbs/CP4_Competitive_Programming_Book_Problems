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
    string line;
    getline(cin,line);
    stringstream ss (line);
    string word;
    int count=0;
    while(ss>>word){
        ++count;
    }
    int n;
    cin >>n;
    vector<string> v(n);
    f(i,0,n){
        cin>>v[i];
    }
    vi v1(n,0);
    int index=0;
    vi t1;
    vi t2;
    f(i,0,n){
        f(j,0,count-1){
            while (v1[index]==1){
                ++index;
                index%=n;
            }
            index++;
            index%=n;
        }
        while (v1[index]==1){
            ++index;
            index%=n;
        }
        v1[index]=1;
        if (i%2){
            t2.pb(index);
        }
        else t1.pb(index);
    }
    cout<<t1.size()<<'\n';
    f(i,0,t1.size()){
        cout<<v[t1[i]]<<'\n';
    }
    cout<<t2.size()<<'\n';
    f(i,0,t2.size()){
        cout<<v[t2[i]]<<'\n';
    }
}