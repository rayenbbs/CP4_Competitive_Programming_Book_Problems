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
    while(getline(cin ,line)){
        vi v;
        stringstream ss(line);
        int a;
        int maxint=-1;
        while(ss>>a){
            v.push_back(a);
            maxint=max(maxint,a);
        }
        vi result(maxint,0);
        f(i,0,v.size()){
            f(j,i+1,v.size()){
                result[abs(v[i]-v[j])-1]++;
            }
        }
        vi missing;
        bool ruler=true;
        f(i,0,maxint){
            if( result[i]>1){
                ruler=false;
                break;
            }
            else if(result[i]==0) {
                missing.push_back(i+1);
            }
        }
        if(!ruler){
            cout<<"not a ruler\n";
        }
        else{
            if (missing.empty()){
                cout<<"perfect\n";
            }
            else{
                cout<<"missing";
                f(i,0,missing.size()){
                    cout<<" "<<missing[i];
                }
                cout<<'\n';
            }
        }
    }
}