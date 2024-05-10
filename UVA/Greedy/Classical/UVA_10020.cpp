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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >>t;
    int testcount=1;
    while(t--){
        if (testcount!=1){
            cout<<"\n";
        }
        int m;
        cin >>m;
        vector<pii> v;
        int l,r;
        cin>>l>>r;
        while(l!=0 || r!=0){
            v.eb(l,r);
            cin>>l>>r;
        }
        sort(v.begin(),v.end(),[](pii a,pii b){
            if (a.first!=b.first)
                return b.first>a.first;
            else return a.second>b.second;
        });
        int indice=0;
        int covered=0;
        vi results;
        bool test=true;
        while(covered<m && indice<v.size() && test){
            int indicecandidate=-1;
            int rightxcandidate=-INF;
            while (indice<v.size() && v[indice].first<=covered){
                if (rightxcandidate<v[indice].second && v[indice].second>covered){
                    indicecandidate=indice;
                    rightxcandidate=v[indice].second;
                }
                indice++;
            }
            if (indicecandidate!=-1){
                covered=rightxcandidate;
                results.pb(indicecandidate);
            }
            else {
                test=false;
            }
        }

        if(covered<m || !test){
            cout<<"0\n";
        }
        else {
            cout<<results.size()<<"\n";
            f(i,0,results.size()){
                if(i!=0){
                    cout<<" ";
                }
                cout<<v[results[i]].first<<" "<<v[results[i]].second;
            }
            cout<<"\n";
        }
        ++testcount;
    }
}