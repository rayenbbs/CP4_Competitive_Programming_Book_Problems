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

bool solution(int indice,vi &v,int sum,int target)
{
    if (indice==v.size()){
        return (sum==target);
    }
    else{
        return ((solution(indice+1,v,sum+v[indice],target)) || (solution(indice+1,v,sum-v[indice],target)) || (solution(indice+1,v,sum*v[indice],target)));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,d,e;
    cin >>a>>b>>c>>d>>e;
    vi v;
    while( a!=0 || b!=0  || c!=0 || d!=0 ||e!=0){
        v={a,b,c,d,e};
        sort(v.begin(),v.end());
        bool test=true;
        do{
            if(solution(1,v,v[0],23)){
                cout<<"Possible\n";
                test=false;
                break;
            }
            else continue;
        }while(next_permutation(v.begin(),v.end()));
        if (test)
            cout<<"Impossible\n";
        cin >>a>>b>>c>>d>>e;
    }
}