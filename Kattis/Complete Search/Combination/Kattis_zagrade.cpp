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
    string target;
    cin >>target;
    vi stack;
    vector<pair<int,int>> pairs;
    f(i,0,target.size()){
        if (target[i]=='('){
            stack.pb(i);
        }
        else if (target[i]==')'){
            pairs.eb(stack.back(),i);
            stack.pop_back();
        }
    }
    uset<int> set;
    string result;
    vector<string> results;
    f(i,0,1<<pairs.size()){
        result.clear();
        set.clear();
        f(j,0,pairs.size()){
            if (i & 1<<j){
                set.insert(pairs[j].first);
                set.insert(pairs[j].second);
            }
        }
        f(j,0,target.size()){
            if (set.find(j)==set.end()){
                result.pb(target[j]);
            }
        }
        results.pb(result);
    }
    sort(results.begin(),results.end());
    uset<string> resultsset;
    resultsset.insert(target);
    f(i,0,results.size()){
        if (resultsset.find(results[i])==resultsset.end()){
            resultsset.insert(results[i]);
            cout<<results[i]<<'\n';
        }
    }

}
