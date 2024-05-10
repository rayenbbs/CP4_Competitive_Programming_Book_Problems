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
    vii AM(26,vi(26,0));
    int m,n;
    cin >>m>>n;
    f(i,0,m){
        char a,b;
        cin >>a>>b;
        AM[a-'a'][b-'a']=1;
    }
    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                AM[i][j] |= (AM[i][k] & AM[k][j]);

    f(i,0,n){
        string a,b;
        cin >>a>>b;
        if (a.size()!=b.size()){
            cout<<"no"<<endl;
        }

        else{
            bool test=true;
            f(j,0,a.size()){
                if (!AM[a[j]-'a'][b[j]-'a'] && a[j]!=b[j]){
                    test=false;
                }
            }
            if (!test){
                cout<<"no"<<endl;
            }
            else cout<<"yes"<<endl;
        }
    }
    return 0;

}