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
    string line;
    getline(cin,line);
    int n;
    cin>>n;
    cin.ignore();

    string partie;
    string part;
    vector<vector<string>> v(n);
    f(i,0,n){
        getline(cin,line);
        stringstream s(line);
        while(s>>part){
            if (part[part.size()-1]!=','){
                if (partie.empty()){
                    partie=part;
                }
                else {partie+=" "+ part;}
            }
            else{
                part.pop_back();
                if (partie.empty()){
                    partie=part;
                }
                else {partie+=" "+ part;}
                v[i].pb(partie);
                partie="";
            }
        }
        v[i].pb(partie);
        partie="";
    }
    vector<pii> scores(n);
    f(i,0,n)
    {
        f(i1,0,n)
        {
            int score=0;
            f(j, 0, v[0].size()) {
                if(v[i][j]!=v[i1][j]){
                    score+=1;
                }
            }
            scores[i].first=max(scores[i].first,score);
            scores[i].second=i;
        }
    }
    sort(scores.begin(),scores.end());
    int min=scores[0].first;
    f(i,0,scores.size()){
        if (scores[i].first==min){
            f(j,0,v[scores[i].second].size()) {
                if(j){
                    cout<<", ";
                }
                cout<<v[scores[i].second][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}