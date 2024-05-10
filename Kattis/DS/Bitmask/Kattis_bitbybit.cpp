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
    int n;
    cin >>n;
    while(n!=0){
        vector<char> bit(32,'?');
        f(i,0,n){
            string op;
            int indice1,indice2;

            cin >>op;
            if (op=="SET"){
                cin >>indice1;
                bit[indice1]='1';
            }
            else if (op=="CLEAR"){
                cin >>indice1;
                bit[indice1]='0';
            }
            else if (op=="AND"){

                cin>>indice1>>indice2;
                if (bit[indice1]=='0' || bit[indice2]=='0'){
                    bit[indice1]='0';
                }
                else if (bit[indice1]=='?' || bit[indice2]=='?'){
                    bit[indice1]='?';
                }

                else {
                    bit[indice1]='1';
                }
            }
            else if (op=="OR"){
                cin>>indice1>>indice2;
                if (bit[indice1]=='1' || bit[indice2]=='1')
                    bit[indice1]='1';
                else if (bit[indice1]=='?' || bit[indice2]=='?'){
                    bit[indice1]='?';
                }
                else
                    bit[indice1]='0';

            }
        }
        reverse(bit.begin(),bit.end());
        f(i,0,32){
            cout<<bit[i];
        }
        cout<<endl;
        cin >>n;
    }
    return 0;

}