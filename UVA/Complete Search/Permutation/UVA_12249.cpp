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
    int t;
    cin >>t;
    int testcount=1;
    while(t--){
        cout<<"Case "<<testcount++<<": ";
        int n;
        cin >>n;
        vector<string> vs(n);
        f(i,0,n){
            cin >>vs[i];
        }
        sort(vs.begin(),vs.end());
        int minf=INF;
        do{
            string resultstring=vs[0];
            f(i,1,vs.size()){
                string s1=vs[i];
                bool test=false;
                f(j,0,resultstring.size()){
                    int indice1=j;
                    int indice2=0;
                    while (resultstring[indice1]==s1[indice2] && indice1<resultstring.size()){
                        indice1++;
                        indice2++;
                    }
                    if (indice1==resultstring.size()){
                        test=true;
                        f(k,indice2,s1.size())
                            resultstring.pb(s1[k]);
                        break;
                    }
                }
                if (!test){
                    f(k,0,s1.size())
                        resultstring.pb(s1[k]);
                }
            }
            minf=min(minf,(int)resultstring.size());

        }while(next_permutation(vs.begin(),vs.end()));
        cout<<minf<<'\n';
    }
}