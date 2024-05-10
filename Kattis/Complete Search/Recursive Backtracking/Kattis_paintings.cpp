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



void backtrack(vector<string> &v,int &count,vector<string> &solution,umap <string,uset<string>> &pairs,vector<string> &temp,vi& used){
    if (temp.size()==v.size()){
        if (solution.empty()){
            solution.assign(temp.begin(),temp.end());
        }
        ++count;
    }
    else{
        f(i,0,v.size()){
            if (temp.empty()){
                temp.pb(v[i]);
                used[i]=1;
                backtrack(v,count,solution,pairs,temp,used);
                temp.pop_back();
                used[i]=0;
            }
            else if (!used[i] && pairs[temp.back()].find(v[i])==pairs[temp.back()].end()){
                temp.pb(v[i]);
                used[i]=1;
                backtrack(v,count,solution,pairs,temp,used);
                temp.pop_back();
                used[i]=0;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        vector<string> v(n);
        f(i,0,n){
            cin >>v[i];
        }
        vector<string> solution;
        int m;
        cin >>m;
        umap <string,uset<string>> mymap;
        f(i,0,m){
            string a,b;
            cin >>a>>b;
            mymap[a].insert(b);
            mymap[b].insert(a);
        }
        int count=0;
        int indice=0;
        vector<string> temp;
        vi used(n,0);
        backtrack(v,count,solution,mymap,temp,used);
        cout<<count<<"\n";
        f(i,0,solution.size()){
            if (i!=0){
                cout<<" ";
            }
            cout<<solution[i];
        }
        cout<<'\n';
    }
}


