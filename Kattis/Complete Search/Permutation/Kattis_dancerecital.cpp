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
    int n;
    cin>>n;
    vector<string> v(n);
    f(i,0,n){
        string inter;
        cin >>inter;
        v[i]=inter;
    }
    vii precalccount(n,vi(n));
    int count;
    uset<char> myset(2*n);
    f(i,0,v.size()){
        f(j,i+1,v.size()){
            count=0;
            string s1=v[i];
            string s2=v[j];
            if (s2!=s1){
                myset.clear();
                f(k,0,s2.size()){
                    myset.insert(s2[k]);
                }
                f(k,0,s1.size()){
                    if (myset.find(s1[k])!=myset.end()){
                        ++count;
                    }
                }
            }
            else
                count=s1.size();
            precalccount[i][j]=count;
            precalccount[j][i]=count;
        }
    }
    vi perm(n);
    f(i,0,n){
        perm[i]=i;
    }
    int best=INF;
    do{
        count=0;
        f(i,0,v.size()-1){
            count+=precalccount[perm[i]][perm[i+1]];
        }
        best=min(best,count);
    }while(next_permutation(perm.begin(),perm.end()));
    printf("%d\n",best);
}