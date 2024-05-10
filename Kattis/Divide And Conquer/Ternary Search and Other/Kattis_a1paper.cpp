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

vi v;
int n;


double solve(int indice,int size){
    if (indice==n-2 && v[indice]<size){
        return INF;
    }
    else if(indice==n-1){
        return 0;
    }
    else {
        if (v[indice]>=size){
            return ((double)size/2)*pow(2,-(0.75+(double)indice*0.5));
        }
        else{
            return (solve(indice+1,2*(size-v[indice]))+((double)size/2)*pow(2,-(0.75+(double)indice*0.5)));
        }

    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    v.assign(n,0);
    f(i,0,n-1){
        cin>>v[i];
    }
    double result=solve(0,2);
    if (result>INF-1){
        printf("impossible\n");
    }
    else printf("%lf\n",result);
}