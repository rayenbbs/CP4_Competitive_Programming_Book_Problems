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
    string q;
    cin >>q;
    string min="zzzzzzzzzzzz";
    f(a,1,q.size()+1){
        f(b,a,q.size()+1){
            if (b==a || b==q.size()){
                continue;
            }
            string a1;
            string a2;
            string a3;
            f(i,0,a){
                a1.pb(q[i]);
            }
            f(i,a,b){
                a2.pb(q[i]);
            }
            f(i,b,q.size()){
                a3.pb(q[i]);
            }
            reverse(a1.begin(),a1.end());
            reverse(a2.begin(),a2.end());
            reverse(a3.begin(),a3.end());
            string inter="";
            inter.append(a1);
            inter.append(a2);
            inter.append(a3);
            if (inter<min){
                min=inter;
            }

        }
    }
    cout<<min<<endl;



}