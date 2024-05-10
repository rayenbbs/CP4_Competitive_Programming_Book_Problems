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


string to_lower(string& a){
    f(i,0,a.size()){
        a[i]=tolower(a[i]);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    int testcount=1;
    while(cin>>r>>c && r) {
        if(testcount>1){
            cout<<'\n';
        }
        testcount++;
        string a;
        vector<string> v(r);
        f(i,0,r){
            cin>>a;
            v[i]=a;
        }
        vector<string> truestring(c);
        f(i,0,c) {
            string test;
            f(j, 0, r) {
                test.push_back(v[j][i]);
            }
            truestring[i]=test;
        }
        sort(truestring.begin(),truestring.end(),[](string a,string b){
            return to_lower(a)<to_lower(b);
        });
        f(i,0,r){
            string results;
            f(j,0,c){
                results.push_back(truestring[j][i]);
            }
            v[i]=results;
        }
        f(i,0,r){
            cout<<v[i]<<'\n';
        }
    }


    return 0;
}