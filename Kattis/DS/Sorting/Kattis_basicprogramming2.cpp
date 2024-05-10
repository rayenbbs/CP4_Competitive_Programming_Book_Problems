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

    int n,t;
    cin>>n>>t;
    vi v(n);
    f(i,0,n){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if (t==1){
        int answer=false;
        f(i,0,n){
            if (*lower_bound(v.begin(),v.end(),7777-v[i])== 7777-v[i])
                answer=true;
        }
        if(answer){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    if(t==2){
        bool duplicate=false;
        f(i,1,n){
            if (v[i]==v[i-1]){
                duplicate=true;
            }
        }
        if(duplicate){
            cout<<"Contains duplicate\n";
        }
        else cout<<"Unique\n";
    }
    if(t==3){
        int prev=v[0];
        int count=0;
        bool found=false;
        f(i,0,n){
            if (v[i]==prev){
                count++;
                if (count>n/2){
                    cout<<prev<<'\n';
                    found=true;
                    break;
                }
            }
            else{
                count=1;
                prev=v[i];
            }
        }
        if(!found){
            cout<<"-1\n";
        }
    }
    if(t==4){
        if(n%2!=0){
            cout<<v[n/2]<<'\n';
        }
        else if(n%2==0){
            cout<<v[n/2-1]<<" "<<v[n/2]<<'\n';
        }
    }
    if(t==5){
        int ind= lower_bound(v.begin(),v.end(),100)-v.begin();
        int first=1;
        f(i,ind,n){
            if (v[i]<=999){
                if (first){
                    first=0;
                }
                else cout<<" ";
                cout<<v[i];
            }
        }
        cout<<'\n';
    }



    return 0;
}