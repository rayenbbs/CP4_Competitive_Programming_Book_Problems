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

struct CustomCompare {
    bool operator()( pair<char, int>& a,  pair<char, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return b.second < a.second;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int d,n;
    cin>>d>>n;
    while(d!=0 || n!=0){
        int resultsize=d-n;
        vector<char> vc(d);
        priority_queue<pair<char,int>,vector<pair<char,int>>,CustomCompare> q1;
        priority_queue<pair<char,int>,vector<pair<char,int>>,CustomCompare> q2;

        f(i,0,d){
            cin>>vc[i];
            q1.emplace(vc[i],i);
        }
        int indice=0;
        vector<char> result;
        while (n>0 && indice<d && !q1.empty()){
            pair<char,int> top=q1.top(); q1.pop();
            if (top.second>=indice){
                if( top.second-indice<=n) {
                    n -= top.second - indice;
                    indice = top.second + 1;
                    result.pb(top.first);
                    while(!q2.empty()){
                        top=q2.top(); q2.pop();
                        q1.push(top);
                    }
                }
                else{
                    q2.push(top);
                }
            }
        }
        f(i,0,min(resultsize,(int)result.size())){
            cout<<result[i];
        }
        if (result.size()<resultsize) {
            f(i, indice, d) {
                cout << vc[i];
            }
        }
        cout<<'\n';
        cin>>d>>n;
    }
}