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

const double EPS=1e-6;

vector<int> v;

bool can(int target)
{
    f(i,0,v.size())
    {
        if (i==0)
        {
            if (v[i]==target)
            {
                target--;
            }
            else if (v[i]>target)
                return false;
        }
        else
        {
            if (v[i]-v[i-1]==target){
                target--;
            }
            else if (v[i]-v[i-1]>target)
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >>t;
    int testcount=1;
    while(t--){
        int n;
        cin>>n;
        v.assign(n,0);
        f(i,0,n){
            cin >>v[i];
        }
        int lo=0,high=10000000;
        while(lo<=high){
            int mid=(lo+high)/2;
            can(mid) ?  high=mid-1 : lo=mid+1;
        }
        if (can(lo) && can(high)){
            cout<<"Case "<<testcount++<<": "<<min(lo,high)<<'\n';
        }
        else if (can(lo)){
            cout<<"Case "<<testcount++<<": "<<lo<<'\n';
        }
        else if (can(high)){
            cout<<"Case "<<testcount++<<": "<<high<<'\n';
        }
    }

}


