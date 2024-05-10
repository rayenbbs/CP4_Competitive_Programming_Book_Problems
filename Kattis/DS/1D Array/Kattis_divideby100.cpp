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
    string n,m;
    cin>>n>>m;
    int count0=0;
    deque<char> result;
    f(i,0,m.size()){
        if (m[i]=='0'){
            count0++;
        }
    }
    int trailing=true;
    for(int i=n.size()-1;i>=0;i--){
        if (trailing && n[i]=='0' && count0>0){
            count0--;
        }
        else if (count0>0){
            trailing=false;
            count0--;
            result.push_front(n[i]);
            if (count0==0){
                count0--;
                result.push_front('.');
            }
        }
        else{
            result.push_front(n[i]);
        }
    }
    if (count0>0) {
        while (count0 > 0) {
            result.push_front('0');
            count0--;
        }
        result.push_front('.');
    }
    if (result[0]=='.'){
        result.push_front('0');
    }
    f(i,0,result.size()){
        cout<<result[i];
    }
    cout<<'\n';


    return 0;
}