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


int target;
int nb;
vi used;
vi v;
int n;

int backtrack(int sum,int start,int nombre,int index){
    if (sum==target){
        if (nombre+1==nb)
            return 1;
        return(backtrack(0,1,nombre+1,0));
    }
    else if (start==1){
        int indice;
        for(indice=0;used[indice] && indice<n;++indice);
        used[indice]=1;
        if(backtrack(v[indice],0,nombre,indice))
            return 1;
        used[indice]=0;
    }
    else {
        f(i,index+1,n)
        {
            if (!used[i] && sum+v[i]<=target)
            {
                used[i]=1;
                if (backtrack(sum+v[i],0,nombre,i))
                    return 1;
                used[i]=0;
                if (sum+v[i]==target)
                    return 0;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    while(n!=0){
        v.assign(n,0);
        int sum=0;
        f(i,0,n){
            cin >>v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        bool test=false;
        f(i,v[0],sum/2+2){
            if (sum%i==0 && i){
                used.assign(n,0);
                target=i;
                nb=sum/i;
                if(backtrack(0,1,0,0)){
                    cout<<target<<'\n';
                    test=true;
                    break;
                }
            }
        }
        if (!test){
            cout<<sum<<'\n';
        }
        cin >>n;
    }
}


